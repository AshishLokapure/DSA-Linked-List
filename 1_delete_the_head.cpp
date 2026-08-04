#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = convertArr2LL(nums);
    cout<<"List before Deleting head : ";
    print(head);
    cout<<endl<<"List after Deleting head : ";
    Node* newHead = deleteHead(head);
    print(newHead);
}