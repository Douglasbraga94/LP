#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int preencher(int* p, int num);
int ElevaQuadrado(int* p, int num);
double CalculaSoma(int* p, int num);


int main(void){
    int* p;
    int num=0, c;
    char ch;
    double soma, tempoexecucao;
    clock_t tempoinicial, tempofinal;

/*    printf("\nInforme o tamanho para o vetor: ");
      scanf("%d%c",&num,&ch);
      if(num <=0){
        printf("\nValor invalido!!!\n");
        system("pause");
        exit(0);
    }*/

    /*NUM FIXO PARA TESTAR O TEMPO DE EXECUÇÃO PELO PROPRIO WINDOWS, POIS NÃO ACHEI UMA FUNÇÃO QUE 
    PEGUE O TEMPO EM MILISSEGUNDOS*/
    num=1000;

    p=(int *)malloc(num*sizeof(int));
    if(!p){
        printf("\nErro na alocação de memoria.\n");
        system("pause");
        exit(0);
    }


    num=preencher(p, num);
    tempoinicial=clock();
    num=ElevaQuadrado(p, num);
    soma= CalculaSoma(p, num);
    tempofinal=clock();

    for(c=0;c<num;c++){
        printf("%d\n", p[c]);
    }
    //tempoexecucao=(tempofinal-tempoinicial)/CLOCKS_PER_SEC;
    printf("%lf\n", soma);
    //printf("%lf", ((double)(tempofinal-tempoinicial)/CLOCKS_PER_SEC));
    //system("pause");

    free(p);
    return 0;
}

int preencher(int* p, int num){
    int c;
    char ch;
    srand(time(NULL));
    for(c=0;c<num;c++){
        p[c]=rand() % 100;
    }
    return (c-1);
}

int ElevaQuadrado(int* p, int num){
    int c;
    for(c=0;c<num;c++){
        p[c]=p[c]*p[c];
    }
    return (c-1);
}

double CalculaSoma(int* p, int num){
    double soma=0;
    int c;
    for (c=0;c<num;c++) {
        soma = soma + p[c];
    }

    return (soma);
}
