#include <iostream>

using namespace std;

bool isPrime(int n){
    for(int i=(n-1);i>1;i--)
        if(n%i==0) return false;
        return true;
}

void printDivisors(int n){
    for(int i=n;i>=1;i--)
        if(n%i==0) cout<<i<<" ";
        cout<<endl;
}

int numDivisors(int n){
    int count=0;
    for(int i=n;i>=1;i--)
        if(n%i==0) count++;
    return count;
}

int gcd(int m, int n){
    while(m!=n){
        if(m>n) m=m-n;
        else n=n-m;
    }
    return m;
}

int phi(int n){
    int count=0;
    for(int i=n;i>=1;i--)
        if(gcd(n,i)==1) count++;
        return count;
}

int main() {
    cout << isPrime(5)<<endl;
    printDivisors(65);
    cout << numDivisors(65)<<endl;
    cout << gcd(65,125)<<endl;
    cout << phi(65)<<endl;
    return 0;
}
