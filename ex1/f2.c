#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int isprime(int n){
   if(n<2)
      return 0;
   for(int i=2;i*i<=n;i++){
      if(n%i==0){
         return 0;
      }
   }
   return 1;
}
int main(){
   int p2;
   int n;
   printf("enter no of elements");
   scanf("%d",&n);
   int arr[n];
   printf("enter the elements:");
   for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
   }
   p2=fork();
   if(p2==0){
      printf("prime numbers:");
      for(int i=0;i<n;i++){
         if(isprime(arr[i])){
               printf("%d",arr[i]);
         }
      }
   }
   else{
      wait(NULL);
   }
   return 0;
}
[24bcs053@mepcolinux ex1]$./ex2
enter no of elements6
enter the elements:1 4 3 2 7 8
