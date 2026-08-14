#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    public : 
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
}; 

void print(Node* head){
    Node* temp = head;
    while(temp){
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
        mover = temp;
    }
    return head;
}

Node* addTwoNumber(Node* head1, Node* head2){
    Node* l1 = head1;
    Node* l2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL){
        int sum = carry;
        if(l1) sum += l1->data;
        if(l2) sum += l2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        temp->next = newNode;
        temp = temp->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    vector<int> List1 = {3, 5};
    vector<int> List2 = {4, 5, 9, 9};
    Node* head1 = convertArr2LL(List1);
    Node* head2 = convertArr2LL(List2);
    cout<<"List 1 : ";
    print(head1);
    cout<<endl;
    cout<<"List 2 : ";
    print(head2);
    cout<<endl;

    cout<<"Addition : ";
    Node* head = addTwoNumber(head1, head2);
    print(head);
}