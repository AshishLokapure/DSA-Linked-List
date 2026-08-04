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

int lengthOfLL(Node* head){
    Node* ptr = head;
    int cnt = 0;
    while(ptr){
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}
int main(){
    vector<int> nums = {2, 4, 6, 7};
    Node* head = convertArr2LL(nums);
    cout<<"Length : "<<lengthOfLL(head);
}