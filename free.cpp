#include <stdlib.h>
int main ()
{
    int * buffer1, * buffer2, * buffer3;
    buffer1 = (int*) malloc (100*sizeof(int));
  
    buffer3 = (int*) realloc (buffer1,500*sizeof(int));
    free (buffer1);
    free (buffer3);

  
    return 0;
}