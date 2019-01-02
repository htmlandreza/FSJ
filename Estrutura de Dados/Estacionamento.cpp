#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> //para fazer as acentuações funcionarem

/* Feito por Andreza Moreira em 26/09/2018 */
/* Deus está vendo o seu CTRL + C! */

//==================================
// criando os menus
void TROCARPILHA();
void EXERCICIOS();
void MenuPrincipal();
void EMPILHAR();
void DESEMPILHAR();
void LISTAGEM();
void ESVAZIAR();
void EXERCICIOS();
void EXIBIRTOPO();

//==================================
// definindo a estrutura da lista
#define MAX 10
typedef struct{
	int placa;
	int qm;
} telem;

//typedef int telem;

typedef struct{
	telem v[MAX];
	int topo;
} tpilha;

//===================================
//criando as listas e as funções - Essa parte está no slide
void criar (tpilha *p){
	p->topo= -1; //vai criar a lista se a posição n for igual a 0
}; 
int vazia (tpilha p){
	return(p.topo== -1);  //vai considerar a lista como vazia
};

//obter o elemento do topo da pilha (sem eliminar)
int elemtopo(tpilha p, telem *valor){
	if(vazia(p)) return 0;
	*valor = p.v[p.topo];
	return 1;
}

//insere um novo elemento no topo da pilha (empilhar)
int push (tpilha *p, telem valor){
	if(p->topo==MAX-1) return 0;
	p->v[++p->topo] = valor;
	return 1;
}

//remove o elemento do topo da pilha (desempilhar), retornando o valor removido
int pop (tpilha *p, telem *valor){
	if(vazia(*p)) return 0;
	*valor = p->v[p->topo--];
	return 1;
}

//==================================
// gerando as opções para o menu
tpilha CARROS;
int opcao;
main(){
	int fim=0;
	//criar (&CARROS[0]);
	//criar (&CARROS[1]);
	criar (&CARROS);
	do {
		MenuPrincipal();
		switch(opcao){
			case 1: EMPILHAR();
					break;
			case 2: DESEMPILHAR();
					break;
			case 3: EXIBIRTOPO();
					break;
			case 4: LISTAGEM();
					break;
			case 5: ESVAZIAR();
					break;
			case 6: EXERCICIOS();
					break;
		//	case 7: pilha = !(pilha);
		//			printf("\n\nO estacionamento %d esta ativo.", pilha);
		//			getch();
		//			break;
			case 9: fim=1;
					break;
			default: printf("Opcao Invalida\n");
					getch();
		}
	}	while (!(fim));
		printf("Fim do programa");
		getch();
}

// Menu Principal do Estacionamento
void MenuPrincipal(){
	system("cls");
	printf("     ESTACIONAMENTO PILHA\n");
	printf("\n1 - EMPILHAR\n");
	printf("\n2 - DESEMPILHAR \n");
	printf("\n3 - EXIBIR ELEMENTO DO TOPO\n");
	printf("\n4 - EXIBIR PILHA\n");
	printf("\n5 - EXERCICIOS EXTRAS\n");
	printf("\n6 - TROCAR PILHA\n");
	printf("\n7 - SAIR\n");
	printf("\n DIGITE A SUA OPÇÃO: ");
	scanf("%d", &opcao);
}

void EXIBIRTOPO(){
	telem carro;
	system("cls");
	printf("		TOPO DA PILHA\n");
	if(!(elemtopo(CARROS[pilha], &carro))){
		printf("NENHUM CARRO ESTACIONADO");
		getch();
		return;
	}
	printf("O carro %d esta no topo da pilha.", carro.placa);
	getch();
}

void EMPILHAR(){
	telem carro;
	int posicao;
	system ("cls");
	printf("		EMPILHAR DADO\n");
	printf("Digite os numeros da placa do veiculo:");
	scanf("%d", &carro.placa);
	
	if(!(push (&CARROS[pilha], carro))){
		printf("ESTACIONAMENTO LOTADO");
		getch();
		return;
	}
	printf("O carro placa %d foi estacionado na vaga %d.", CARROS[pilha].v[CARROS[pilha].topo], CARROS[pilha].topo);
	getch();
}

void LISTAGEM(){
	system ("cls");
	printf("		SAIDA DE DADOS - LISTAGEM => ESTACIONAMENTO : %d\n", pilha);
	printf("Posicao		Placas		N° de Manobras\n");
	
	if(vazia(CARROS[pilha])){
		printf("NENHUM CARRO ESTACIONADO");
		getch();
		return;
	}
	
	imprimir (&CARROS[pilha]);
	getch();
}

void DESEMPILHAR(){
	telem carro;
	system("cls");
	printf("		RETIRAR CARRO\n");
	
	if(!(pop(&CARROS[pilha],&carro))){
		printf("ESTACIONAMENTO VAZIO");
		getch();
		return;
	}
	else{
		printf("O carro placa %d saiu do estacionamento.", carro.placa);
	}
	getch();
}

void ESVAZIAR(){
	telem carro;
	system("cls");
	if(vazia(CARROS[pilha])){
		printf("NENHUM CARRO ESTACIONADO");
		getch();
		return;
	}
	
	while(!(tamanho(CARROS[pilha])==0)){
		pop (&CARROS[pilha], &carro);
	}
	
	printf("ESTACIONAMENTO VAZIO");
	getch();
}

void EXER03(){
	telem carro_io, carro_manobra;
	int encontrou, aux;
	char MovIO; // movimentaçãi de Entrada e Saída
	system("cls");
	printf("		ESTACIONAMENTO EM FUNCIONAMENTO\n");
	printf("Digite os numeros da placa do carro (zero pra terminar):");
	scanf("%d", &carro_io.placa);
	
	while(!(carro_io.placa==0)){
		printf("Digite (E) para estacionar carro ou (S) para retirar um carro do estacionamento: ");
		MovIO=getch();
		printf("\n");
		
		if(MovIO=='E'){
			carro_io.qm=0;
			if(!(push(&CARROS[pilha], carro_io))){
				printf("ESTACIONAMENTO LOTADO\n");
				getch();
			}
			else{}
		}
		else{
			if(vazia(CARRO[pilha])){
				printf("ESTACIONAMENTO VAZIO\n");
				getch();
			}
			else{}
			getch();
		}
	
		printf("Digite os numeros da placa do carro (zero pra terminar):");
		scanf("%d", &carro_io.placa);
	}
}

//===================================
//criando as listas e as funções
//===================================
void imprimir (tpilha *P){
	int i;
	for(i=P->topo; i>=0; i--){
		printf("%4d %16d %15d\n", i,P->v[i].placa, P->v[i].qm);
	}
	return;
}


