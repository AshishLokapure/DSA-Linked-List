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

Node* bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    vector<int> nums;
    while(temp != NULL){
        nums.push_back(temp->data);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end());
    temp = head;
    int i = 0;
    while(temp != NULL){
        temp->data = nums[i++];
        temp = temp->next;
    }
    return head;
}

Node* merge(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 == NULL && l2 == NULL) return NULL;
    Node* t1 = l1;
    Node* t2 = l2;
    Node* temp = new Node(-1);
    Node* head = temp;
    while(t1 != NULL && t2 != NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return head->next;
}

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mid = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next = NULL;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge(leftHead, rightHead);
}

Node* optimal(Node* head){
    head = mergeSort(head);
    return head;
}

int main(){
    vector<int> nums = {5, 3, 7, 2, 7, 8, 9, 1, 2, 10};
    Node* head = convertArr2LL(nums);
    cout<<"LL Before sort : ";
    print(head);
    cout<<endl;

    cout<<"LL After sort (BruteForce) : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL After Sort (Optimal) : ";
    head = optimal(head);
    print(head);
}