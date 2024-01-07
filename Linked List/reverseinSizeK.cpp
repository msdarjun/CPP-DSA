#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* next;

    node (int a) {
        val = a;
        next = NULL;
    }
};

void insertNode (node* &head, int val) {
    node* newNode = new node(val);

    if (head == NULL) {
        head = newNode;
        cout << "the LL created is " <<newNode->val;
        return;
    }

    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    cout << " " << newNode->val;
    return;
}

node* reverseinSizeK (node* head, int k) {
    node* curr = head;
    node* prev = NULL;
    node* next;
    int count = 0;

    while (curr and count<k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next) {
        head->next = reverseinSizeK (next, k);
    }
    return prev;
}


void printLL (node* head){
    node* temp = head;
    cout << endl <<"the output is "; 
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {

    node* head = NULL;
    insertNode (head, 1);
    insertNode (head, 2);
    insertNode (head, 3);
    insertNode (head, 4);
    insertNode (head, 5);
    insertNode (head, 6);
    insertNode (head, 7);
    insertNode (head, 8);
    insertNode (head, 9);

    int k = 3;

    head = reverseinSizeK (head, k);

    cout <<endl << "after reversing the LL by given size " << k ;

    printLL (head);

    return 0;
}