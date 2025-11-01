#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CadastrarAluno();
void ListarTodosOsAlunos();

int main(void) {

    int  continuar = 1, escolha;

    while (continuar != 0) {
        printf("MENU DE OPCOES:\n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Listar todos os alunos\n");
        printf("3 - Sair do programa\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                CadastrarAluno();
                break;
            case 2:
                ListarTodosOsAlunos();
                break;
            case 3:
                continuar = 0;
                break;
        }
    }


    return 0;
}

void CadastrarAluno() {
    char nome[50];
    int idade;
    setbuf(stdin, NULL);

    printf("\n\n---- CADASTRO DE ALUNO ----\n");
    printf("Digite os dados do aluno que deseja cadastrar:\n");
    printf("Nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Idade: ");
    scanf("%d", &idade);

    FILE *fp = fopen("cadastro.txt", "a");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    fprintf(fp, "%s, %d\n", nome, idade);
    fclose(fp);
    setbuf(stdin, NULL);
    printf("Aluno cadastrado com sucesso!\n");
    printf("Aperte qualquer tecla para voltar ao menu principal...");
    getchar();
}

void ListarTodosOsAlunos() {
    char linha[100];
    printf("Lista de todos os Alunos Cadastrados: \n");
    FILE *fp = fopen("cadastro.txt", "r");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo");
    }

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        printf("%s", linha);
    }
    printf("----------------------\n");
    fclose(fp);

    setbuf(stdin, NULL);
    printf("Aperte qualquer tecla para voltar ao menu principal...");
    getchar();
}