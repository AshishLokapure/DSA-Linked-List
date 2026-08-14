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
    if(nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        } else if(cnt1){
            temp->data = 1;
            cnt1--;
        } else if(cnt2){
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* head0 = new Node(-1);
    Node* head1 = new Node(-1);
    Node* head2 = new Node(-1);
    Node* zero = head0;
    Node* one = head1;
    Node* two = head2;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1){
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (head1->next) ? (head1->next) : head2->next;
    one->next = head2->next;
    two->next = NULL;
    Node* result = head0->next;
    delete head0;
    delete head1;
    delete head2;
    return result;
}

int main(){
    vector<int> nums = {2, 1, 0, 0, 0, 2, 1, 0, 2, 1, 1, 1, 0, 2};
    Node* head = convertArr2LL(nums);
    cout<<"LL Before : ";
    print(head);
    cout<<endl;

    cout<<"LL After sort Brute Force : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL After sort Optimal : ";
    head = optimal(head);
    print(head);
}