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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = convertArr2LL(nums);
    cout<<"List before Deteting tail : ";
    print(head);
    cout<<endl<<"List after Deleting tail : ";
    Node* newHead = deleteTail(head);
    print(head);
}