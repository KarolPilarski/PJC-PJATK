#include <iostream>

using namespace std;

void clean(char* n) {
    int size=0;
    while(n[size]!='\0') size++;
    
    while(n[size-1]==' '){
    	n[size-1]=='\0';
    	size--;
		
		if(size==0) return;
	}
	
	while(n[0]==' '){
    	for(int i=0;i<(size-1);i++){
    		n[i]=n[i+1];
		}
		n[size-1]='\0';
		size--;
	}
	
	for(int i=0;i<(size-1);i++){
    	if(n[i]==' '&&n[i+1]==' '){
    		for(int j=i;j<(size-1);j++){
    			n[j]=n[j+1];
			}
			i--;
			n[size-1]='\0';
			size--;
		}
	}
}

int main() {
    char n1[] = "a   bc   def  ghijk ";
    cout << "Przed: >" << n1 << "<" << endl;
    clean(n1);
    cout << " Po: >" << n1 << "<" << endl;
    char n2[] = " a  bc  def    ghijk";
    cout << "Przed: >" << n2 << "<" << endl;
    clean(n2);
    cout << " Po: >" << n2 << "<" << endl;
    char n3[] = "    ";
    cout << "Przed: >" << n3 << "<" << endl;
    clean(n3);
    cout << " Po: >" << n3 << "<" << endl;
}
