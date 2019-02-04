/* GNU tools to help develop C/C++ applications
 *
 * Some tools supported in GNU/Linux are gcc, g++, glibc, binutils etc
 * For Windows similar tools are provided by MINGW but limited to only 32-bit OS
 * MinGW generates code for the windows runtime in PE format, so Linux system calls cant be used with this 
 */

 /* Code:blocks comes with gcc v4.9.2 */

//Optionally Cygwin project also provides a complete UNIX-like environment in windows with GNU tools and 
//an abstraction layer for POSIX APIs. Any UNIX/Linux application can be ported on Cygwin

#include<stdio.h>
#define PI 22.0/7.0

int main()
{
 double area,r;
 area=PI*r*r;
 printf("area of circle=%lf\n",area);
 return 0;
}

//underlying phases of development? gcc/g++ undergo various phases like pre-processing,assembling, linking etc
//with the help of tools like cpp,as,ld,etc so gcc/g++ act like wrappers for these tools
//to see the phase, try these commands

//to see preprocessed output, use -E option of gcc whcih invokes cpp command internally. here you can see PI replaced by their 
//values. Comments are removed, macros are expanded and header file contents are included.   
