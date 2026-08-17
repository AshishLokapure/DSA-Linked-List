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
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    int middle = n/2;
    temp = head;
    while(temp != NULL){
        middle--;
        if(middle == 0){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete(del);
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* del = slow->next;
    slow->next = slow->next->next;
    delete(del);
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 7};
    Node* head = convertArr2LL(nums);
    cout<<"LL before deleting middle element : ";
    print(head);
    cout<<endl;

    cout<<"LL after deleting middle (bruteForce) : ";
    head = bruteForce(head);
    print(head);
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"LL after deleting middle (optimal) : ";
    head = optimal(head);
    print(head);
}