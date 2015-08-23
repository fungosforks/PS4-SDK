#include "module.h"

#include "libc.h"

void *(*malloc)(size_t size);
void *(*memset)(void *destination, int value, size_t num);
void *(*memcpy)(void *destination, const void *source, size_t num);
char *(*strcpy)(char *destination, const char *source);
size_t (*strlen)(const char *s);
int (*sprintf)(char *str, const char *format, ...);
int (*sscanf)(const char *str, const char *format, ...);
char *(*strchr)(const char *s, int c);
char *(*strrchr)(const char *s, int c);


void initLibc(void) {
	int libc;
	loadModule("libSceLibcInternal.sprx", &libc);
	
	RESOLVE(libc, malloc);
	RESOLVE(libc, memset);
	RESOLVE(libc, memcpy);
	RESOLVE(libc, strcpy);
	RESOLVE(libc, strlen);
	RESOLVE(libc, sprintf);
	RESOLVE(libc, sscanf);
	RESOLVE(libc, strchr);
	RESOLVE(libc, strrchr);
}
