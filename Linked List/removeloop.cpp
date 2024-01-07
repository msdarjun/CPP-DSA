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
    node* newNode = new node (val);
    if (head == NULL) {
        head = newNode;
        cout << "the LL create is " << newNode->val;
        return;
    }
    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    cout << " " << newNode->val;
    return;
}

void createCycle (node* head, int a, int b) {
    int cnta = 0,cntb = 0;
    node* p1 = head;
    node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

bool cycleDetect (node* head) {
    if (head == NULL) return false;
    node* fast = head;
    node* slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) return true;
    }
    return false;
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

    createCycle (head, 1, 5);

    if (cycleDetect(head) == true) 
        cout << endl << "cycle is present " << endl;
    else 
        cout << endl << "cycle is not present " << endl;

    return 0;
}