#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (10)

int main()
{
    const char* p1="adsadsadsa";
    char* p2=(char*)malloc(sizeof(char)*N);
    memcpy(p2,p1,N);
    printf("%s\n",p2);

    free(p2);
    p2 = NULL;

    system("pause");
    return 0;
}

