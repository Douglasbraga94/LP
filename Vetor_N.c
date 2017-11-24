#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int preencher(int* p, int num);
int ElevaQuadrado(int* p, int num);
double CalculaSoma(int* p, int num);


int main(){
    int* p;
    int num, c;
    char ch;
    double soma;

    num=100;

    p=(int *)malloc(num*sizeof(int));
    if(!p){
        printf("\nErro na alocação de memoria.\n");
        system("pause");
        exit(0);
    }


    num=preencher(p, num);
    num=ElevaQuadrado(p, num);
    soma= CalculaSoma(p, num);

    printf("%lf\n", soma);

    free(p);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////q

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
