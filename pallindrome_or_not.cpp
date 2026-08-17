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

bool bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return true;
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

Node* reverse(Node* temp){
    Node* prev = NULL;
    while(temp != NULL){
        Node* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    return prev;
}

bool optimal(Node* head){
    if(head == NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverse(slow->next);
    Node* low = head;
    Node* high = newHead;
    while(high != NULL){
        if(low->data != high->data){
            reverse(newHead);
            return false;
        }
        low = low->next;
        high = high->next;
    }
    reverse(newHead);
    return true;
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 2, 1};
    Node* head = convertArr2LL(nums);
    cout<<"LL is : ";
    print(head);
    cout<<endl;

    cout<<"Pallindrome or Not (bruteForce): ";
    bool ans = bruteForce(head);
    cout<<ans<<endl;

    head = convertArr2LL(nums);
    cout<<"Pallindrome or Not (optimal): ";
    ans = optimal(head);
    cout<<ans<<endl;

}