#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    public :
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* convertArr2LL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* insertHead(Node* head, int ele){
    if(head == NULL) return new Node(ele);
    Node* newNode = new Node(ele);
    newNode->next = head;
    head = newNode;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ele = 10;
    cout<<"Linked List before adding "<<ele<<" : ";
    Node* head = convertArr2LL(nums);
    print(head);
    cout<<endl;
    cout<<"Linked List after adding "<<ele<<" : ";
    head = insertHead(head, ele);
    print(head);
}