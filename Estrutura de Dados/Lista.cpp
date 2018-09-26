#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> //para fazer as acentuações funcionarem
/* Feito por Livia Dantas - Deus está vendo o seu CTRL + C! */
/* Ajustes de Andreza Moreira - 26/09/2018 */

// criando os menus
void MenuPrincipal();
void LISTAGEM ();
void ENTRADA ();
void INCLUIR ();
void EXCLUIR ();
void ESVAZIAR ();

//==================================
// definindo a estrutura da lista
//==================================
#define MAX 10
typedef int telem;
typedef struct {
	telem v[MAX];
	int n;
} tlista;

//===================================
//criando as listas e as funções - Essa parte está no slide
//===================================
void criar (tlista *L){
	L -> n=0; //vai criar a lista se a posição n for igual a 0
}; 
int vazia (tlista L){
	return(L.n==0);  //vai considerar a lista como vazia
};
int cheia (tlista L){
	return(L.n==MAX); //vai considerar a lista como cheia
};
int tamanho (tlista L){
	return(L.n); //vai retornar as posições preenchidas da lista
};
int inserir (tlista * L, int pos, telem dado){
	/*retorna 0 se a posião for inválida ou se a lista estiver cheia*/
	/*caso contrário, retorna 1*/
	int i;
	if((L->n==MAX) || (pos> L->n+1)) 
			{
				return(0);
			}
	for (i=L->n;i>=pos;i--)
		L->v[i] = L->v[i-1];
	
	L ->v[pos-1] = dado;
	(L->n)++;
	return(1);
};
int remover (tlista * L, int pos, telem * dado){
	/*O paramêtro dado irá receber o elemento encontrado*/
	/*Retorna 0 se a posição for inválida. Caso contrário, retorna 1*/
	int i;
	if ((pos >L->n)||(pos<=0))return (0);
	*dado = L->v[pos-1];
	for(i=pos;i<=(L->n)-1;i++)
	L->v[i-1]=L->v[i];
	(L->n)--;
	return(1);
}

//void imprimir (tlista * L);
void imprimir (tlista *L){
	int i;
	for (i=0; i<=(L->n)-1;i++){
		printf("%4d %16d\n", i+1, L -> v[i]);
	}
	return;
}

//=====================================
//GERANDO AS OPÇÕES DO MENUZINHO
//=====================================
tlista NUMEROS;
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
			case 1: LISTAGEM();
					break;
			case 2: ENTRADA();
					break;
			case 3: INCLUIR();
					break;
			case 4: EXCLUIR();
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
	printf("     EDITOR DE LISTA \n");
	printf("\n1 - EXIBIR LISTA\n");
	printf("\n2 - ADICIONAR \n");
	printf("\n3 - INCLUIR\n");
	printf("\n4 - REMOVER\n");
	printf("\n5 - ESVAZIAR\n");
	printf("\n6 - SAIR\n");
	printf("\n DIGITE A SUA OPÇÃO...");
	scanf("%d", &opcao);
}
void ENTRADA()
{
	telem num;
	system ("cls");
	printf("                   E N T R A D A   D E   D A D O S\n ");
	printf("Digite um número inteiro (zero para terminar):");
	scanf("%d", &num);
	while(!(num==0))
	{
		if(!(inserir (&NUMEROS, tamanho(NUMEROS)+1, num)))
		{
			printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS");
			getch();
			return;
		}
	printf("Digite um numero inteiro (zero para terminar):");
	scanf("%d", &num);	
		}
	}
void LISTAGEM()
{
	system("cls");
	printf("			S A I D A     D E    D A D O S  -  L I S T A G E M\n");
	printf("Posição      Numeros\n");
	if(vazia(NUMEROS))
	{
		printf("NENHUM NUMERO INSERIDO");
		getch();
		return;
	}
	imprimir (&NUMEROS);
	getch();
}
void INCLUIR()
{
	telem num;
	int posicao;
	system("cls");
	printf("			I N C L U I R   D A D O\n");
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	printf("Digite posição de inclusão:");
	scanf("%d", &posicao);
	if(!(inserir (&NUMEROS,posicao,num)))
		{
			printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS OU POSICAO INVALIDA");
			getch();
			return;
		}
}
void EXCLUIR()
{
	telem num;
	int posicao;
	system("cls");
	printf("           E X C L U I R  D A D O\n");
	printf("Digite posição de exclusão:");
	scanf("%d", &posicao);
	if(!(remover(&NUMEROS, posicao, &num)))
		{
			printf("POSIÇÃO INVÁLIDA");
			getch();
			return;
		}
		else
		{
			printf("O número %d foi excluído da lista.", num);
			
		}
		getch();
}

void ESVAZIAR()
{
	telem num;
	int posicao;
	system("cls");
	if(vazia(NUMEROS))
	{
		printf("NENHUM NUMERO INSERIDO");
		getch();
		return;
	}
	
     while (!(tamanho(NUMEROS)==0))
     {
     	remover(&NUMEROS, tamanho(NUMEROS), &num);
	 }
	 printf("LISTA ESVAZIADA");
	 getch();
}
