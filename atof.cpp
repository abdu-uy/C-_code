#include <stdio.h>
#include <stdlib.h>
int main(){
   const char *a = "-100.23",
         *b = "200e-2",
         *c = "341",
         *d = "100.34cyuyan",
         *e = "cyuyan",
         *f = "3456.34";

    printf("a = %.2f\n", atof(a));
    printf("b = %.2f\n", atof(b));
    printf("c = %.2f\n", atof(c));
    printf("d = %.2f\n", atof(d));
    printf("e = %.2f\n", atof(e));
    printf("f = %.2f\n", atof(f));

    
    return 0;
}