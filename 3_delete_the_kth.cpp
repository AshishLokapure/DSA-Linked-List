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

Node* deleteKth(Node* head, int k){
    if(head == NULL) return head;
    Node* temp = head;
    if(k == 1){
        head = head->next;
        free(temp);
        return head;
    }
    Node* prev = NULL;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k){
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
    int k = 5;
    Node* head = convertArr2LL(nums);
    cout<<"Linked List before deleteting "<<k<<" element : ";
    print(head);
    cout<<endl;
    cout<<"Linked List after deleteting "<<k<<" element : ";
    Node* newHead = deleteKth(head, k);
    print(newHead);
}
