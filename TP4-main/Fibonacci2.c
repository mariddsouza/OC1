/////////////////////////////////////////
// Fibonacci entrada com vetor 10.000///
///////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

int fib(int n){

  int i, fib1 = 1, fib2 = 1, soma;         
  for (i = 3; i <= n; i = i + 1){

    soma = fib1 + fib2;                    
    fib1 = fib2;                           
    fib2 = soma;  

  }                                        
     return fib2;                             
}                                          
   
   
 int main(void){
     int n;
     FILE *arquivo;
     arquivo = fopen("Entrada_DezMil.txt","r");

     while (!feof(arquivo))
     {
        fscanf(arquivo,"%d\n",&n);
     }

    getchar();

    fclose(arquivo);
    return 0; 

}