//PROGRAMA c-19
//Cadastro de pacientes com diagnóstico positivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converterCaracteresParaInt(char *data, int n){
    char caracteres[n];
    int i;

    for(i = 0; i < n; i++) {
        caracteres[i] = data[i];
    }

    return atoi(caracteres);
}

int calcularIdade(char *nascimento, char *dataAtual){
    int diaIdade, diaAtual;
    int mesIdade, mesAtual;
    int anoIdade, anoAtual;
    int idade;

    diaIdade = converterCaracteresParaInt(nascimento, 2);
    diaAtual = converterCaracteresParaInt(dataAtual, 2);

    mesIdade = converterCaracteresParaInt(&nascimento[3], 2);
    mesAtual = converterCaracteresParaInt(&dataAtual[3], 2);
    
    anoIdade = converterCaracteresParaInt(&nascimento[6], 4);
    anoAtual = converterCaracteresParaInt(&dataAtual[6], 4);

    if (diaIdade <= diaAtual && mesIdade <= mesAtual) {
        idade = anoAtual - anoIdade;
    } else {
        idade = anoAtual - anoIdade - 1;
    }

    printf ("\n%d", idade);

    return idade;    
}

void cadastrarPaciente(){
    FILE *paciente;
    FILE *envio;

    char nome[50];
    char cpf[15]; // 000.000.000-00
    char telefone[16]; // (00) 00000-0000
    char rua[50];
    char numero[6];
    char complemento[10];
    char bairro[20];
    char cidade[20];
    char estado[3];
    char cep[10]; // 00000-000
    char nascimento[11]; // 00/00/0000
    char email[30];
    char dataDiagnostico[11]; // 00/00/0000
    char comorbidade[50];
    int idade;

    system("cls");  // Não funciona no Linux (usar "system("clear")")

    printf("\n=======================================");
    printf("\n|          BEM-VINDO AO C-19          |");
    printf("\n|        Cadastro de Paciente         |");
    printf("\n=======================================\n");

    printf("Nome: ");
    fflush(stdin);
    gets(nome);

    printf("CPF (000.000.000-00): ");
    fflush(stdin);
    gets(cpf);

    printf("Telefone ((00) 00000-0000): ");
    fflush(stdin);
    gets(telefone);

    printf("Rua: ");
    fflush(stdin);
    gets(rua);

    printf("N.: ");
    fflush(stdin);
    gets(numero);

    printf("Complemento: ");
    fflush(stdin);
    gets(complemento);

    printf("Bairro: ");
    fflush(stdin);
    gets(bairro);

    printf("Cidade: ");
    fflush(stdin);
    gets(cidade);

    printf("Estado (UF): ");
    fflush(stdin);
    gets(estado);

    printf("CEP (99999-999): ");
    fflush(stdin);
    gets(cep);

    printf("Data de Nascimento (DD/MM/AAAA): ");
    fflush(stdin);
    gets(nascimento);

    printf("E-mail: ");
    fflush(stdin);
    gets(email);
    printf("Data do Diagnostico (DD/MM/AAAA): ");
    fflush(stdin);
    gets(dataDiagnostico);

    printf("Comorbidades: ");
    fflush(stdin);
    gets(comorbidade);

    paciente = fopen("pacientes.txt", "a");
    fprintf (paciente, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n", nome, cpf, telefone, rua, numero, bairro, cidade, estado, cep, nascimento, email, dataDiagnostico, comorbidade);
    fclose(paciente);

    printf ("\nCadastro realizado com sucesso.");

    idade = calcularIdade(nascimento, dataDiagnostico);

    if (idade > 65 && strcmp(comorbidade, "") != 0){
        envio = fopen ("envio.txt", "a");
        fprintf (envio, "%d;%s\n", idade, cep);
        fclose(envio);
    }
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
    while (fscanf(base, "%s %s", user1, senha1) != EOF){
        if ((strcmp(user1,user) == 0) && (strcmp(senha1,senha) == 0)){
            return 1;
        }
    }
    return 0;
}
int main(){
    int logado;

    printf("\n=======================================");
    printf("\n|          BEM-VINDO AO C-19          |");
    printf("\n|            Tela de Login            |");
    printf("\n=======================================\n");

    logado=logar();

    if (logado==1){
        cadastrarPaciente();
    }
    else{
        printf("\nUsuario e Senha invalidos.");
    }

    return 0;
}