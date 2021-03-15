#include <iostream>

using namespace std;

int main() {
    double wzrost,waga;
    cout << "Podaj wzrost(w metrach)" << endl;
    cin >> wzrost;
    cout << "Podaj wage(w kilogramach)" << endl;
    cin >> waga;
    cout << "BMI: " <<waga/(wzrost*wzrost)<<endl;
    return 0;
}
