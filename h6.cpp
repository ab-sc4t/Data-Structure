#include<iostream>
using namespace std;

int main(){
    int arr[]={47,14,91,25};
    int arr2[11]={0};
    int len = sizeof(arr)/sizeof(int);
    for (int i=0; i<4; i++){
        int temp;
        for (int j=0; j<11; j++){
            temp = ((arr[i]%11) + j*(7-(arr[i]%7)))%11;
            if (arr2[temp]==0){
                arr2[temp] = arr[i];
                break;
            }
        }
    }
    for (int x=0; x<11; x++){
        cout << arr2[x] << " ";
    }
    return 0;
}