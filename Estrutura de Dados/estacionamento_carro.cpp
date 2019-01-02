#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MenuPrincipal();
void LISTAGEM();
void EMPILHAR();
void EXIBIRTOPO();
void DESEMPILHAR();
void ESVAZIAR();
void TROCARPILHA();
void EXERCICIOS();
//=======================
#define MAX 10
typedef struct {
	int placa;
	int qm;
} telem;

//TYPEEDF INT TELEM
typedef struct {
	  telem v[MAX];
	  int topo;
	} tpilha;
//=======================
void criar (tpilha *P);
int vazia (tpilha P);
int cheia (tpilha P);
int tamanho (tpilha P);
int elemtopo (tpilha P, telem *dado);
int push (tpilha *P, telem dado);
int pop (tpilha *P, telem *dado);
void imprimir (tpilha *P);



//=======================
tpilha CARROS[2];
int opcao,pilha=0;

main()
{
      int fim=0;
      criar (&CARROS[0]);  
      criar (&CARROS[1]);      
      do
      {
         MenuPrincipal();      
         switch (opcao)
         {
             case 1:EMPILHAR();
                    break;
             case 2:DESEMPILHAR();
                    break;
             case 3:EXIBIRTOPO();
                    break;
             case 4:LISTAGEM();
                    break;
             case 5:ESVAZIAR();
                    break;
             case 6:EXERCICIOS();
                    break;
             case 7:pilha = !(pilha);
                    printf("\n\nO ESTACIONAMENTO %d ESTA ATIVO.",pilha);
                    getch();             
                    break;
             case 9:fim=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim));
      printf("Fim do programa");
      getch();
}


// EXERCICIOS
void EXERCICIOS()
{
      void Menusub();
      void EXER01();
      void EXER02();
      int fim_sub=0,op_sub;
      do
      {
         Menusub();      
         scanf("%d",&op_sub);
         switch (op_sub)
         {
             case 1:EXER01();
                    break;
             case 2:EXER02();
                    break;
             case 9:fim_sub=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim_sub));
}

void Menusub()
{
     system("cls");
     printf("         M E N U   SUB\n");
     printf("\n1 - EXERCICIO 01\n");
     printf("\n2 - EXERCICIO 02\n");
     printf("\n9 - Sair\n");
     printf("\nEscolha uma das opcoes:");
}
void EXER01(){
	
}
void EXER02()
{

}
void EXE03(){
	telem carro_io,carro_manobra;
	int encontrou,aux;
	char MovIO;//movimento de entrada e saida
	system("cls");
	printf(" ESTACIONAMENTO EM FUNCIONAMETO \n ");
	printf("DIGITE OS NUMEROS DA PLACA DO CARRO (ZERO PARA TERMINAR):");
	scanf("%d",&carro_io.placa);
	while(!(carro_io.placa==0))
	{
		printf("DIGITE (E) PARA ESTACIONAR O CARRO OU (S) PARA RETITRAR UM CARRO DO ESTACIONAMENTO. ");
		MovIO=getch();
		printf("\n");
		printf(" DIGITE OS NIUMEROS DDA PLACA DO CARRO(ZERO PARA TERMINAR) :");
		scanf("%d",&carro_io.placa);
	}
	if(MovIO=='E'){
		carro_io.qm=0;
		if(!(push(&CARROS[pilha],carro_io))){
			printf("ESTAFIONAMENTO LOTADO!!\n");
			getch();
		}else{
			if(vazia(CARROS[pilha])){
				printf("ESTACIONAMETO VAZIO \n");
				getch();
			}else{
				
			}
			getch();
		}
	}
	encontrou=0;
	while((!(encontrou))&&(pop(&CARROS[pilha],&carro_manobra)))
	if((carro_manobra.placa)==(carro_io.placa)){
		encontrou=1;
		carro_io=carro_manobra;
		while(pop(&CARROS[!(pilha)],&carro_manobra)){
			carro_manobra.qm++;
			aux=push(&CARROS[pilha],carro_manobra);
		}
	}
	else aux=push(&CARROS[!(pilha)],carro_manobra);
	if(encontrou)
	printf("O CARRO PLACA %d SAIU DO ESTACIONAMENTO E FOI MENOBRADO %d VEZES \n",carro_io.placa,carro_io.qm);
	else
	{
		printf("O %d NAO ESTA NO SISTEMA \n",carro_io.placa);
		while(pop(&CARROS[!(pilha)],&carro_manobra))
		aux=push(&CARROS[pilha],carro_manobra);
	}
	}
// FIM ROTINAS DE EXERCICIOS

void MenuPrincipal()
{
     system("cls");
     printf("         ESTACIONAMENTO PILHA\n");
     printf("\n1 - EMPILHAR\n");
     printf("\n2 - DESEMPILHAR\n");
     printf("\n3 - EXIBIR ELEMENTO DO TOPO\n");
     printf("\n4 - EXIBIR PILHA\n");     
     printf("\n5 - ESVAZIAR\n");          
     printf("\n6 - EXERCICIOS EXTRAS\n");
     printf("\n7 - TROCAR PILHA\n");     
     printf("\n9 - SAIR\n");
     printf("\nDIGITE SUA OPCAO:");
     scanf("%d",&opcao);
}
void EXIBIRTOPO()
{
     telem carro;
     system("cls");
     printf("           T O P O  D A  P I L H A\n");
     if (!(elemtopo (CARROS[pilha], &carro))) 
       {
         printf("NENHUM CARRO ESTACIONADO");
         getch();
         return;
       }
     printf("O CARRO %d ESTA NO TOPO DA PILHA.",carro.placa);
     getch();
}

void EMPILHAR()
{
     telem carro;
     int posicao;
     system("cls");
     printf("           E M P I L H A R  D A D O\n");         
     printf("Digite os numeros da placa do veiculo:");
     scanf("%d",&carro.placa);
     carro.qm=0;
     if (!(push (&CARROS[pilha],carro)))
             {
               printf("ESTACIONAMENTO LOTADO");
               getch();
               return;
             }
     printf("O CARRO %d FOI ESTACIONADO NA VAGA %d.",CARROS[pilha].v[CARROS[pilha].topo].placa ,CARROS[pilha].topo);
     getch();
}
void LISTAGEM()
{
     system("cls");
     printf("         S A I D A  D E  D A D O S  -  L I S T A G E M  => ESTACIONAMENTO: \n",pilha);
     printf("POSICAO         PLACA     N DE MANOBRAS\n");
     if (vazia(CARROS[pilha])) 
       {
         printf("NENHUM CARRO ESTACIONADO");
         getch();
         return;
       }         
     imprimir(&CARROS[pilha]); 
     getch();
}


void DESEMPILHAR()
{
     telem carro;
     system("cls");
     printf("           RETIRAR CARRO\n");         
     if (!(pop(&CARROS[pilha],&carro)))
             {
               printf("ESTACIONAMENTO VAZIO");
               getch();
               return;
             }
             else
             {
               printf("O carro placa  %d saiu do estacionamento da pilha.",carro.placa);
             }
     getch();             
}

void ESVAZIAR()
{
     telem carro;
     system("cls");
     if (vazia(CARROS[pilha])) 
       {
         printf("NENHUM CARRO ESTACIONADO");
         getch();
         return;
       }

     while (!(tamanho(CARROS[pilha])==0)) // falta a funcao tamanho
       {                            // enquanto nao vazia...
         pop (&CARROS[pilha], &carro);        
       }
     printf("ESTACIONAMENTO VAZIO");
     getch();
}
//============================
void imprimir (tpilha *P) {

int i;
for (i=P->topo; i>=0; i--)
   {
     printf("%4d %16d\n",i,P -> v[i].placa, P->v[i].qm);
   }
return;
}

//============================
void criar (tpilha *P){
   P->topo=-1;
}
//============================
int vazia (tpilha P){
   return (P.topo == -1);
}
//============================
int cheia (tpilha P){
   return (P.topo + 1 == MAX);
}
//============================
int tamanho (tpilha P){
   return (P.topo+1);
}
//============================
int elemtopo (tpilha P, telem *dado) 
{
    if (vazia(P)) return (0);
    *dado = P.v[P.topo];
    return 1;
}
//============================
int push (tpilha *P, telem dado) 
{
    if (P->topo==MAX-1) return (0);
    P-> v[++P->topo]= dado;
    return 1;
}
//============================
int pop (tpilha *P, telem *dado) 
{
    if (vazia(*P)) return (0);
    *dado = P->v[P->topo--];
    return 1;
}
