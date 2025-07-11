#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TAMANHO 100

//Função para gerar senha
void gerarSenha(int tamanho, int usarMaiusculas, int usarNumeros, int usarSimbolos){
    char minusculas[] = "abcdefghijklmnopqrstuvwxyz";
    char maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numeros[] = "0123456789";
    char simbolos[] = "!@#$%&*?";

    char conjunto[MAX_TAMANHO] = "";

    //Monta o  conjunto de caracteres
    strcat(conjunto, minusculas);
    if (usarMaiusculas) strcat(conjunto, maiusculas);
    if (usarNumeros) strcat(conjunto, numeros);
    if (usarSimbolos) strcat( conjunto, simbolos);

    int len = strlen(conjunto);
    if (len == 0){
        printf("Nenhum tipo de caractere foi selecionado.\n");
        return;
    
    }
    printf("Senha gerada: ");
    for (int i = 0; i<tamanho; i++){
        printf("%c", conjunto[rand() % len]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    int tamanho, usarMaiusculas, usarNumeros, usarSimbolos;

    printf("Gerador de Senhas Fortes\n\n");

    printf("Informe o tamanho da senha: ");
    scanf("%d", &tamanho);

    printf("Incluir letras maiúsculas? (1 = sim, 0 = não): ");
    scanf("%d", &usarMaiusculas);

    printf("Incluir números? (1 = sim, 0 = não): ");
    scanf("%d", &usarNumeros);

    printf("Incluir símbolos? (1 = sim, 0 = não): ");
    scanf("%d", &usarSimbolos);

    gerarSenha(tamanho, usarMaiusculas, usarNumeros, usarSimbolos);

    return 0;
}
