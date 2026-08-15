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

Node* bruteForce(Node* head, int n){
    if(head == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    if(cnt == n){
        Node* del = head;
        head = head->next;
        delete(del);
        return head;
    }
    int res = cnt - n;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0) break;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete(delNode);
    return head;
}

Node* optimal(Node* head, int n){
    if(head == NULL) return NULL;
    Node* fast = head;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        Node* del = head;
        head = head->next;
        delete(del);
        return head;
    }
    Node* slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 3;
    Node* head = convertArr2LL(nums);
    cout<<"LL Before Deleting : ";
    print(head);
    cout<<endl;

    cout<<"LL After deleting "<<n<<"th node : ";
    head = bruteForce(head, n);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL After deleting "<<n<<"th node : ";
    head = optimal(head, n);
    print(head);
}