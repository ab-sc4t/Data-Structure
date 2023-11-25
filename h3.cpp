#include<iostream>
using namespace std;

int main(){
    int arr[] = {89,18,49,58,9};
    int q=10;
    int arr2[q]={0};
    for (int i=0; i<5; i++){
        int temp;
        for (int j=0; j<10; j++){
            temp = (arr[i] + j*j) % q;
            if (arr2[temp]==0){
                arr2[temp] = arr[i];
                break;
            }
        }
    }
    for (int i=0; i<10; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}