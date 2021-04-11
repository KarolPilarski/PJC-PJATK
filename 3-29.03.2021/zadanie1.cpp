#include <iostream>

using namespace std;

int main() {
    int size=4;
    int tab[size][size];

    for(int i=0;i<size;i++){
        if(i==0) tab[0][i]=1;
        else tab[0][i]=0;
    }
    for(int i=1;i<size;i++){
        tab[i][0]=1;
        for(int j=1;j<size;j++){
            tab[i][j]=tab[i-1][j]+tab[i-1][j-1];
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
