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
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int middle = (cnt / 2) + 1;
    temp = head;
    while(temp != NULL){
        middle--;
        if(middle == 0) break;
        temp = temp->next;
    }
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(nums);
    cout<<"LL : ";
    print(head);
    cout<<endl;

    cout<<"Middle of LL : ";
    Node* middle = bruteForce(head);
    cout<<middle->data;
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"Middle of LL : ";
    middle = optimal(head);
    cout<<middle->data;
    cout<<endl;
}