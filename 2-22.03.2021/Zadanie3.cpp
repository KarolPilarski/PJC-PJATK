#include <iostream>

using namespace std;

void histo(int arr[], size_t size) {
    int najw = 0;
    for(int i=0;i<size;i++) if(arr[i]>najw) najw=arr[i];

    for(int i=najw-1;i>=0;i--){
        for(int j=0;j<size;j++){
            if(i<arr[j]) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int arr[]{2,1,0,7,1,9};
    size_t size = sizeof(arr)/sizeof(*arr);
    histo(arr,size);
}
