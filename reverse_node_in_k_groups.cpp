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

void reverse(Node* temp){
    Node* prev = NULL;
    while(temp != NULL){
        Node* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
}

Node* findKthNode(Node* temp, int k){
    k -= 1;
    Node* t1 = temp;
    while(t1 != NULL && k > 0){
        k--;
        t1 = t1->next;
    }
    return t1;
}

Node* optimal(Node* head, int k){
    Node* temp = head;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if(head == temp) head = kthNode;
        else prevNode->next = kthNode;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;
    Node* head = convertArr2LL(nums);
    cout<<"LL before reverse : ";
    print(head);
    cout<<endl;

    cout<<"LL after reverse k size grp : ";
    head = optimal(head, k);
    print(head);
}