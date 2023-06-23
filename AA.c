#include <stdio.h>
#include <stdlib.h>

struct cambio{
	int peso,dosp,cincop,diezp;
	int b20,b50,b100,b200,b500,b1000;
};
struct conteo{
	int peso, dosp, cincop, diezp;
	int b20, b50, b100, b200, b500, b1000;	
};
void algoritmo(struct cambio *moneda,int recibo, struct conteo *cantidad);
void imprimir(struct conteo*cantidad);

int main(){

	struct cambio *moneda,var;
	struct conteo *cantidad,var2;
	int recibo;
	moneda=&var;
	cantidad=&var2;

	cantidad->b1000=0;
	cantidad->b500=0;
	cantidad->b200=0;
	cantidad->b100=0;
	cantidad->b50=0;
	cantidad->b20=0;
	cantidad->diezp=0;
	cantidad->cincop=0;
	cantidad->dosp=0;
	cantidad->peso=0;

	puts("Bienvenido");

	puts("Ingrese la cantidad de monedas de 1 peso");
	scanf("%d",&moneda->peso);
	puts("Ingrese la cantidad de monedas de 2 pesos");
	scanf("%d",&moneda->dosp);
	puts("Ingrese la cantidad de monedas de 5 pesos");
	scanf("%d",&moneda->cincop);
	puts("Ingrese la cantidad de monedas de 10 pesos");
	scanf("%d",&moneda->diezp);
	puts("Ingrese la cantidad de billetes de 20 pesos");
	scanf("%d",&moneda->b20);
	puts("Ingrese la cantidad de billetes de 50 pesos");
	scanf("%d",&moneda->b50);
	puts("Ingrese la cantidad de billetes de 100 pesos");
	scanf("%d",&moneda->b100);
	puts("Ingrese la cantidad de billetes de 200 pesos");
	scanf("%d",&moneda->b200);
	puts("Ingrese la cantidad de billetes de 500 pesos");
	scanf("%d",&moneda->b500);
	puts("Ingrese la cantidad de billetes de 1000 pesos");
	scanf("%d",&moneda->b1000);

	puts("Ingrese el cambio a recibir");
	scanf("%d",&recibo);

	algoritmo(moneda,recibo,cantidad);

	return 0;

}


void algoritmo(struct cambio *moneda,int recibo, struct conteo *cantidad){
	int meta=recibo,check=1;

	while(meta!=0){

		if(meta>=1000 && moneda->b1000!=0){					//$1000
			meta=meta-1000;
			moneda->b1000--;
			cantidad->b1000++;
		}else if(meta>=500 && moneda->b500!=0){//$500
			meta=meta-500;
			moneda->b500--;
			cantidad->b500++;
		}else if(meta>=200 && moneda->b200!=0){//$200
			meta=meta-200;
			moneda->b200--;
			cantidad->b200++;
		}else if(meta>=100 && moneda->b100!=0){//$100
			meta=meta-100;
			moneda->b100--;
			cantidad->b100++;
		}else if(meta>=50 && moneda->b50!=0){//$50
			meta=meta-50;
			moneda->b50--;
			cantidad->b50++;
		}else if(meta>=20 && moneda->b20!=0){//$20
			meta=meta-20;
			moneda->b20--;
			cantidad->b20++;
		}else if(meta>=10 && moneda->diezp!=0){//$10
			meta=meta-10;
			moneda->diezp--;
			cantidad->diezp++;
		}else if(meta>=5 && moneda->cincop!=0){//%5
			meta=meta-5;
			moneda->cincop--;
			cantidad->cincop++;
		}else if(meta>=2 && moneda->dosp!=0){//$2
			meta=meta-2;
			moneda->dosp--;
			cantidad->dosp++;
		}else if(moneda->peso!=0){//$1
			meta--;
			moneda->peso--;
			cantidad->peso++;
		}else{
			check=0;
			
			break;
		}
	}
	if(check==1)
		imprimir(cantidad);
	else
		puts("No hay suficiente dinero para regresar el cambio");
	

}

void imprimir(struct conteo*cantidad){
	if(cantidad->b1000!=0)
		printf("Se usaron %d billetes de $1000\n", cantidad->b1000);
	if(cantidad->b500!=0)
		printf("Se usaron %d billetes de $500\n", cantidad->b500);
	if(cantidad->b200!=0)
		printf("Se usaron %d billetes de $200\n", cantidad->b200);
	if(cantidad->b100!=0)
		printf("Se usaron %d billetes de $100\n", cantidad->b100);
	if(cantidad->b50!=0)
		printf("Se usaron %d billetes de $50\n", cantidad->b50);
	if(cantidad->b20!=0)
		printf("Se usaron %d billetes de $20\n", cantidad->b20);
	if(cantidad->diezp!=0)
		printf("Se usaron %d monedas de $10\n", cantidad->diezp);
	if(cantidad->cincop!=0)
		printf("Se usaron %d monedas de $5\n", cantidad->cincop);
	if(cantidad->dosp!=0)
		printf("Se usaron %d monedas de $2\n", cantidad->dosp);
	if(cantidad->peso!=0)
		printf("Se usaron %d monedas de $1\n", cantidad->peso);
}

