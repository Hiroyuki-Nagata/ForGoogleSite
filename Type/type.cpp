#include <iostream>

#ifdef _WIN32
   #include <windows.h>
#else
   typedef char	          CHAR;
   typedef unsigned char  BYTE;
   typedef short          SHORT;
   typedef unsigned short WORD;
   typedef int            INT;
   typedef unsigned int   UINT;
   typedef long           LONG;
   typedef unsigned long  DWORD;
   typedef unsigned long  ULONG;
   typedef float	  FLOAT;
   typedef double	  DOUBLE;
#endif

int main()
{
     std::cout << "CHAR  " << sizeof(CHAR)  << std::endl; 
     std::cout << "BYTE  " << sizeof(BYTE)  << std::endl; 
     std::cout << "SHORT " << sizeof(SHORT) << std::endl; 
     std::cout << "WORD  " << sizeof(WORD)  << std::endl; 
     std::cout << "INT 	 " << sizeof(INT)   << std::endl; 
     std::cout << "UINT  " << sizeof(UINT)  << std::endl; 
     std::cout << "LONG  " << sizeof(LONG)  << std::endl; 
     std::cout << "DWORD " << sizeof(DWORD) << std::endl; 
     std::cout << "ULONG " << sizeof(ULONG) << std::endl; 
     std::cout << "FLOAT " << sizeof(FLOAT) << std::endl; 
     std::cout << "DOUBLE" << sizeof(DOUBLE)<< std::endl; 
}
