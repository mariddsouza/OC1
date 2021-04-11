#include "tp.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){

     int n=5;
     char rd_B[n], rs1_B[n], rs2_B[n];
     int rd_int, rs1_int, rs2_int;
     char rd[n], rs1[n], rs2[n], instrucao[n];
     char immediat[5], immediat_B[12];
     int immediat_int;
     setlocale(LC_ALL,"");
    
     FILE *arquivo;
     arquivo = fopen("arquivo.asm","r");
     if(arquivo == NULL){
         printf("Não se pode abrir o arquivo...");
     }
     FILE *saida;
     saida = fopen("saida.txt","w+");
    
    //"While" está percorrendo cada linha do arquivo de entrada.
     while (fscanf(arquivo,"%s %s %s %[^\n]s", instrucao, rd, rs1, rs2) != EOF){
           
           //Condição caso seja tipo R.
            if((strcmp(instrucao,"add") == 0) || (strcmp(instrucao,"sub") == 0) || (strcmp(instrucao,"and") == 0) || (strcmp(instrucao,"or") == 0) || (strcmp(instrucao,"xor") == 0) || (strcmp(instrucao,"sll") == 0) || (strcmp(instrucao,"srl") == 0)){
                
                Elimina_X(rd,rs1,rs2,n, instrucao);
                transforma_string_int(instrucao,&rd_int, rd, &rs1_int, rs1, &rs2_int, rs2);
                transformar_Binario(n, rd_int, rs1_int, rs2_int, rd_B, rs1_B, rs2_B, instrucao);
                imprime_comando_binario(saida, instrucao, rd_B, rs1_B, rs2_B, immediat_B);
                
            }

           //Condição caso seja tipo I.
            if((strcmp(instrucao, "addi") == 0) || (strcmp(instrucao, "andi") == 0) || (strcmp(instrucao, "ori") == 0)){
                
                strcpy(immediat, rs2);
                Elimina_X(rd,rs1,immediat,n, instrucao);
                transforma_string_int(instrucao, &rd_int, rd, &rs1_int, rs1, &immediat_int, immediat);
                transformar_Binario(n, rd_int, rs1_int, immediat_int, rd_B, rs1_B, immediat_B, instrucao);
                imprime_comando_binario(saida, instrucao, rd_B, rs1_B, rs2_B, immediat_B);
                 
            }
     }

    fclose(saida);
    fclose(arquivo);
    return 0;
}