#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    node* next;
    int val;

    node(int a) {
        val = a;
        next = NULL;
    }
};

void insertNodes (node* &head, int val) {
    
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        cout << "the linkedList created is " <<newNode->val;
        return;
    }

    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    cout << " " << newNode->val;
    return;
}

//reverse 1st approach(using pointers)
// node* reverseLL (node* head) {
//     node* prev = NULL;
//     node* curr = head;
//     node* next;
//     while (curr) {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

//2nd approach (using stack DS) 
node* reverseLL (node* head) {
    node* temp = head;
    stack<int>st;

    while (temp) {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;

    while (temp) {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


void printLL (node* head) {
    node* temp = head;
    cout <<endl << "the reverserd LL is ";
    while (temp) {
        cout << temp->val <<" ";
        temp = temp->next;
    }
}

int main () {

    node* head = NULL;
    insertNodes (head, 1);
    insertNodes (head, 2);
    insertNodes (head, 3);
    insertNodes (head, 4);
    insertNodes (head, 5);
    insertNodes (head, 6);
    insertNodes (head, 7);
    insertNodes (head, 8);

    head = reverseLL(head);
    printLL(head);


    return 0;
}