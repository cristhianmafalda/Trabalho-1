#include<stdio.h>
#include<stdlib.h>

void troca(int v[], int p1, int p2){     	//funcao que troca os valores entre duas posicoes de um vetor
	int t = v[p1];
	v[p1] = v[p2];
	v[p2] = t;
}

void quicksort(int v[], int f, int l){ 		//funcao que ordena um vetor atraves do m�todo do quicksort
	if (f>=l){
		return;								//condicao para fim de recursao
	}
	int p = rand() % (l-f+1) + f;			//acha uma posicao aleatoria p dentro do vetor para iniciar a ordenacao
	troca(v,p,f);
	p=f;
	int i=f,j=l;
	while(i<j){
		while(v[i]<=v[p] && i<=j){   		//localiza um valor maior que o p
			i++;
		}
		while(v[j]>v[p]){					//localiza um valor menor que o p
			j--;
		}	
		if(j>i){							// verifica a necessidade de troca
				troca(v,i,j);
		}
		
	}	
	troca(v,j,p);	
	quicksort(v,f,j-1);    					//funcao recursiva para ordenar posicoes anteriores a p
	quicksort(v,j+1,l);						//funcao recursiva para ordenar posicoes posteriores a p
}

void main () {
	
	int n;										// ler quantidade n de elementos
	printf ("Entre com o valor de elementos a ser digitado em seguida, os valores do vetor.\n\n");
	scanf ("%d",&n);
	
	if(n<2){									//teste para valor abaixo de 2
		printf("\nErro! Reinicie o programa e insira um valor maior que 1.\n");
	}
	
	if (n>1){									//condicao para necessitar do algoritmo
	
		int *v;									// alocando mem�ria para n elementos
		v = (int*)malloc(n*sizeof(int));
		
		int i;									//lendo os n elementos
		for(i=0;i<n;i++){
			scanf("%d",&v[i]);
		}
			
		quicksort(v,0,n-1);						//ordenando o vetor com quick sort
		
		int d,t;								//descobrir a menor distancia entre pares
		d=v[1]-v[0];	
		for(i=1;i<n-1;i++){
			if(v[i+1]-v[i]<d){					//repete-se at� acharmos o menor m�dulo de distancia
				d=v[i+1]-v[i];	
			}
		}
		
		printf("\n\nMenor diferenca encontrada: %d\n",d);	//teste para conferir a menor distancia 
		
		printf("\nPares com diferenca %d entre si: \n\n", d);	
		for(i=0;i<n-1;i++){						//localizando todos os pares com a menor distanca entre si					
			if(v[i+1]-v[i]==d && i == 0){		//evitando imprimir pares iguais 
				printf ("%d  %d\n",v[i],v[i+1]);
			}
			else if (v[i+1]-v[i]==d && v[i+1]!=v[i-1]){
				printf ("%d  %d\n",v[i],v[i+1]);
			}
		}
		free(v);								//liberando a mem�ria utilizada
	}
	getch();
}
