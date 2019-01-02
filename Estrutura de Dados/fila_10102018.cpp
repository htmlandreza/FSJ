#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> //para fazer as acentuações funcionarem

/* Feito por Andreza Moreira - 10/10/2018 */

// criando os menus
void MenuPrincipal();
void ADICIONAR ();
void EXCLUIR ();
void EXIBIRPRIELEMENTO ();
void EXIBIRFILA ();
void ESVAZIAR ();
void SAIR();

//==================================
// definindo a estrutura da fita
//==================================
#define MAX 20
typedef int telem;
typedef struct {
	telem v[MAX];
	int inicio;
	int final;
} tfila;

//===================================
//criando as fila e as funções - Essa parte está no slide
//===================================
void criar (tfila *F){
     F->inicio=0;
     F->final=-1;
}; 

int vazia (tfila F){
	return(F.inicio>F.final);
};

int primeiro (tfila F, telem *dado){
    if(vazia(F)) return 0; //Erro: final vazia
    *dado = F.v[F.inicio];
    return (1);
}; 

int inserir (tfila *F, telem valor){
    if(F->final==MAX-1) return 0;
    
    (F->final)++;
    
    F->v[F->final]=valor;
    return (1);
}

int remover (tfila *F, telem *valor){
    if(vazia(*F)) return 0; //Erro: fila vazia
    primeiro(*F, valor);
    (F->inicio)++;
    return(1);
}

//=====================================
//GERANDO AS OPÇÕES DO MENUZINHO
//=====================================
tfila NUMEROS;
int opcao;
main ()
{
	setlocale(LC_ALL, "Portuguese");
	int fim=0;
	criar (&NUMEROS);
	do
	{
		MenuPrincipal();
		switch(opcao)
		{
			case 1: ADICIONAR();
					break;
			case 2: EXCLUIR();
					break;
			case 3: EXIBIRPRIELEMENTO();
					break;
			case 4: EXIBIRFILA();
					break;
			case 5: ESVAZIAR();
					break;
			case 6: fim=1;
					break;
			default: printf("Opção inválida");
					getch();
			
		}
	}while(!(fim));
	printf("Fim do programa");
			getch();
}

void MenuPrincipal(){
	system("cls");
	printf("     EDITOR DE FILA \n");
	printf("\n1 - ADICIONAR\n");
	printf("\n2 - EXCLUIR \n");
	printf("\n3 - EXIBIR PRIMEIRO ELEMENTO\n");
	printf("\n4 - EXIBIR FILA\n");
	printf("\n5 - ESVAZIAR\n");
	printf("\n6 - SAIR\n");
	printf("\n DIGITE A SUA OPÇÃO...");
	scanf("%d", &opcao);
}
