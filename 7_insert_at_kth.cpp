#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    public :
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
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
        mover = mover->next;
    }
    return head;
}

Node* insertkth(Node* head, int ele, int k){
    if(head == NULL){
        if(k == 1) return new Node(ele);
        else return NULL;
    }
    if(k == 1){
        Node* newNode = new Node(ele);
        newNode->next = head;
        head = newNode;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k - 1){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ele = 10;
    int k = 4;
    cout<<"Linked List before adding "<<ele<<" at "<<k<<" : ";
    Node* head = convertArr2LL(nums);
    print(head);
    cout<<endl;
    cout<<"Linked List after adding "<<ele<<" at "<<k<<" : ";
    head = insertkth(head, ele, k);
    print(head);
}