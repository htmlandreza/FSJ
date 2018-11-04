#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/* Feito por Andreza Moreira - 04/11/2018 */

struct Fila {
	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

void criarFila( struct Fila *f, int c ) { 
	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Fila *f ) { // pega o item do começo da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila está vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila está cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%d\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;
	}
	/*printf("\n\n");*/
}

main () {
	int opcao, capa;
	int valor;
	struct Fila umaFila;

	// cria a fila
	/*printf("\nCapacidade da fila? ");
	scanf("%d",&capa);*/
	capa = 20; //capacitade total
	criarFila(&umaFila, capa);

	// apresenta menu
	while( 1 ){
		system("cls");
		printf("*****   EDITOR DE FILA   *****");
		printf("\n1 - ADICIONAR");
		printf("\n2 - EXCLUIR"); 
		printf("\n3 - EXIBIR PRIMEIRO ELEMENTO"); //incompleto
		printf("\n4 - EXIBIR FILA");
		printf("\n5 - ESVAZIAR"); //incompleto
		printf("\n0 - SAIR");
		printf("\n\n DIGITE SUA OPCAO:... ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // Adicionar elemento
				if (estaCheia(&umaFila)){
					system("cls");
					printf("*****   Fila Cheia!!!   *****");
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					getch();
				}
				else {
					system("cls");
					printf("*****   ADICIONAR ITEM NA FILA   *****");
					printf("\n\n\nDigite um numero: ");
					scanf("%d", &valor);
					inserir(&umaFila,valor);
				}

				break;
				
			case 2: // exclui o primeiro item fila, 1 2 3
				if (estaVazia(&umaFila)){
					system("cls");
					printf("*****   Fila Vazia!!!   *****");
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					getch();
				}
				else {
					system("cls");
					printf("*****   Excluindo primeiro item da fila   *****");
					valor = remover(&umaFila);
					printf("\n\n\n O valor %d foi removido da fila com sucesso.", valor);
					printf("\n\n\n*****   Fila atualizada   *****\n");
					mostrarFila(&umaFila);
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					getch(); 
				}
				
				break;
				
			case 4: // exibir fila
				if (estaVazia(&umaFila)){
					system("cls");
					printf("*****   Fila Vazia!!!   *****");
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					
					getch();
				}
				else {
					system("cls");
					printf("*****   Conteudo da Fila   *****\n\n");
					mostrarFila(&umaFila);
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					getch();
				}
				break;
		
				default:
					system("cls");
					printf("*****   Opcao Invalida   *****\n\n");
					printf("\n\n\nPressione qualquer tecla para continuar. . .");
					getch();
		}
	}
}
