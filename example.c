// #include <sys/syscall.h> // includes SYS_write
#include <unistd.h>
#include <string.h>

int main(void)
{
    const char* str = "Hello, world!\n";
    size_t len = strlen(str);
    // write(STDOUT_FILENO, str, len);

#ifdef __linux__
    syscall(1, STDOUT_FILENO, str, len);
#elif __APPLE__
    syscall(4, STDOUT_FILENO, str, len);
#endif

    return 0;
}
