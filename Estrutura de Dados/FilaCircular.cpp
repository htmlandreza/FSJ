#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 

//Andreza Moreira - Fila Circular 
//TSI 2018.2

#define MAX 3
typedef int telem;
typedef struct {
	telem v[MAX];
	int inicio;
	int final;
	int tam;
} tfila;

void criar (tfila *F){
	F->inicio=0; 
	F->final=-1;
	F->tam = 0;
};

int vazia (tfila F){
	return(F.tam==0); 
};

int primeiro (tfila F, telem *dado){
	if(vazia(F)) return 0; 
	*dado = F.v[F.inicio];
	return (1);
}

int inserir (tfila *F, telem valor){
	if(F->tam==MAX) return 0;
	else{
		(F->tam)++;
		F->final=(F->final+1) % MAX;
		F->v[F->final]=valor;
		return(1);
	}
}

int remover (tfila *F, telem *valor){
	if (vazia(*F)) return 0; 
	primeiro (*F, valor);
	(F->tam)--;
	F->inicio=(F->inicio+1)% MAX;
	return(1);
}

void imprimir (tfila * F){
	int i;
	if((F->inicio)<=(F->final)){
		for(i=(F->inicio);i<=(F->final);i++){
			printf("%4d %12d\n",i,F -> v[i]);
		}
	}
	else{
		i=(F->inicio);
		while(i<MAX){
		printf("%4d %12d\n",i,F -> v[i]);
		i++;}	
		i=0;
		while(i<=(F->final)){
		printf("%4d %12d\n",i,F -> v[i]);
		i++;}
	}
return;
}

void MenuPrincipal();
void LISTAGEM ();
void ENTRADA ();
void PRIMEIRO();
void INCLUIR ();
void EXCLUIR ();
void ESVAZIAR ();

//Menu
tfila NUMEROS;
int opcao;
main (){
	int fim=0;
	criar (&NUMEROS);
	
	do{
	MenuPrincipal();

		switch(opcao){
			case 1: LISTAGEM();
			break;
			case 2: ENTRADA();
			break;
			case 3: PRIMEIRO();
			break;
			case 4: EXCLUIR();
			break;
			case 5: ESVAZIAR();
			break;
			case 6: fim=1;
			break;
			default: printf("Opção invalida");
			getch();
		}
	}
	while(!(fim));
	printf("Fim do programa");
	getch();
}

void MenuPrincipal(){
	system("cls");
	printf(" *** EDITOR DE FILA *** \n");
	printf("\n1 - EXIBIR FILA");
	printf("\n2 - ADICIONAR");
	printf("\n3 - PRIMEIRO ELEMENTO");
	printf("\n4 - REMOVER");
	printf("\n5 - ESVAZIAR");
	printf("\n6 - SAIR");
	printf("\n\n DIGITE A SUA OPCAO... ");
	scanf("%d", &opcao);
}

void ENTRADA(){
	telem num;
	system ("cls");
	printf(" *** ENTRADA DE DADOS ***\n ");
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	if(!(inserir (&NUMEROS,num))){
		printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS");
		getch();
		return;
	}

}

void PRIMEIRO(){
	telem num;
	system("cls");
	printf(" *** PRIMEIRO DA FILA ***\n");
	printf("Posicao Numeros\n");		
	if(!(primeiro(NUMEROS, &num))){
		printf("NENHUM NUMERO INSERIDO");
		getch();
		return;
	}
	else
		printf("O numero %d esta eh o primeiro da fila.",num);
	getch();
}

void LISTAGEM(){
	system("cls");
	printf(" *** SAIDA DE DADOS - FILA *** \n");
	printf("Posicao Numeros\n");
	if(vazia(NUMEROS)){
		printf("NENHUM NUMERO INSERIDO");
		getch();	
		return;
	}
	imprimir (&NUMEROS);
	getch();
}

void INCLUIR(){
	telem num;
	system("cls");
	printf(" *** INCLUIR DADOS *** \n");
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	if(!(inserir (&NUMEROS,num))){
		printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS ");
		getch();
		return;
	}	
}

void EXCLUIR(){
	telem num;
	system("cls");
	printf(" *** EXCLUIR DADOS ***\n");
	if(!(remover(&NUMEROS, &num))){
		printf("POSICAO INVALIDA");
		getch();
		return;
	}
	else{
		printf("O numero %d foi excluido da fila.", num);
	}
	getch();
}

void ESVAZIAR(){
	telem num;
	int posicao;
	system("cls");
	if(vazia(NUMEROS)){
		printf("NENHUM NUMERO INSERIDO");
		getch();
		return;
	}

	while (vazia(NUMEROS)==0){
		remover(&NUMEROS, &num);
	}
	printf("LISTA ESVAZIADA");
	getch();
}
