#include <stdio.h>
#include <stdlib.h>
#define max_Size 35660
void soma(int casa, int numero[max_Size], int valorASomar);
void testaSoma();
void multiplica(int primeiroNumero[max_Size], int segundoNumero[max_Size], int numero[max_Size]);
void testaMultiplica();
int main(){
    printf("Digite um numero inteiro: ");
    int n;
    scanf("%d", &n);
    int * temp = (int*) calloc (max_Size, sizeof(int));
    int * temp2 = (int*) calloc (5, sizeof(int));
    int * result = (int*) calloc (max_Size, sizeof(int));
    result[0] = 1;
    temp2[0] = 1;
    for(int i = 0; i < n; i++){
        multiplica(result, temp2, temp);
        for(int j = 0; j < max_Size; j++){
            result[j] = temp[j];
            temp[j] = 0;
        }
        soma(0, temp2, 1);
    }
    int aux = 0;
    int aux2 = max_Size;
    while(aux == 0){
        if(result[aux2] != 0){
            aux = result[aux2];
            break;
        }
        // printf("%d %d", result[aux2], aux2);

        aux2--;
    }
    printf("Resultado: ");
    for(int i = aux2; i >= 0; i--){
        printf("%d", result[i]);
    }
    printf("\n");
    // testaSoma();
    // testaMultiplica();
    return 0;
}

void soma(int casa, int numero[max_Size], int valorASomar){
    if(numero[casa] + valorASomar > 9){
        soma(casa + 1, numero, (numero[casa] + valorASomar) / 10);
        numero[casa] = (numero[casa] + valorASomar) % 10;
    }
    else numero[casa] += valorASomar;
}

void multiplica(int primeiroNumero[max_Size], int segundoNumero[max_Size], int numero[max_Size]){
    int k = 0;
    for(int i = 0; i < max_Size; i++){
        k = i;
        if(primeiroNumero[i] != 0){    
            for(int j = 0; j < 5; j++){
                if(segundoNumero[j] != 0){
                soma(k, numero, primeiroNumero[i] * segundoNumero[j]);
                }
                k++;
            }
        }
    }
}

void testaMultiplica(){
    int * temp = (int*) calloc (max_Size, sizeof(int));
    int * temp2 = (int*) calloc (max_Size, sizeof(int));
    int * temp3 = (int*) calloc (max_Size, sizeof(int));
    temp[1] = 5;
    temp2[0] = 2;
    multiplica(temp, temp2, temp3);
    for(int i = 10; i >= 0 ; i--){
        printf("%d", temp3[i]);
    }
}

void testaSoma(){
    int temp[5];
    temp[4] = 0;
    temp[3] = 0;
    temp[2] = 0;
    temp[1] = 0;
    temp[0] = 0;
    for(int i = 0; i < 20; i++){
    soma(0, temp, 1);
    printf("%d%d%d%d%d\n", temp[4], temp[3], temp[2], temp[1], temp[0]);
    }
}
