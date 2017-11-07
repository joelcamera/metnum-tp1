#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>


Federico Javier Pousa

//////////////////////////////////////////////////////////////
float mirand(float hasta){
	return (hasta * (rand() / (RAND_MAX + 1.0)));
}
//////////////////////////////////////////////////////////////

int nums = 100000000;
float numeros[100000000];

int main(){
	
	srand(314);
	for(int i=0;i<nums;i++){
		//~ numeros[i] = pow(2,-20);
		numeros[i] = pow(2,-rand()%10);
	}
	numeros[50] = 16.;
	 
	float suma = 0.0;
	float kahan = 0.0;
	float c = 0.0;
	for(int i=0;i<nums;i++){
		//~ printf("%.10lf\n", numeros[i]);
		suma += numeros[i];
		float y = numeros[i]-c;
		float t = kahan + y;
		c = (t - kahan) - y;
		kahan = t;
	}
	
	
	
	
	
	sort(numeros, numeros+nums);
	float suma2 = 0.0;
	float suma3 = 0.0;
	for(int i=0;i<nums;i++){
		suma2+=numeros[i];
		suma3+=numeros[nums-1-i];
	}
	
	
	printf("Como viene: %.15lf\nOrden Ascendente: %.15lf\nOrden Descendente: %.15lf\nSUPER KAHAN!: %.15lf\n", suma, suma2, suma3, kahan);
	 
	return 0;
}
