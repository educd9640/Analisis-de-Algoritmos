#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxi=0;
void tabla(char *cade1,char *cade2,int x, int y);
void Algoritmo(char *cade1,char *cade2,int **string,int r, int c);
int secuenciaIf(int c,int r,char *cade1,char *cade2,int **string );
int max(int a, int b);
void imprimir(int c,int r,char*cade1,char*cade2,int**string);
void subcadenas(int**string,int r,int c,char*cade1,char*cade2);

int main(){
	char *cade1,*cade2,aux[10],aux2[10];
	int i,j;
	cade1=(char*)malloc(sizeof(char)*15);
	cade2=(char*)malloc(sizeof(char)*15);
	
	puts("Bienvenido");
	puts("Introduce la primer cadena de caracteres");
	fflush(stdin);
	gets(aux);
	puts("Introduce la segunda cadena de caracteres");
	fflush(stdin);
	gets(aux2);

	strcpy(cade1,"0\0");
	strcpy(cade2,"0\0");
	strcat(cade1,aux);
	strcat(cade2,aux2);

	tabla(cade1,cade2,strlen(cade1),strlen(cade2));
	free(cade1);
	free(cade2);

}

void tabla(char *cade1,char *cade2,int c, int r){
	int **string,i;

	string=(int**)malloc(sizeof(int*)*r);

	for ( i = 0; i < r; ++i)
		string[i]=(int*)malloc(sizeof(int*)*c);

	Algoritmo(cade1,cade2,string,r,c);
}

void Algoritmo(char *cade1,char *cade2,int **string,int r, int c){
	int i,j;
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){										//rellena la tabla
			string[i][j]=secuenciaIf(i,j,cade1,cade2,string);
		}
	}

	imprimir(c,r,cade1,cade2,string);
	printf("\nSubcadenas obtenidas\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){							//revisa la tabla y genera las subcadenas
			if(string[i][j]==maxi)
				subcadenas(string,i,j,cade1,cade2);
		}
	}

	for(i=0;i<r;i++){
		free(string[i]);
	}
	free(string);

}

int secuenciaIf(int r,int c,char *cade1,char *cade2,int **string ){
	if(c==0 || r==0){			
		return 0;
	}else{
		if(cade1[c]==cade2[r]){							//diagonales
			if((string[r-1][c-1])+1>maxi)
				maxi=(string[r-1][c-1])+1;
			return (string[r-1][c-1])+1;
		}else
			if(string[r][c-1]!=string[r-1][c])			//sup || izq
				return max(string[r][c-1],string[r-1][c]);				
			else
				return string[r-1][c];					//sup
	}
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

void imprimir(int c,int r,char*cade1,char*cade2,int**string){
	int i,j;
	printf("   ");
	for(i=0;i<c;i++)
		printf("%c   ",cade1[i]);
	puts("");
	for(i=0;i<r;i++){
		printf("%c  ",cade2[i]);
		for(j=0;j<c;j++){								
			

			if(cade1[j]==0 || cade2[i]==0 || string[i][j]==0)
				printf(" ");
			else if(cade1[j]==cade2[i])
				printf("D");
			else if(string[i][j-1]>string[i-1][j])
				printf("I");
			else
				printf("S");

			printf("%d  ",string[i][j]);
		}
		puts("");
	}
}

void subcadenas(int**string,int r,int c,char*cade1,char*cade2){
	char *aux,*ptr;												
	int i,j,k,o=maxi-1;
	aux=(char*)malloc(sizeof(char)*maxi);
	
	if(cade1[c]==cade2[r]){
		for(i=0;i<maxi;i++){
			while(1){
				if(cade1[c]==cade2[r])
					break;
				else if(string[r][c-1]>string[r-1][c])
					c--;
				else
					r--;
			}
			aux[o]=cade1[c];
			o--;
			c--;
			r--;
		}
		for(i=0;i<maxi;i++)
			printf("%c",aux[i]);
		puts("");
	}
	free(aux);
}