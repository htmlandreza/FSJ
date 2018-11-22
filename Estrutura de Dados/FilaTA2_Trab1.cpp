#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
 
//Andreza Moreira
//TSI 2018.2

//TRABALHO TA2 - CONSULTÓRIO MÉDICO
 
 #define MAX 5
typedef struct{
	char nome;
	int rg;
	int idade;
	char planSaude;
	char hora;
   }	telem;
   
typedef struct {
    telem v[MAX]; 
    int inicio; 
    int fim;   
    int tam; 
   }	tfila;
   
void criar(tfila *F){
  F -> inicio= 0;
  F -> fim = -1;
  F ->tam = 0;
} 

int vazia(tfila F){
   return (F.tam==0);
}        

int primeiro(tfila F, telem *dado){
    if (vazia(F)) return (0);
    *dado = F.v[F.inicio];
    return (1);
}

int inserir(tfila *F, telem dado){
  	if(F->tam==MAX) return 0; 
        (F->tam)++;
        F->fim=(F->fim+1)% MAX;
        F->v[F->fim]=dado;
        return(1);
}

int remover(tfila *F, telem *dado){
    if (vazia(*F)) return (0);
    primeiro(*F, dado);
    (F->tam)--;
    F->inicio = (F->inicio+1) %MAX;
    return 1;
}

int esvaziar(tfila *F){
  if(vazia(*F)) return 0;
  F->inicio = F->fim + 1;
  return 1;
}

void imprimir (tfila *F)
{
    int i;
    if ((F->inicio)<=(F->fim)){	
		 for (i>=(F->inicio);i<=(F->fim);i++){
		    printf("%4d       %s                       %s\n", i, F -> v[i].nome, F->v[i].hora);
		   }
        }
     else{
    	 i=(F->inicio);
    	 while(i<=MAX){
    	     printf("%4d      %s                        %s\n", i,F ->v[i].nome, F->v[i].hora);
    	     i++;
     	   }
     	   
		 i=0;
		 
		 while(i<=(F->fim)){
             printf("%4d      %s                        %s\n",i,F->v[i].nome, F->v[i].hora);
             i++;
  		   }
        }
    return;
}
 
void MenuPrincipal();
void INSERIR();
void EXCLUIR();
void CHAMAR_PACIENTE();
void EXIBIR();
void EXIBIR();
void ESVAZIAR();
 
//menu
tfila CLIENTES;
int opcao;

main(){
      int codigo=0;
      criar (&CLIENTES);
      do{
         MenuPrincipal();
         
         	switch (opcao){
             	case 1:INSERIR();
                    break;
             	case 2:EXCLUIR();
                    break;
             	case 3:CHAMAR_PACIENTE();
                    break;
             	case 4:EXIBIR();
                    break;
             	case 5:ESVAZIAR();
                    break;
             	case 6:codigo=1;
                    break;
             	default: printf("Opcao invalida\n");
                      getch();
        	}
      	}
			while (!(codigo));
      			printf("Fim do programa");
      		getch();
}

void MenuPrincipal(){
     system("cls");
     printf(" *** CONSULTORIO MEDICO ***\n");
     printf("\n1 - ADICIONAR PACIENTE");
     printf("\n2 - EXCLUIR PACIENTE");
     printf("\n3 - EXIBIR PROXIMO");
     printf("\n4 - EXIBIR FILA");
     printf("\n5 - ESVAZIAR");
     printf("\n6 - SAIR\n");
     printf("\nDIGITE SUA OPCAO: ");
     scanf("%d",&opcao);
}

void INSERIR(){
     telem cliente;
     system ("cls");
     printf(" *** ADICIONAR PACIENTE *** \n\n");
     printf("Nome: ");
     scanf("%s", cliente.nome);
	 getchar(); 
     printf("RG: ");
     scanf("%d", &cliente.rg);
     printf("Idade: ");
     scanf("%d", &cliente.idade);
     printf("Plano de saude: ");
     scanf("%s", cliente.planSaude);
     getchar();
     printf("Horario previsto para atendimento: ");
     scanf("%s", cliente.hora);
     getchar();
     	if(!(inserir(&CLIENTES,cliente))){
         	printf("NUMERO MAXIMO DE PACIENTES INSERIDOS");
         	getch();
         	return;
     	}
     printf("\n\n\nPaciente: %s \nSera atendido: %s horas\nSenha do paciente:  %d", cliente.nome, cliente.hora, CLIENTES.fim); 
     getch();
}

void EXCLUIR(){
     telem cliente;
     system("cls");
     printf("*** EXCLUIR PACIENTE ***\n");
     	if(!(remover(&CLIENTES, &cliente))){
           printf("Fila vazia");
           getch();
           return;
        }
        else{
          printf("O paciente %s foi excluido", cliente.nome);
        }
        getch();
}

void CHAMAR_PACIENTE(){ 
     telem cliente;
     system("cls");
     printf("*** CHAMA PACIENTE ***\n");
     if(!(primeiro(CLIENTES, &cliente))){
         printf("NENHUM PACIENTE INSERIDO");
         getch();
         return;
    }
     printf("\n\nO paciente %s sera o proximo a ser atendido.",cliente.nome);
     getch();
}

void EXIBIR(){
     system("cls");
     printf("*** EXIBIR FILA DE PACIENTES ***:\n");
     printf("Senha:         Paciente:           Horario:\n");
     if(vazia(CLIENTES)){
        printf("NENHUM PACIENTE INSERIDO");
        getch();
        return;
     }
     imprimir(&CLIENTES);
     getch();
}

void ESVAZIAR(){
     telem cliente;
     system ("cls");
     printf("        E S V A Z I A R   F I L A:\n\n");
     if(vazia(CLIENTES))
     {
        printf("        NENHUM PACIENTE INSERIDO\n");
        getch();
        return;
     }
     while((remover(&CLIENTES,&cliente))) //remove um a um dos elementos da fila
          remover(&CLIENTES,&cliente);

    printf("           FILA ESVAZIADA");
    getch();
    return;
}
