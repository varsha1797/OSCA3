#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
   int num,a;                         // 1 Complexity
   printf("Enter a number");            // 1 Complexity
   scanf("%d",&num);                  // 1 Complexity
   if(num > 0){                       // 1 Complexity
   if(fork()==0){                        // 1 Complexity
                           
       for( a = number; a>0; a = a/2 )   // log n Complexity
       {
           printf("%d \t",a);            // log n Complexity
       }
       
       printf("Child Process");          // 1 Complexity
       exit(0);                          // 1 Complexity
       
   }else{
       wait();                            // 1 Complexity
       printf("Parent Process");          // 1 Complexity
   }
   }
   return 0;                             // 1 Complexity
}
