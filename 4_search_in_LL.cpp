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

bool searchInLL(Node* head, int target){
    Node* temp = head;
    while(temp){
        if(temp->data == target) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> nums = {2, 4, 6, 7};
    Node* head = convertArr2LL(nums);
    int target = 6;
    if(searchInLL(head, target)){
        cout<<"Element Present";
    } else {
        cout<<"Element Not Present";
    }
}