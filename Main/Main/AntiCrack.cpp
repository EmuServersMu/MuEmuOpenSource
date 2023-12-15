#include "stdafx.h"
#if(ANTI_CRACK_MAIN == 1)
#include "AntiCrack.h"

void MainProtection(){
	SystemOut1();
	SystemOut2();
	SystemOut3();
	CheckDbgPresentCloseHandle();
	Int2DCheck();
	IsDbgPresentPrefixCheck();
}

//will read if OllyDbg debugger is active
void SystemOut1(){
	HANDLE holly = FindWindow (TEXT ("OllyDbg"), NULL);
	if(holly){
	    system("@echo Off"); 
        system("shutdown -r -f -t 00"); 
	    __asm{
		     MOV EAX, 00000000;
		     CALL EAX;
	    } 
	}
}


//will read if the HxD debugger is active
void SystemOut2(){
	HANDLE hxd = FindWindow (TEXT ("HxD"), NULL);
	if(hxd){
	    system("@echo Off"); 
        system("shutdown -r -f -t 00"); 
	    __asm{
	    	MOV EAX, 00000000;
		    CALL EAX;
	    } 
	}
}

//will read if the ida pro debugger is active
void SystemOut3(){
	HANDLE ida = FindWindow (TEXT ("ida64"), NULL);
	if(ida){
	    system("@echo Off"); 
        system("shutdown -r -f -t 00"); 
	    __asm{
	    	MOV EAX, 00000000;
		    CALL EAX;
	    } 
	}
	HANDLE idaq = FindWindow (TEXT ("idaq"), NULL);
	if(idaq){
	    system("@echo Off"); 
        system("shutdown -r -f -t 00"); 
	    __asm{
	    	MOV EAX, 00000000;
		    CALL EAX;
	    } 
	}
}

// CheckCloseHandle will call CloseHandle on an invalid
// DWORD aligned value and if a debugger is running an exception
// will occur and the function will return true otherwise it'll
// return false
inline bool CheckDbgPresentCloseHandle(){
	HANDLE Handle = (HANDLE)0x8000;
	__try{
		CloseHandle(Handle);
	}
	__except(EXCEPTION_EXECUTE_HANDLER){
		return true;
	}	
	return false;
}

// The Int2DCheck function will check to see if a debugger
// is attached to the current process. It does this by setting up
// SEH and using the Int 2D instruction which will only cause an
// exception if there is no debugger. Also when used in OllyDBG
// it will skip a byte in the disassembly and will create
// some havoc.
inline bool Int2DCheck(){
	__try{
		__asm{
			int 0x2d
			xor eax, eax
			add eax, 2
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER){
		return false;
	}	
	return true;
}

inline bool IsDbgPresentPrefixCheck(){
	__try{
		__asm __emit 0xF3 // 0xF3 0x64 disassembles as PREFIX REP:
		__asm __emit 0x64
		__asm __emit 0xF1 // One byte INT 1
	}
	__except(EXCEPTION_EXECUTE_HANDLER){
		return false;
	}
	return true;
}

#endif