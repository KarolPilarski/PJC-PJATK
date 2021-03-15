#include <iostream>

using namespace std;

int main() {
    int najwliczba=0,najwsuma=0,obecnasuma,liczba,obecnaliczba=1;

    while(obecnaliczba!=0){
        obecnasuma=0;
        cout <<"enter a natural number (0 if done): ";
        cin>>liczba;
        obecnaliczba=liczba;
        while(liczba>0){
            obecnasuma+=(liczba%10);
            liczba=liczba/10;
        }
        if(obecnasuma>najwsuma){
            najwliczba=obecnaliczba;
            najwsuma=obecnasuma;
        }
    }
    cout << "Max sum of digits was "<< najwsuma << " for " << najwliczba;
    return 0;
}
