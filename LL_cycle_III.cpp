// Q3. Length of Loop

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

Node* convertArr2LL(vector<int>& nums){
    if(nums.empty())
        return NULL;
    Node* head = new Node(nums[0]);
    Node* mover = head;
    Node* connector = NULL;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
        if(nums[i] == 4)
            connector = temp;
    }
    mover->next = connector;
    return head;
}

int bruteForce(Node* head){
    if(head == NULL || head->next == NULL) return 0;
    Node* temp = head;
    map<Node*, int> mpp;
    int timer = 1;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return timer - mpp[temp];
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int optimal(Node* head){
    if(head == NULL || head->next == NULL) return 0;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            fast = fast->next;
            while(slow != fast){
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = convertArr2LL(nums);
    cout<<"LL : ";
    cout<<endl;

    cout<<"Length of brute force : ";
    int ans = bruteForce(head);
    cout<<ans;
    cout<<endl;

    head = convertArr2LL(nums);
    cout<<"Length of Loop optimal : ";
    ans = optimal(head);
    cout<<ans;
    cout<<endl;
}