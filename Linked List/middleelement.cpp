#include<bits/stdc++.h>
using namespace std;

//creating a node class here.
class node {
    public:
    node* next;
    int val;

    node(int a) {
        val = a;
        next = NULL;
    }
};

//inserting nodes in a given linkedlist
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


//1st approach to get middle of linkedList
// int middleNode (node* head) {
//     int count = 0;
//     node* temp = head;
//     while (temp) {
//         count++;
//         temp = temp->next;
//     }
//     temp = head;
//     for (int i=0; i<count/2; i++) {
//         temp = temp->next;
//     }
//     return temp->val;
// }

//2nd approach (Tortoise-Hare method)
int middleNode (node* head) {
    node* slow = head;
    node* fast = head;

    while (fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
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


    cout << "the middle of the given LL is: " << middleNode(head);

    return 0;
}