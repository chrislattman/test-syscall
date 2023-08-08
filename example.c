// #include <sys/syscall.h> // includes SYS_write
#include <unistd.h>
#include <string.h>
// #include <stdio.h>

#if defined(__APPLE__)
    #ifndef _SYS_SYSCALL_H_
        #define SYS_write 4
    #endif
#elif defined(__linux__)
    #ifndef _SYSCALL_H
        #if defined(__amd64__)
            #define SYS_write 1
        #elif defined(__aarch64__)
            #define SYS_write 64
        #endif
    #endif
#endif

int main(void)
{
    const char* str = "Hello, world!\n";
    size_t len = strlen(str);
    // printf("%s", str);
    // write(STDOUT_FILENO, str, len);

    syscall(SYS_write, STDOUT_FILENO, str, len);

    return 0;
}
