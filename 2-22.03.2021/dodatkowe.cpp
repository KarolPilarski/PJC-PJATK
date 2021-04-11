#include <iostream>

using namespace std;

void ord3(double& a, double& b, double& c){
	double tmp;
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
}
void ord3(double* a, double* b, double* c){
	if(*a>*b) swap(*a,*b);
	if(*b>*c) swap(*b,*c);
	if(*a>*b) swap(*a,*b);
}

void getMinMax(const double &a, const double& b,const double& c,const double*& pMin, const double*& pMax){
	pMin=&a;
	pMax=&a;
	
	if(b>*pMax) pMax=&b;
	if(b<*pMin) pMin=&b;
	
	if(c>*pMax) pMax=&c;
	if(c<*pMin) pMin=&c;
}

void getMinMax(const double *a, const double* b,const double* c,const double** pMin, const double** pMax){
	pMin=&a;
	pMax=&a;
	
	if(*b>**pMax) pMax=&b;
	if(*b<**pMin) pMin=&b;
	
	if(*c>**pMax) pMax=&c;
	if(*c<**pMin) pMin=&c;
}

void printOrd(const double* a, const double* b,const double* c){
cout << *a << " " << *b << " " << *c << endl;
}

void printMinMax(const double* pmn, const double* pmx){
cout << "Min = " << *pmn << "; "<< "Max = " << *pmx <<endl;}

int main(){
double a, b, c;
const double *pMin, *pMax;
a = 2; b = 1; c = 3;
ord3(a,b,c);
printOrd(&a, &b, &c);
a = 3; 
b = 2; 
c = 1;
ord3(&a,&b,&c);
printOrd(&a, &b, &c);
a = -1; 
b = -1; 
c = 1;
ord3(&a,&b,&c);
printOrd(&a, &b, &c);
a = 2;
b = 3;
c = 1;
getMinMax(a,b,c,pMin,pMax);
printMinMax(pMin, pMax);
a = 3; 
b = 1; 
c = 2;
getMinMax(&a,&b,&c,&pMin,&pMax);
printMinMax(pMin, pMax);
a = 3; 
b = 3; 
c = -1;
getMinMax(&a,&b,&c,&pMin,&pMax);
printMinMax(pMin, pMax);
}


