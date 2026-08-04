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
        mover = mover->next;
    } 
    return head;
}

Node* deleteKth(Node* head, int val){
    if(head == NULL) return head;
    Node* temp = head;
    if(head->data == val){
        head = head->next;
        free(temp);
        return head;
    }
    Node* prev = NULL;
    while(temp){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 5;
    Node* head = convertArr2LL(nums);
    cout<<"Linked List before deleteting "<<val<<" : ";
    print(head);
    cout<<endl;
    cout<<"Linked List after deleteting "<<val<<" : ";
    Node* newHead = deleteKth(head, val);
    print(newHead);
}
