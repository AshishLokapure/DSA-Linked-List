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

Node* bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    vector<int> nums;
    while(temp != NULL && temp->next != NULL){
        nums.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) nums.push_back(temp->data);

    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        nums.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) nums.push_back(temp->data);
    temp = head;
    for(int i = 0; i < nums.size(); i++){
        temp->data = nums[i];
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(nums);
    cout<<"LL Before : ";
    print(head);
    cout<<endl;

    cout<<"LL After Brute Force : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL After Optimal : ";
    head = optimal(head);
    print(head);
}