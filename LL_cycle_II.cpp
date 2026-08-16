// Q2. Starting of Loop?

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

Node* convertArr2LL(vector<int>& nums){
    if(nums.empty())
        return NULL;
    Node* head = new Node(nums[0]);
    Node* mover = head;
    Node* connector = NULL;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
        if(nums[i] == 5)
            connector = temp;
    }
    mover->next = connector;
    return head;
}

Node* bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = convertArr2LL(nums);
    cout<<"LL : ";
    cout<<endl;

    cout<<"Starting of Loop brute force : ";
    Node* ans = bruteForce(head);
    cout<<"data : "<<ans->data<<" next address : "<<ans->next;
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"Starting of Loop optimal : ";
    ans = optimal(head);
    cout<<"data : "<<ans->data<<" next address : "<<ans->next;
    cout<<endl;
}