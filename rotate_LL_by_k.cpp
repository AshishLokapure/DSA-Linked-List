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

Node* findNewTail(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* optimal(Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }
    k = k % len;
    if(k == 0) return head;
    tail->next = head;
    Node* newTail = findNewTail(head, len - k);
    head = newTail->next;
    newTail->next = NULL;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 5;
    Node* head = convertArr2LL(nums);
    cout<<"LL before rotate : ";
    print(head);
    cout<<endl;

    cout<<"LL after rotate "<<k<<" places : ";
    head = optimal(head, k);
    print(head);
}