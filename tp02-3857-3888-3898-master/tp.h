#ifndef __TP__
#define __TP__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void Elimina_X(char *rd, char *rs1, char *rs2, int n, char *instrucao);

void transforma_string_int(char *instrucao, int *rd_int, char *rd, int *rs1_int, char *rs1, int *rs2_int, char *rs2 );

void transformar_Binario(int tam, int rd_int, int rs1_int, int rs2_int, char *rd_B, char *rs1_B, char *rs2_B, char *instrucao);

void imprime_comando_binario(FILE *saida, char *instrucao, char *rd, char *rs1, char *rs2, char *immediate);

#endif 