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
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    return prev;
}

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(nums);
    cout<<"LL Before reverse: ";
    print(head);
    cout<<endl;

    cout<<"LL After reverse : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL After reverse : ";
    head = optimal(head);
    print(head);
    cout<<endl;

    cout<<"Reverse Using Recursion : ";
    head = convertArr2LL(nums);
    head = reverse(head);
    print(head);
}