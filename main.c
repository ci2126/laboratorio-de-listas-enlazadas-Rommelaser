///////////////////////////////////////////// Laboratorio 4 Listas Enlazadas /////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
/// Estudiante: Rommel A. J. Contreras F. // Carnet: 14-10242//  CI: V26766770  01/03/2019/ // 
/////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct nodo{
    int val;
    struct nodo* sig;
}Nodo;

typedef Nodo* Lista;

Lista newList(){
    return NULL;
}

// Inserta en la cabeza de la lista

void inserta(int x, Lista *L){
    Nodo *p= malloc(sizeof(Nodo));
    p->val = x;
    p->sig = *L;
    *L = p;
}

int esVacia(Lista L){
    return L== NULL;
}

// pre: L no es Vacia
int firstInList(Lista L){
    return L-> val;
}
//Booleano 1 si x está, o si No
int estaEn(int x, Lista L){
    Nodo*p=L;
    while(p != NULL && p-> val != x) p= p->sig;
        return p!=NULL;
}

// Escribo la lista L de nombre name entre dos corchetes
void writeList(Lista L, char name[]){
    printf("\n%s = [",name);
    if(L==NULL){
        printf("].");
    }
    else{
        while(L->sig!= NULL){
            printf("%d, ", L->val);
            L=L->sig;
        }

        printf("%d].", L->val);
    }

       
}



// Programa de prueba
/*
int main(){
    printf("\nProbando Lista.. :");
    Lista L=newList(), L1=newList();
    writeList(L,"L");
    inserta(4,&L);
    inserta(9,&L);
    inserta(5,&L);
    writeList(L,"L");
    printf("\nA la cabeza de L esta: %d", firstInList(L));
    if(esVacia(L1)) printf("\nL1 es Vacia,"); else printf("\nL1 NO es vacia");
    int x= 7; char s[]= "L";
    if(estaEn(x,L)) printf("\n%d esta en %s. ",x, s );
    else printf("\n%d No esta en %s. ",x, s );

    return 0;

}

*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Agregue otras funciones No Recursivas
// Lo siguiente será agregar algunas funciones recursivas
// complete y pruebe cada una de estas funciones.

// insete a x al final de la Lista L-- spend
void insertaT(int x, Lista *L){
    if(*L != NULL){
    	Nodo*p=malloc(sizeof(Nodo));
    	p=*L;
    	while(p->sig != NULL) p=p->sig;
    	p->sig=malloc(sizeof(Nodo));
    	p=p->sig; p->sig=NULL; p->val=x;
    	p->sig=malloc(sizeof(Nodo));
    	p->sig=NULL;

    }
    else{
    	*L=malloc(sizeof(Nodo));
    	(*L)->val=x;
    	(*L)->sig= NULL;
    }
}

// Elimina la primera ocurrencia de x de la lista L
void elimina(int x, Lista * L){
	Nodo *p = *L, *q;
	if(p != NULL){
		if(p->val == x){
			*L= p->sig;
			free(p);
		}else{
			while(p->sig!= NULL && (p->sig)->val != x) p=p->sig;
			if(p->sig != NULL){
				if(p->sig != NULL){
					q=p->sig;
					p->sig = q->sig;
					free(q);
				}
			}
		}
	}
}
// L= [...] => k=[...]
void clona(Lista L, Lista * N){
	*N = NULL;
	Nodo *q;
	if(L!=NULL){
		*N=L; q=malloc(sizeof(Nodo));
		q->val= (*N)->val;q->sig=(*N)->sig;
		*N=q;

		while(L->sig != NULL){
			q->sig= malloc(sizeof(Nodo));
			(q->sig)->val=(L->sig)->val;
			q=q->sig; L=L->sig;
		}
			q->sig=NULL;// porque El ultimo elemento de la lista debe apuntar a NULL cosa que no se considera en el ciclo...
		}
}



// Concatena las listas L y K. L =L:K =NULL;
void concat(Lista *L, Lista *K){
	if(*L==NULL)*L=*K;
	else{
		Nodo*p =*L;
		while(p->sig!=NULL)p=p->sig;
		p->sig=*K;
	}
	*K=NULL;
}
/*
int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList(), L1=newList();
    writeList(L,"L");
    inserta(4,&L);
    inserta(9,&L);
    inserta(5,&L);
    writeList(L,"L");
    inserta(6,&L1);
    inserta(6,&L1);
    inserta(6,&L1);
    writeList(L1,"L1");
    insertaT(8,&L);
    writeList(L,"L");
    elimina(9,&L);
    writeList(L,"L");
    Lista K=newList();
    clona(L,&K);
    writeList(K,"k");
   	concat(&L1,&K);
    writeList(L1,"L");
    writeList(K,"K");
    return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int sizeR(Lista L){
	if(L==NULL) return 0;
	else return 1+ sizeR(L->sig);

}

// Recursiva...
int estaEnR(int x, Lista L){
	if(L == NULL) return 0;
	else if(L->val == x) return 1;
	return estaEnR(x,L->sig);
}

// Inserta a c al final de la Lista L --apend
void insertaTR(int x, Lista *L){
	if(*L == NULL){
			Nodo *p = malloc(sizeof(Nodo));
			p->val = x;
			p->sig=NULL;
			*L=p;
		}

		else insertaTR(x,&((*L)->sig));
}


// Elimina la primera ocurrencia de x en la Lista *L
void eliminaR(int x, Lista *L){
	if(*L != NULL){
		if((*L)->val == x){
			Nodo *p = *L;
			*L = (*L)->sig;
			free(p);
		}
		else eliminaR(x,&((*L)->sig));
	} // else skip
}

// Extras

int sizeI(Lista L){
	int r=0;
	while(L->sig!=NULL){
		L=L->sig; r=r++;
	}
	return r; // supongo que el NULL no se toma en cuenta en el tamano, pero si se tomara en cuenta r++;
}
/*
int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList();Lista M=newList();
    inserta(1,&L);
    inserta(8,&L);
    inserta(9,&L);
    inserta(9,&M);
    inserta(8,&M);
    inserta(1,&M);
    inserta(0,&M);
    writeList(L,"L");
    writeList(L,"M");
    int k=sizeI(L);
    int x=0;
    printf("\n size of L = %d\n ",k);
    int p=sizeR(M);
    printf("\n size of L = %d\n ",p);
    if(estaEnR(x,M)==1)
		printf("\n el numero %d se encuentra en la lista M",x);
    insertaTR(4,&M);
    writeList(M,"M");
    eliminaR(1,&M);
    writeList(M,"M");
    return 0;
   
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ejercicios

/*
	Mezcla de Listas. Escriba una fucion que resiba dos listas ordenadas de forma no decreciente y retorne
	una nueva lista ordenada de forma no decrecinte que contenga exactamente todos los elementos de las dos 
	listas que recibe Lista merge(const Lista L, const Lista M);
*/

Lista merge(const Lista L, const Lista M){
	Lista T; Nodo*q,*w,*e;
	if(L!=NULL && M!= NULL){
		Nodo *q= malloc(sizeof(Nodo));T=q;w=L;e=M;
		while(w !=NULL && e !=NULL ){
			if((w->val)<=(e->val)){
				q->val=w->val;
				if(w->sig!=NULL){
					q->sig=malloc(sizeof(Nodo));
					q=q->sig; 
				}
				w=w->sig;
			}
			else{
				q->val=e->val; 
				if(e->sig!=NULL){
					q->sig=malloc(sizeof(Nodo));
					q=q->sig; 
				}
				e=e->sig;
			}
		}
		if(w !=NULL || e !=NULL ){
			q->sig=malloc(sizeof(Nodo));
			q=q->sig; 
		}

		while(w != NULL){
			q->val=w->val;
			if(w->sig!=NULL){
				q->sig=malloc(sizeof(Nodo));
				q=q->sig; 
			}
			w=w->sig;
		}
		while(e != NULL){
			q->val=e->val;
			if(e->sig!=NULL){
				q->sig=malloc(sizeof(Nodo));
				q=q->sig; 
			}
			e=e->sig;
		}
		q->sig = NULL;

	}
	 free(w);free(e);
	return T;
}

int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList(), L1=newList();
    writeList(L,"L");
    inserta(8,&L);
    inserta(5,&L);
    inserta(1,&L);
    writeList(L,"L");
    inserta(9,&L1);
    inserta(7,&L1);
    writeList(L1,"L1");
    Lista T=merge(L,L1);
    writeList(T,"T");
    return	0;
}

/*
	Insercion Ordenada. Escriba una funcion que reciba un entero x y una lista ordenada L e inserte el ele-
	mento xe en la lista L de tal dorma que la lista dinal este ordenada. void insertOrd(int x, cons Lista L);

*/
void insertOrdec(int x, Lista * L){
	Nodo *i=*L, *q=malloc(sizeof(Nodo));
	q->val = x; q->sig =NULL;
	if(L==NULL)*L=q;
	else{
		while(i->sig!=NULL && q->val<(i->sig)->val){
			i=i->sig;
		}
		q->sig=i->sig;
		i->sig=q;
	}
}

void insertOrdcre(int x, Lista * L){
	Nodo *i=*L, *q=malloc(sizeof(Nodo));
	q->val = x; q->sig =NULL;
	if(L==NULL)*L=q;
	else{
		while(i->sig!=NULL && q->val>(i->sig)->val){
			i=i->sig;
		}
		q->sig=i->sig;
		i->sig=q;
	}
}
/*
int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList();Lista M=newList();
    inserta(1,&L);
    inserta(8,&L);
    inserta(9,&L);
    inserta(9,&M);
    inserta(8,&M);
    inserta(1,&M);
    insertOrdec(4,&L);
    insertOrdcre(4,&M);
    writeList(L,"L");
    writeList(M,"M");
    return 0;
}
*/

/* 
	Halla el maximo de una lista no vacia. Debe retornar un apuntador al Nodo que contiene la primera ocurrencia
	del maximo
*/

Nodo* maxList(Lista L){
	Nodo*i=L, *j=L->sig, *k;
	if(L== NULL) return NULL;
	else{
		while(j->sig!= NULL){
			if(i->val>(j->val))k=i;
			else k=j;
			i=i->sig;
			j=j->sig;
		}
		return k;
	}
}
/*
int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList();
    inserta(1,&L);
    inserta(9,&L);
    inserta(8,&L);
    writeList(L,"L");
    Lista p= maxList(L);
    writeList(p,"p");
    return 0;
}
*/
/*
	Hallar la posicion de un elemento x dentro de una lista. Debe retornar un apuntador NULO si no se
	Encuentra, de lo contrario debe retornar la direccion de memoria del nodo donde se encuentra.

*/
/*
Nodo* findinlist(int x, Lista L){
	Nodo *q=L;
	if(L==NULL) return q;
	else{	

		while(q->sig!=NULL && q->val != x){
			q=q->sig;
		}
		if(q->val!=x) return NULL;
		else return	q;
	}

}

int main(){
	printf("\nProbando Lista.. :");
    Lista L=newList();
    inserta(1,&L);
    inserta(5,&L);
    inserta(8,&L);
    writeList(L,"L");
    Lista p=findinlist(5,L);
    writeList(p,"p");
    return 0;
}
*/