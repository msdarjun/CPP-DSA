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

void printLL (node* head) {
    node* temp = head;
    cout << endl << "the reverserd LL is ";
    while (temp) {
        cout << temp->val <<" ";
        temp = temp->next;
    }
}

node* rotateRightbyK (node* head, int k) {
    //calculate the length
    int length = 1;
    node* temp = head;
    while (temp->next) {
        length++;
        temp = temp->next;
    }

    //make it as a circular LL
    temp->next = head;

    //breaking the last node and point it to the NULL
    k = k % length;
    int end = length-k;
    while (end--) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    return head;
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
    insertNodes (head, 9);

    int k = 3;
    head = rotateRightbyK (head, k);
    cout << "after rotating right the LL by " << k <<"times ";

    printLL (head);

    return 0;
}