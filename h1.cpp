#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,1,8,3,6,9,5};
    int q=11;
    int arr2[11]={0};
    for (int i=0; i<11; i++){
        int temp;
        temp = arr[i] % q;
        arr2[temp] = arr[i];
    }
    for (int i=0; i<11; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}