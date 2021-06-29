#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 不可以声明为 char *str = "http://c.biancheng.net";
    char str[] = "http://c.biancheng.net";
    memset(str, '-', 7);
    puts(str);

    
    return EXIT_SUCCESS;
}