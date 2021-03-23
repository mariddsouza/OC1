/////////////////////////////////////////
// BubbleSort entrada com vetor 10.000//
///////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

void Bubble_sort(int *vetor, int n){
  
  int i, j, aux;
  for( i = 0; i < (n+1); i++){
        for(j = i + 1; j < (n+1); j++){
            if(vetor[i]>vetor[j]){ //verificando se a posição (n+1)<n. 
                aux = vetor[i];  //passando o valor de n+1 para aux.
                vetor[i] = vetor[j]; // a posicao (n+1) = n. 
                vetor[j] = aux; // n = n+1.
            }
        }
   }
}
 
int main(){
 
    int i=0, aux, n = 10000;
    int *vetor;
    int numero;
    FILE *arquivo;
    arquivo = fopen("Entrada_DezMil.txt","r");
    
    vetor = (int *)malloc(n*sizeof(int));
    while (!feof(arquivo)){
    
         fscanf(arquivo,"%d\n",&vetor[i]);
         i++;
    }
    Bubble_sort(vetor, n);

   getchar();
    free(vetor);
    fclose(arquivo);
    return 0;
 
}