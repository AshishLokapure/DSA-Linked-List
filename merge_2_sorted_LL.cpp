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

// N = n1 + n2
// TC -> 0(N) + 0(N log N) + 0(N)
// SC -> 0(N) + 0(N)
Node* bruteForce(Node* l1, Node* l2){
    if(l2 == NULL) return l1;
    if(l1 == NULL) return l2;
    if(l1 == NULL && l2 == NULL) return NULL;
    Node* temp = l1;
    vector<int> nums;
    while(temp != NULL){
        nums.push_back(temp->data);
        temp = temp->next;
    }
    temp = l2;
    while(temp != NULL){
        nums.push_back(temp->data);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end());
    return convertArr2LL(nums);
}

// TC -> 0(N)
// SC -> 0(N)
Node* better(Node* l1, Node* l2){
    if(l2 == NULL) return l1;
    if(l1 == NULL) return l2;
    if(l1 == NULL && l2 == NULL) return NULL;
    Node* head = NULL;
    Node* mover = NULL;
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            Node* newNode = new Node(l1->data);
            if(head == NULL){
                head = newNode;
                mover = head;
            } else {
                mover->next = newNode;
                mover = mover->next;
            }
            l1 = l1->next;
        } else {
            Node* newNode = new Node(l2->data);
            if(head == NULL){
                head = newNode;
                mover = head;
            } else {
                mover->next = newNode;
                mover = mover->next;
            }
            l2 = l2->next;
        }
    }
    while(l1 != NULL){
        Node* newNode = new Node(l1->data);
        if(head == NULL){
            head = newNode;
            mover = head;
        } else {
            mover->next = newNode;
            mover = mover->next;
        }
        l1 = l1->next;
    }
    while(l2 != NULL){
        Node* newNode = new Node(l2->data);
        if(head == NULL){
            head = newNode;
            mover = head;
        } else {
            mover->next = newNode;
            mover = mover->next;
        }
        l2 = l2->next;
    }
    return head;
}

// TC -> 0(N)
// SC -> 0(1)
Node* optimal(Node* l1, Node* l2){
    if(l2 == NULL) return l1;
    if(l1 == NULL) return l2;
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

int main(){
    vector<int> nums1 = {1, 2, 4, 6, 7};
    vector<int> nums2 = {1, 2, 2, 3, 3, 8, 9, 10};
    Node* l1 = convertArr2LL(nums1);
    Node* l2 = convertArr2LL(nums2);
    cout<<"LL 1 : ";
    print(l1);
    cout<<endl;
    cout<<"LL 2 : ";
    print(l2);
    cout<<endl;

    cout<<"LL after merge (BruteForce) : ";
    Node* head = bruteForce(l1, l2);
    print(head);
    cout<<endl;

    l1 = convertArr2LL(nums1);
    l2 = convertArr2LL(nums2);  
    cout<<"LL after merge (better) : ";
    head = better(l1, l2);
    print(head);
    cout<<endl;

    l1 = convertArr2LL(nums1);
    l2 = convertArr2LL(nums2);  
    cout<<"LL after merge (Optimal) : ";
    head = optimal(l1, l2);
    print(head);
}