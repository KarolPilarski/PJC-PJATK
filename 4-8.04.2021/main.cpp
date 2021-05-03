#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//1
template <typename T>
T add(T a,T b){
    return a+b;
}

template <typename T>
T sub(T a,T b){
    return a-b;
}

//2
template <typename T>
T* najw(T a[]){
    T* najw = a;
    for(int i=1;i<sizeof(a);i++){
        if(a+i>najw) najw=a+i;
    }
    return najw;
}

//3
void Shuffle(vector<int>& a){
    for(int i=0;i<a.size();i++){
        swap(a.at(rand()%a.size()),a.at(rand()%a.size()));
    }
}

//4
template<typename T>
vector<size_t> smallSum3 (vector<T>& a) {
    size_t NI1=0,NI2=1,NI3=2;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            for(int k=0;k<a.size();k++){
                if(i!=j&&i!=k&&j!=k&&(abs(a[NI1]+a[NI2]+a[NI3])>abs(a[i]+a[j]+a[k]))){
                    NI1=i;
                    NI2=j;
                    NI3=k;
                }
            }
        }
    }
    return vector<size_t> {NI1,NI2,NI3};
}

//5
template<typename T,typename FunType>
vector<T>filter(const vector<T>& v,FunType p){
    vector<T> wynik;
    for(int i=0;i<v.size();i++){
        if(p(v.at(i))) wynik.push_back(v.at(i));
    }
    return wynik;
}

template<typename T,typename FunType1, typename FunType2>
vector<T>transfilt(vector<T>& v, FunType1 t,FunType2 p){
    vector<T> wynik;
    for(int i=0;i<v.size();i++){
        v.at(i)=t(v.at(i));
        if(p(v.at(i))) wynik.push_back(v.at(i));
    }
    return wynik;
}

template<typename T>
void printVec(const vector<T>& v){
    cout<<"[ ";
    for(int i=0;i<v.size();i++) cout<<v.at(i)<<" ";
    cout<<"]"<<endl;
}

int main() {
    //1
    cout << add(5,10) << std::endl;

    //2
    int a[] = {2,4,10,3,2};
    cout << najw(a) << endl;

    //3
    vector<int>wektor;
    for(int i=1;i<=10;i++){
        wektor.push_back(i);
        cout<<wektor.at(i-1)<<" ";
    }
    cout<<endl;
    Shuffle(wektor);
    for(int i=0;i<10;i++){
        cout<<wektor.at(i)<<" ";
    }
    cout<<endl;

    //4
    vector<int>vec{2,-13,3,6,4,5,-14,1,-15};
    auto r=smallSum3(vec);

    printf("Sum=%d for elements " "vec[%u]=%d, a[%u]=%d,a[%u]=%d\n", vec[r[0]]+vec[r[1]]+vec[r[2]],vec[0], vec[r[0]],vec[1],vec[r[1]], r[2],vec[r[2]]);

    //5
    vector<int>v{1,-3,4,-2,6,-8,5};
    printVec(v);
    vector<int>l=filter(v,[](int a)->bool{return a%2==0;});
    printVec(l);
    vector<int>s=filter(v,[](int a)->bool{return a>0;});
    printVec(s);
    vector<double>w{1.5,-3.1,4.0,-2.0,6.3};
    printVec(w);double mn= -0.5, mx = 0.5;
    vector<double>d=transfilt(w,[](double a)->double{return sin(a);} ,[mn,mx](double a)->bool{return a>mn&&a<mx;});
    printVec(w);
    printVec(d);

    return 0;
}
