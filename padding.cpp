#include <stdio.h>
 
// Alignment requirements
// (typical 32 bit machine)
 
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes
 
// structure A
typedef struct structa_tag
{
   char        c;
   short int   s;
} structa_t;
 
// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
 
// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;
 
// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;

typedef struct __attribute__((__packed__)) alihan
{
   __uint8_t a;
   __uint16_t b;
   __uint32_t c;
   __uint8_t d;
}ali;
 
int main()
{
   printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
   printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
   printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
   printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));
   printf("sizeof(ali) = %lu\n", sizeof(ali));

   printf("sizeof(int8) = %lu\n", sizeof(__uint8_t));

   printf("sizeof(int16) = %lu\n", sizeof(__uint16_t));

   printf("sizeof(int32) = %lu\n", sizeof(__uint32_t));

   printf("sizeof(int8) = %lu\n", sizeof(__uint8_t));

 
   return 0;
}