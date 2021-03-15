#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cout << "Enter three non-negative numbers: " << endl;
    cin >> a >> b >> c;
    int najw=(a>b)?((c>a)?c:a):((c>b)?c:b);
    for(int i=najw;i>0;i--){
        if(i>a) cout <<" ";
        else cout <<"*";

        if(i>b) cout <<" ";
        else cout <<"*";

        if(i>c) cout <<" ";
        else cout <<"*";

        cout << endl;
    }
    return 0;
}
