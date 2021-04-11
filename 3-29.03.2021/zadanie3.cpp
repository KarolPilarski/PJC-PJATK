#include <iostream>

using namespace std;

void wypisz_wyniki(const char* n1, const char* n2);

int main(){
char nap1[] = "Jakis Dlugi Napis";
char nap2[] = "Zupelnie inny napis";
wypisz_wyniki(nap1,nap2);
}

void wypisz_wyniki(const char* n1, const char* n2){

int size1=0,size2=0;

while(n1[size1]!='\0') size1++;
while(n2[size2]!='\0') size2++;

for(char i='a';i<='z';i++){
	bool j1=false,j2=false;
	for(int j=0;j<size1;j++) if(tolower(n1[j])==i) j1=true;
	for(int j=0;j<size2;j++) if(tolower(n2[j])==i) j2=true;
	if(j1&&j2) cout<<i<<" ";
}

cout<<endl;

for(int i=0;i<(size1-1);i++){
	bool j3=true;
	for(int j=0;j<(size2-1);j++) if(tolower(n1[i])==tolower(n2[j]))	j3=false;
	if(j3) cout<<n1[i]<<" ";	
}
}
