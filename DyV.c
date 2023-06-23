#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nlon(int longitud);
char* cadena(char*str,int lon);
long long int multiplicaG(char *x,char *y,int n,int base);
char* dividir(char* str,char lado, int n);
char* suma(char* x,char* y,int n,int base);
int producto(char x,char y, int base);
int potencia(int base, int p);
int Hexa(char *hex);
char* binario(int num, int n);
int db(int lon);

int main(){

	int longitud, base,base2, nl;
	long long int resultado=0;
	char num1[16],num2[16],*nNum1,*nNum2,aux1[16],aux2[16],*b_2;
	

	puts("Bienvenido");
	//do{
	fflush(stdin);
	puts("Ingrese la longitud del numero con mayor cantidad de digitos");
	scanf("%d",&longitud);
	puts("Ingrese la base de los numeros a multiplicar");
	puts("Ya sea 2, 10 o 16");
	scanf("%d",&base);
	fflush(stdin);
	puts("Ingrese el primer numero a multiplicar");
	gets(num1);
	fflush(stdin);
	puts("Ingrese el segundo numero a multiplicar");
	gets(num2);

	nNum1=(char*)malloc(sizeof(char)*64);
	nNum2=(char*)malloc(sizeof(char)*64);
	b_2=(char*)malloc(sizeof(char)*64);

	if(base==16){
		base2=10;
		itoa(Hexa(num1),aux1,10);
		itoa(Hexa(num2),aux2,10);	

		if(strlen(aux1)>strlen(aux2))
			longitud=strlen(aux1);
		else
			longitud=strlen(aux2);

		nNum1=cadena(aux1,nlon(longitud));
		nNum2=cadena(aux2,nlon(longitud));
		resultado=multiplicaG(nNum1,nNum2,nlon(longitud),base2);
		printf("El resultado de multiplicar %s * %s, es igual a %llX\n",num1,num2,resultado );
	}else if(base==10){
		nNum1=cadena(num1,nlon(longitud));
		nNum2=cadena(num2,nlon(longitud));
		resultado=multiplicaG(nNum1,nNum2,nlon(longitud),base);
		printf("El resultado de multiplicar %s * %s, es igual a %d\n",num1,num2,resultado );
	}else{
		nNum1=cadena(num1,nlon(longitud));
		nNum2=cadena(num2,nlon(longitud));
		resultado=multiplicaG(nNum1,nNum2,nlon(longitud),base);
		b_2=binario(resultado,db(nlon(resultado)));
		printf("El resultado de multiplicar %s * %s, es igual a %s\n",num1,num2,b_2 );
		free(b_2);
	}

	
	
	//}while(continuar)

	free(nNum1);
	free(nNum2);
	return 0;
}

int nlon(int longitud){
	int n=2;
	while(longitud>n){
		n=n*2;
	}
	return n;
}

char* cadena(char*str,int lon){
	char *aux;
	aux=(char*)malloc(sizeof(char)*64);
	int i;
	for(i=0	;i<(lon-strlen(str)) ;i++){
		aux[i]='0';
	}
	aux[i]='\0';
	strcat(aux,str);
	return aux;
}

long long int multiplicaG(char *x,char *y,int n,int base){
	if(strlen(x)==1 && strlen(y)==1)
		return producto(*x,*y,base);

	if(strlen(x)!=n || strlen(y)!=n){
		if(strlen(x)>strlen(y)){
			n=nlon(strlen(x));
			x=cadena(x,n);
			y=cadena(y,n);
		}
		else{
			n=nlon(strlen(y));
			x=cadena(x,n);
			y=cadena(y,n);
		}
	}
	
	char *xi,*xd,*yi,*yd;
	long long int p1,p2,p3, resultado=0;
	xi=(char*)malloc(sizeof(char)*(n));
	xd=(char*)malloc(sizeof(char)*(n));
	yi=(char*)malloc(sizeof(char)*(n));
	yd=(char*)malloc(sizeof(char)*(n));

	xi=dividir(x,'i',n);
	xd=dividir(x,'d',n);
	yi=dividir(y,'i',n);
	yd=dividir(y,'d',n);
	
	p1=multiplicaG(xi,yi,n/2,base);
	p2=multiplicaG(suma(xi,xd,n,base),suma(yi,yd,n,base),n/2,base);
	p3=multiplicaG(xd,yd,n/2,base);

	resultado=(potencia(base,n) * p1) + (potencia(base,n/2) * (p2-p1-p3)) + p3;
	free(xi);
	free(xd);
	free(yi);
	free(yd);
	return resultado;

}



char* dividir(char* str,char lado, int n){
	char *aux;
	aux=(char*)malloc(sizeof(char)*(n+1));
	if(lado=='i')
		strncpy(aux,str,n/2);
	else
		strncpy(aux,str+n/2,n/2);

	aux[n/2	]='\0';
	return aux;
}

char* suma(char* x,char* y,int n,int base){
	char *aux;

	aux=(char*)malloc(sizeof(char)*(n+2));
	int i,j=strlen(x)-1, acarreo=0;
	for(i=strlen(x)-1;i>=0;i--,j--){

		aux[j]=(((x[i]-48)+(y[i]-48)+acarreo)%base)+48;
		acarreo=((x[i]-48)+(y[i]-48)+acarreo)/base;
	}
	aux[strlen(x)]='\0';
	if (acarreo!=0){
		char *aux2;
		aux2=(char*)malloc(sizeof(char)*(n+2));
		aux2[0]=acarreo+48;
		aux2[1]='\0';
		strcat(aux2,aux);
		free(aux);
		return aux2;
	}else{
		return aux;
	}
}

int producto(char x,char y, int base){
	int resultado=0;
	if(base==10){
		resultado=(x-48)*(y-48);	
	}else{
		if(x=='1' && y=='1')
			resultado=1;
		else
			resultado=0;
	}
	return resultado;

}

int potencia(int base, int p){
	int i,aux=1;
	for (i = 0; i < p; ++i)
	{
		aux=base*aux;
	}
	return aux;
}

int Hexa(char *hex){
    int dec=0,length=strlen(hex),i;
    char digit;
    for(i=0;i<length;i++){
        digit=hex[length-1-i];
        if(digit>='a' && digit<='z')
            digit=digit-32;
        if(digit >= '0' && digit <='9')
            dec+=(digit - '0')*(potencia(16,i));
        else
            dec+= (digit - 'A' + 10)*(potencia(16,i));
    }
    return dec;
}

char* binario(int num, int n){
    int aux=num,i,valor;
    char *bin;

    bin=(char*)malloc(sizeof(char)*(n+1));

    for(i=n;i>=0;i--){
        valor=num%2;
        aux=aux/2;
        bin[i]=valor+48;
        num=aux;
    }
    bin[n+1]='\0';
    return bin;   
}

int db(int lon){
	int i=0;
	if(lon==1){
		return 0;
	}else{
		while(lon!=1){
			lon=lon/2;
			i++;
		}
		return i;	
	}
}