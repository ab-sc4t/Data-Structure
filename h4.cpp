//CHAINING

#include<iostream>
using namespace std;

class Node2{
    public:
        int data;
        Node2 * rp;
        Node2(int d){
            data = d;
            rp = NULL;
        }
};

class Node1{
    public:
        int listno;
        Node2 * rp;
        Node1 * dp;
};

int main(){
    Node1 * start = NULL, *temp, *head;
    Node2 * h, *t;

    start = new Node1;
    start->listno = 0;
    start->rp = NULL;
    start->dp = NULL;
    head = start;

    for (int i=1; i<11; i++){
        temp = new Node1;
        temp->listno = i;
        temp->rp = NULL;
        temp->dp = NULL;
        if (start == NULL){
            start = temp = head;
        }
        else{
            head->dp = temp;
            head = temp;
        }
    }
    int arr[]={2,24,36,29,35,48};
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int j=0; j<len; j++){
        int tt = arr[j] % 11;
        temp = start;
        while(temp->listno != tt){
            temp = temp->dp;
        }
        t = new Node2(arr[j]);
        t->rp = NULL;
        if (temp->rp == NULL){
            temp->rp = h = t;
        }
        else{
            h->rp = t;
            h = t;
        }
    }
    temp = start;
    while(temp!=NULL){
        int c=0;
        cout << temp->listno<< " : ";
        t = temp->rp;
        while(t!=NULL){
            cout << t->data << " ";
            t = t->rp;
            c++;
        }
        cout << "\n";
        temp = temp->dp;
    }
    return 0;
}