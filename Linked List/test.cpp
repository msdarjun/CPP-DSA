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
    return 0;
}