#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

int putc(unsigned char c); // send one character
int puts(unsigned char *str); // send sentence
int putxval(unsigned long value, int column); // send hex value

void* memset(void* b, int c, long len); //fill out with certain byte data
void* memcpy(void* dst, const void* src, long len); //copying memory
int memcmp(const void* b1, const void* b2, long len); //comparing memories
int strlen(const char* s); //return length of str
char* strcpy(char* dst, const char* src); //copying str
int strcmp(const char* s1, const char* s2); //comparing strs
int strncmp(const char* s1, const char* s2, int len); //strcmp with length unit

#endif
