#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node* random;
    node (int a) {
        val = a;
        next = NULL;
        random = NULL;
    }
};

node* copyRandomList (node* head) {
    node* temp = head;

    //step 1: creating a new copy of the LL
    while (temp) {
        node* newNode = new node (temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    //step 2: putting the random pointers
    node* itr = head;
    while (itr) {
        if (itr->random) {
            itr->next->random = itr->random->next;
        }
        itr = itr->next->next;
    }

    //step 3: separating both the LL
    node* dummy = new node(0);
    itr = head;
    temp = dummy;
    node* fast;
    while (itr) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
}

void printLL (node* head) {
    while (head != NULL) {
        cout << head->val <<":";
        head->next != NULL ? cout << head->next->val : cout << "NULL";
        head->random != NULL ? cout <<"," << head->random->val : cout <<"NULL";
        cout << endl;
        head =head->next;
    }
}

int main() {
    node* head = NULL;
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node3;

    cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    printLL (head);

    cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    node* newHead = copyRandomList (head);
    printLL(newHead);

    return 0;
}