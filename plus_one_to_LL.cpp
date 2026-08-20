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

Node* reverse(Node* head){
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

Node* bruteForce(Node* head){
    if(head == NULL) return head;
    Node* newHead = reverse(head);
    Node* temp = newHead;
    int carr = 1;
    while(temp != NULL){
        temp->data += 1;
        if(temp->data < 10){
            carr = 0;
            break;
        } else {
            temp->data = 0;
            // carr = 1;
        }
        temp = temp->next;
    }
    if(carr == 1){
        Node* newNode = new Node(1);
        head = reverse(newHead);
        newNode->next = head;
        return newNode;
    }
    head = reverse(newHead);
    return head;
}

int helper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carr = helper(temp->next);
    temp->data += carr;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* optimal(Node* head){
    int carr = helper(head);
    if(carr == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    } 
    return head;
}


int main(){
    vector<int> nums = {1, 2, 5};
    Node* head = convertArr2LL(nums);
    cout<<"LL before adding one : ";
    print(head);
    cout<<endl;

    cout<<"LL after adding one (BruteForce) : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL after adding one (optimal) : ";
    head = optimal(head);
    print(head);
}