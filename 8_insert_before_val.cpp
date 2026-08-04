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
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
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

Node* insertBeforeVal(Node* head, int ele, int val){
    if(head == NULL) return head;
    if(head->data == val) return new Node(ele, head);
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ele = 10;
    int val = 4;
    cout<<"Linked List before adding "<<ele<<" before "<<val<<" : ";
    Node* head = convertArr2LL(nums);
    print(head);
    cout<<endl;
    cout<<"Linked List after adding "<<ele<<" before "<<val<<" : ";
    head = insertBeforeVal(head, ele, val);
    print(head);
}