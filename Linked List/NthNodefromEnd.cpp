#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node(int a) {
        val = a;
        next = NULL;
    }
};

void insertNodes (node* &head, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        cout << "the new LL created is " << newNode->val;
        return;
    }

    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << " " << newNode->val;
    return;
}

int removeNthFromEnd (node* head, int n) {
    node* currentNode = head;
    node* nthNode = head;

    for (int i=0; i<n; i++) {
        if (currentNode == NULL) return -1;
        currentNode = currentNode->next;
    }

    while (currentNode ) {
        currentNode = currentNode->next;
        nthNode = nthNode->next;
    }
    return nthNode->val;
}


int main() {

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

    int n = 3;
    int ans = removeNthFromEnd (head, n);
    cout << "the nth node from the end is " << ans;

    return 0;
}