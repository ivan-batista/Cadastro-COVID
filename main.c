#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *base;
    char user[10];
    char senha[10];
    char user1[10];
    char senha1[10];

    printf("BEM-VINDO AO C-19\n");
    printf("Usuario: ");
    fflush(stdin);
    gets(user);
    
    printf("Senha: ");
    fflush(stdin);
    gets(senha);
    
    base = fopen ("login.txt", "r");
 
    while (fscanf(base, "%s %s", &user1, &senha1) != EOF){
        printf("\nComparando %s:%s com %s:%s",user1,senha1,user,senha);
        if ((strcmp(user1,user) == 0) && (strcmp(senha1,senha) == 0 )){
            printf("\nSucesso!!!");
            break;
        }
    }

    return 0;
}
