#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a,b,c;
    cout << "Podaj a" << endl;
    cin >> a;
    cout << "Podaj b" << endl;
    cin >> b;
    cout << "Podaj c" << endl;
    cin >> c;
    if((b*b-4*a*c)<0) cout << "Brak rozwiazan";
    else if ((b*b-4*a*c)==0) cout << "X: " << ((-b)/(2*a));
    else cout << "X1: " << ((-b-sqrt((b*b-4*a*c)))/(2*a)) << "   X2: " << ((-b+sqrt((b*b-4*a*c)))/(2*a)) << endl;
    return 0;
}
