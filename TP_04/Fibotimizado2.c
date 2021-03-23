///////////////////////////////////////////////////
// Fibonacci Otimizado entrada com vetor 10.000///
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdio.h>

int fib(int n){                                         
      if (n == 1) return 1;                   
      else                                    
        if (n == 2) return 1;                 
        else return fib(n - 1) + fib(n - 2);  
}                                         
   
int main(void){

     int n;
     FILE *arquivo;
     arquivo = fopen("Entrada_DezMil.txt","r");

     while (!feof(arquivo)){
        fscanf(arquivo,"%d\n",&n);
     }

    getchar();

    fclose(arquivo);
    return 0;
 }