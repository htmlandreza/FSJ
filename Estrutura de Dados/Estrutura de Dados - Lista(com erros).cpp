#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MenuPrincipal();
void LISTAGEM();
void ENTRADA();
void INCLUIR();
void EXCLUIR();
void ESVAZIAR();

//====================

#define MAX 20
typedef int telem;

typedef struct{
	telem v[MAX];
	int n;
} tlista;

//====================

// Cria uma lista vazia
void criar (tlista *L){
	L -> n=0;
}

// Verificar se a lista está vazia
int vazia (tlista L){
	return (L.n == 0);
}

// Verificar se a lista está cheia
int cheia (tlista L){
	return (L.n == MAX);
}

// Obter tamanho da lista
int tamanho (tlista L){
	return (L.n);
}

// Inserção de um elemento em uma determinada posição
// Requer o deslocamento à direita dos elementos v(i+1)...v(n)
int inserir (tlista *L, int pos, telem dado){
	/* Retorna 0 se a posição dor inválida ou se a lista estiver cheia */
	/* Caso contrário, retorna 1 */
	
	int i;
	
	if ((L->n==MAX) || (pos>L->n+1)) return (0);
	
	for (i=L->n; i>=pos; i--)
		L->v[i] = L-v[i-1];
		
	L->v[pos-1] = dado;
	(L->n)++;
	return (1);	
}

// Remoção do elemento de uma determinada posição
// Requer o deslocamento à esquerda dos elementos v(p+1)...v(n)
int remover (tlista *L, int pos, telem *dado){
	/* O parâmetro dado irá receber o elemento encontrado */
	/* Retornna 0 se a posição for inválida. Caso contrário, retorna 1 */
	
	int i;
	
	if ((pos>L->n) || (pos<=0)) return (0);
	
	*dado = L->v[pos-1];
	
	for (i=pos; i<=(L->n)-1; i++)
		L->v[i-1]=L->v[i];
	
	(L->n)--;
	return (1);
}

// Mostrar dados
void imprimir(tlista *L){
	int i;
	for(i=0; i<=(L->n)-1; i++){
		printf("%4d %16d\n", i+1, L->v[i]);
	}
	return;
}

//==================
// Menu Principal
void MenuPrincipal(){
	system("cls");
	printf("         EDITOR DE LISTA\n");
	printf("\n1 - EXIBIR LISTA\n");
	printf("\n2 - ADICIONAR\n");
	printf("\n3- INCLUIR\n");
	printf("\n4- REMOVER\n");
	printf("\n5- ESVAZIAR\n");
	printf("\n6- SAIR\n");
	printf("\nDIFITE SUA OPÇÃO:");
	
	int opcao;
	scanf("%d", &opcao);
};

//Entrada de dados
void ENTRADA(){
	telem num;
	system("cls");
	printf("          ENTRADA DE DADOS\n");
	
	printf("Digite um numero inteiro (zero para terminar):");
	scanf("%d", &num);
	
	while(!(num==0)){
		if(!(inserir (&NUMEROS, tamanho(NUMEROS)+1, num))){
			printf ("NUMERO MAXIMO DE ELEMENTOS INSERIDOS");
			getch();
			return;
		}
		printf("Digite um numero inteiro (zero para terminar):");
		scanf("%d", &num);
	}
}

//Saida de dados
void LISTAGEM(){
	system("cls");
	printf("          SAIDA DE DADOS - LISTAGEM");
	printf("Posicao           Numeros\n");
	
	if(vazia(NUMEROS)){
		printf("NENHUM NUMERO INSERIDO");
		getch();
		return;
	}
	imprimir (&NUMEROS);
	getch();
}

//Inclusao de dados
void INCLUIR(){
	telem num;
	int posicao;
	system ("cls");
	printf("          INCLUIR DADOS\n");
	printf("Digite um numero inteiro:");
	scanf("%d", &num);
	printf("Digite posição de inclusao:");
	scanf("%d", &posicao);
	
		if(!(inserir(&NUMEROS, posicao, num))){
			printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS OU POSICAO INVALIDA");
			getch();
			return;
		}
}

//Excluir dados
void EXCLUIR(){
	telem num;
	int posicao;
	printf("          EXCLUIR DADOS\n");
	printf("Digite posição de exclusao:");
	scanf("%d", &posicao);
	
		if(!(remover(&NUMEROS, posicao, &num))){
			printf("POSICAO INVALIDA");
			getch();
			return;
		}
		else{
			printf("O numero %d foi excluido da lista.", num);
		}
	getch();
}

//Esvaziar lista
void ESVAZIAR(){
	telem num;
	int posicao;
	system("cls");
		if (vazia(NUMEROS)){
			printf("NENHUM NUMERO INSERIDO");
			getch();
			return;
		}
	
		while(!(tamanho(NUMEROS)==0)){
			remover(&NUMEROS, tamanho(NUMEROS),&num);
		}
	printf("LISTA ESVAZIADA");
	getch();
}
