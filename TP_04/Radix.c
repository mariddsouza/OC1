/////////////////////////////////////////
// RadixSort entrada com vetor 1.000////
///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

void radixsort(int *vet, int n) {
	int i, exp = 1, m = 0, bucket[n], temp[n];

	for(i = 0; i < n; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}
		for(i = 0; i < n; i++) {
			vet[i] = temp[i];
		}
		exp *= 10;
	}
}

int main() {
	int n = 1000;
	int *vetor;
	FILE *arquivo;
    int i=0;
    arquivo = fopen("Entrada_Mil.txt","r");
	vetor = (int *)malloc(n*sizeof(int));
    while (!feof(arquivo)) {
      fscanf(arquivo,"%d\n", &vetor[i]);
      i++;
   }
	radixsort(vetor,n);
	
   getchar();

	fclose(arquivo);
	return(0);
}