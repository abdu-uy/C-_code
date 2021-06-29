#include<stdio.h>

namespace first
{
    int i=2;
}

namespace second{
    int i=5;

     namespace internal{

        struct p
        {
            int x;
            int y;
            /* data */
        };
        
    }

}


int main(){
    using  namespace first;
    using second::internal::p;

    printf("%d",first::i);
    printf("%d",second::i);

    p p;
    p.x=4;
    p.y=10;

    printf("   %d %d",p.x,p.y);


}