#include "exercises_mix.h"

/* Exercício de Recursão: 1 */
int soma_digitos(int numero){
	if(numero <= 0)
		return 0;
	return numero%10 + soma_digitos(numero/10);
}

/* Exercício de Recursão: 2 */
int super_digito(int numero){
	if(numero <= 0) return 0;
	else if(numero < 10){
		//printf("super_digito(%d) = %d\n", numero, numero);
		return numero;	
	}
	else{
		//printf("super_digito(%d) = ", numero);
		return super_digito(soma_digitos(numero));	
	} 
}

/* Exercício de Recursão: 3 */
int suc(int n){
	return n+1;
}

int pred(int n){
	return n-1;
}

/* 3.a */
int soma(int n1, int n2){
	if(n1 == 0) return n2;
	if(n2 == 0) return n1;
	return soma(suc(n1), pred(n2));
}

/* 3.b */
int subtracao(int n1, int n2){ // subtracao(n1, n2) = n1 - n2
	if(n1 == 0) return n1;
	if(n2 == 0) return n1;
	return subtracao(pred(n1), pred(n2));
}
/* 3.c */
int dobro(int n){
	if(n == 0) return 0;
	return suc(suc(dobro(pred(n))));
}
/* 3.d */
int metade_inteira(int n){
	if(n <= 1) return 0;
	return suc(metade_inteira(pred(pred(n))));
}
/* 3.e */
int minimo(int n1, int n2){
	if(n1 == 0) return n1;
	if(n2 == 0) return n2;
	if(n1 == n2) return n1;
	return suc(minimo(pred(n1), pred(n2)));
}
/* 3.f */
int maximo(int n1, int n2){
	if(n1 == 0) return n2;
	if(n2 == 0) return n1;
	if(n1 == n2) return n1;
	return suc(maximo(pred(n1), pred(n2)));
}
/* 3.g */
int eh_par(int n){
	if(n == 0) return 1;
	if(n == 1) return 0;
	return eh_par(pred(pred(n)));
}
/* 3.h */
int eh_impar(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return eh_impar(pred(pred(n)));
}
