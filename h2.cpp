#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,1,8,3,12,16,19,7,5,14,24,24,17,9};
    int q=17;
    int arr2[q]={0};
    for (int i=0; i<14; i++){
        int temp;
        for (int j=0; j<17; j++){
            temp = (arr[i] + j) % q;
            if (arr2[temp]==0){
                arr2[temp] = arr[i];
                break;
            }
        }
    }
    for (int i=0; i<17; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}