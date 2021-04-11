#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tp.h"

//Função que elimina o x da string. Exemplo: x9, -> Aplicando a função "Elimina_x" ficaria "9,".
void Elimina_X(char *rd, char *rs1, char *rs2, int n, char *instrucao){
       for (int i=0;i<n;i++){

                    //Condição do tipo R.     
                   if((!(strcmp(instrucao, "addi") == 0)) && (!(strcmp(instrucao, "andi") == 0)) && (!(strcmp(instrucao, "ori") == 0))){
                        rd[i] = rd[i+1];
                        rs1[i] = rs1[i+1];
                        rs2[i] = rs2[i+1];
                        //O x da string passaria a não ser mais o primeiro termo da string após essa operação.
                   }

                    //Condição do tipo I.     
                   if((strcmp(instrucao,"addi") == 0) || (strcmp(instrucao,"andi") == 0) || (strcmp(instrucao,"ori") == 0)){
                        rd[i] = rd[i+1];
                        rs1[i] = rs1[i+1];
                        //Mesma operação, porém sem rs2, pois estamos tratando de um imediato no tipo I.                       
                   }  
        }
}

//Função para tranformar todas strings em números inteiros.
void transforma_string_int(char *instrucao, int *rd_int, char *rd, int *rs1_int, char *rs1, int *rs2_int, char *rs2 ){
    char *string1;

  //Condição tipo R.  
  if((!(strcmp(instrucao, "addi") == 0)) && (!(strcmp(instrucao, "andi") == 0)) && (!(strcmp(instrucao, "ori") == 0))){
    *rd_int = strtoul(rd, &string1, 0);
    *rs1_int = strtoul(rs1, &string1, 0);
    *rs2_int = strtoul(rs2, &string1, 0); 
    //Operação que transforma em int e transfere os números inteiros, antes strings, dos registradores nas variáveis que estão recebendo.
    //Haverá uma parte ainda em string que será ignorada através de armazenamento dela em "string1".    
  }

  //Condição tipo I.  
  if((strcmp(instrucao,"addi") == 0) || (strcmp(instrucao,"andi") == 0) || (strcmp(instrucao,"ori") == 0)){
    *rd_int = strtoul(rd, &string1, 0);
    *rs1_int = strtoul(rs1, &string1, 0);
    *rs2_int = atoi(rs2);
    //A função "atoi" transforma o imediato de string para inteiro.
  }

}

//Função que transforma os decimais em binários.
void transformar_Binario(int tam, int rd_int, int rs1_int, int rs2_int, char *rd_B, char *rs1_B, char *rs2_B, char *instrucao){
    int i;
    int tam2 = 12;
    int aux = 0;

     //O "for" está dando o valor aos bits da esquerda para a direita, o "tam-1" é o tamnho 5 bits do registrador binário.   
     for( i = tam - 1; i>=0 ;i--){ 

        //Condição para o "rd".  
          if(rd_int%2 == 0){
            rd_B[i] = '0';                 
            rd_int = rd_int/2;
            //Condição caso o registrador seja par, a posição "i" do registrador binário será 0.
         }
         else{
            rd_B[i] = '1';
            rd_int = rd_int/2;
            //Caso seja ímpar, será 1.
        }
      } 
      
      for( i = tam - 1; i>=0 ;i--){

        //Condição para o "rs1".  
        if(rs1_int%2==0){
            rs1_B[i] = '0';
            rs1_int = rs1_int/2;
        }
        else{
            rs1_B[i] = '1';
            rs1_int = rs1_int/2;
        }
      }

    //Condição caso a instrução seja do tipo R, ela terá um rs2.
      if((strcmp(instrucao,"add") == 0) || (strcmp(instrucao,"sub") == 0) || (strcmp(instrucao,"and") == 0) || (strcmp(instrucao,"or") == 0) || (strcmp(instrucao,"xor") == 0) || (strcmp(instrucao,"sll") == 0) || (strcmp(instrucao,"srl") == 0)){
     
       rs2_B[strlen(rs2_B)-1] = '\0';

      for( i = tam - 1; i>=0 ;i--){
        if(rs2_int%2 == 0){
            rs2_B[i] = '0';
            rs2_int = rs2_int/2;
        }
        else{
            rs2_B[i] = '1';
            rs2_int = rs2_int/2;
        }
      }
    }

    //Condição caso a instrução seja do tipo I, ela terá um imediato.
    if((strcmp(instrucao, "addi") == 0 ) || (strcmp(instrucao, "andi") == 0) || (strcmp(instrucao, "ori") == 0)){ 

        //Aplicando condição para o imediato positivo.
        //obs: A variável "rs2" nesse caso é o imediato.
        if (rs2_int >= 0){
        for(i=(tam2-1); i>=0; i--){
            if (rs2_int% 2 == 0 ) {
                rs2_B [i] = '0' ;
            }
            else {
                rs2_B [i] = '1' ;
            }
            rs2_int = rs2_int / 2 ;
        }
    }
    
     // Aplicando condição caso o imediato seja negativo.
     if (rs2_int < 0){
        for(i=(tam2-1); i>=0; i--){

            //A partir daqui, começamos a aplicar o complemento de 2. 
            //Primeiramente, aplica-se o complemento de 1.   
            if (rs2_int% 2 == 0 ) {
                rs2_B [i] = '1' ;
            }
            else {
                rs2_B [i] = '0' ;
            }
            rs2_int = rs2_int / 2 ;
        }

        //Somaremos 1 ao binário invertido pelo complemento de 1.
        for(i=(tam2-1); i>=0; i--){
            if (i == (tam2-1)){
                if (rs2_B [i] == '1'){
                    rs2_B [i] = '0';
                    aux = 1;
                }
                else{
                    rs2_B [i] = '1';
                    aux = 0;
                }
            }
            else{
                if (aux == 1){
                    if (rs2_B [i] == '1'){
                        rs2_B [i] = '0';
                        aux = 1;
                    }
                    else{
                        rs2_B [i] = '1';
                        aux = 0;
                    }
                }
                if (aux == 0){
                    if (rs2_B [i] == '1'){
                        rs2_B [i] = '1';
                        aux = 0;
                    }
                    else{
                        rs2_B [i] = '0';
                        aux = 0;
                    }
                }
            }
        }
      }
  }
}

//Print para comandos binários do tipo R e I
void imprime_comando_binario(FILE *saida, char *instrucao, char *rd, char *rs1, char *rs2, char *immediate){

    char funct7[8], funct3[4], opcode[8];
    if(strcmp(instrucao, "add") == 0 ){
     
       strcpy(funct7, "0000000");
              
       strcpy(funct3, "000");
      
       strcpy(opcode, "0110011");
       
       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
       
       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "sub") == 0 ){
        
       strcpy(funct7, "0100000");

       strcpy(funct3, "000");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    
       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "and") == 0 ){
        
       strcpy(funct7, "0000000");

       strcpy(funct3, "111");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    
       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "or") == 0 ){
        
       strcpy(funct7, "0000000");

       strcpy(funct3, "110");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
       
       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "xor") == 0 ){
        
       strcpy(funct7, "0000000");

       strcpy(funct3, "100");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "sll") == 0 ){
        
       strcpy(funct7, "0000000");

       strcpy(funct3, "001");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "srl") == 0 ){
        
       strcpy(funct7, "0000000");

       strcpy(funct3, "101");

       strcpy(opcode, "0110011");

       printf("%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s%s\n",funct7,rs2,rs1,funct3,rd,opcode);
    }

    if(strcmp(instrucao, "addi") == 0 ){

       strcpy(funct3, "000");

       strcpy(opcode, "0010011");

       printf("%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);

    }

    if(strcmp(instrucao, "andi") == 0 ){

       strcpy(funct3, "111");

       strcpy(opcode, "0010011");

       printf("%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);
    }
    
    if(strcmp(instrucao, "ori") == 0 ){

       strcpy(funct3, "110");

       strcpy(opcode, "0010011");

       printf("%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);

       fprintf(saida,"%s%s%s%s%s\n",immediate,rs1,funct3,rd,opcode);
    }
}