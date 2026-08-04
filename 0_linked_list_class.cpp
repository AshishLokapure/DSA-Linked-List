#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    public :
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    Node *y = new Node(2, nullptr);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<y->next<<endl<<endl;

    Node p = Node(2, nullptr);
    cout<<p.data<<endl;
    cout<<p.next<<endl;
}