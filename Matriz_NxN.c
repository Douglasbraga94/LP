#include <stdlib.h>

int **alocaMemoria(int linha, int coluna);
int preencheMatriz(int linha, int coluna, int **matriz);
int **multiplicaMatriz(int linha1, int linha2, int coluna1, int coluna2, int **matriz1, int **matriz2, int **matriz3);
int **liberaMemoria(int linha, int **matriz);

//////////////////////////////////////* Função Principal */////////////////////////////////////////////////////////

int main (){
    int **matriz1,**matriz2,**matriz3;
    int linha1,linha2,coluna1,coluna2;


    linha1=linha2=coluna1=coluna2=100;


    /*Aloca-Preenche matrizes.*/
    matriz1 = alocaMemoria(linha1,coluna1);
    preencheMatriz(linha1,coluna1,matriz1);
    matriz2 = alocaMemoria(linha2,coluna2);
    preencheMatriz(linha2,coluna2,matriz2);
    matriz3 = alocaMemoria(linha1,coluna2);

    /*Multiplica Matrizes*/
    matriz3 = multiplicaMatriz(linha1,linha2,coluna1,coluna2,matriz1,matriz2,matriz3);


/*libera memória*/

matriz1 = liberaMemoria(linha1,matriz1);

matriz2 = liberaMemoria(linha2,matriz2);

matriz3 = liberaMemoria(linha1,matriz3);

return 0;

}


/*Alocação*/
int **alocaMemoria(int linha, int coluna){
    int **aux,i; /*Variavel auxiliar*/
    aux = (int **) malloc(linha*sizeof(int *));
    if(aux!=NULL){
        for (i=0;i<linha;i++){
            aux[i] = (int *) calloc(coluna,sizeof(int));
        if(aux[i]==NULL){
            printf("Memória Insuficiente.");
            exit(1);
        }
    }
}

    else{
        printf("Memória Insuficiente.");
        exit(1);
    }
return(aux);
}

/*Preenche matrizes*/
int preencheMatriz(int linha, int coluna, int **matriz){
    int i,j,n;
    srand(time(NULL));
    for (i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            matriz[i][j]=rand()%10;
        }
    printf("\n");
    }
}

/*Multiplica as duas matrizes*/
int **multiplicaMatriz(int linha1, int linha2, int coluna1, int coluna2, int **matriz1, int **matriz2, int **matriz3){
    int i,j,k; /*Variaveis auxiliares*/
    for (i = 0 ; i < linha1; i++ ){
        for (j = 0; j < coluna2; j++){
        matriz3[i][j] = 0;
        for (k = 0; k < linha2; k++){
            matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
        }
    }
}
return(matriz3);
}

/*Libera memória*/
int **liberaMemoria(int linha, int **matriz){
    int i; /*Variavel auxiliar*/
    if(matriz==NULL){
        return(NULL);
    }

    for (i=0;i<linha;i++){
        free(matriz[i]);
    }
free(matriz);
return(NULL);
}
