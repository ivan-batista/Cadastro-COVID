#include <stdio.h>
#include <stdlib.h>

void cadastrarPaciente(){

    char nome[50];
    char CPF[14];                //000.000.000-00
    char telefone[15];           //(00) 00000-0000
    char rua[50];
    char numero[4];
    char bairro[20];
    char cidade[20];
    char estado[2];
    char CEP[9];                 //00000-000
    char nascimento[10];         //00/00/0000
    char email[20];
    char dataDiagnostico[10];    //00/00/0000
    char comorbidade[20];

    printf("\nCadastro de Pacientes:");

}

int logar(){

    FILE *base;
    char user[10];
    char senha[10];
    char user1[10];
    char senha1[10];

    printf("Usuario: ");
    fflush(stdin);
    gets(user);
    
    printf("Senha: ");
    fflush(stdin);
    gets(senha);
    
    base = fopen ("login.txt", "r");
 
    while (fscanf(base, "%s %s", &user1, &senha1) != EOF){
        if ((strcmp(user1,user) == 0) && (strcmp(senha1,senha) == 0 )){
            return 1;
        }
    }
    return 0;
}
int main(){
    
    int logado;

    printf("\n=======================================");
    printf("\n|          BEM-VINDO AO C-19          |");
    printf("\n=======================================\n");
    
//    logado=logar();
    logado=1;

    if (logado==1){
        cadastrarPaciente();
    }
    else{
        printf("\nUsuario e Senha invalidos.");
    }

    return 0;
}

