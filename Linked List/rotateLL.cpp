/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.

Input:
The first line of input contains the number of testcases T. For each test case, the first line of input contains the length of a 
linked list and the next line contains linked list elements and the last line contains k, by which linked list is to be rotated.

Output:
For each test case, print the rotated linked list.

User Task:
The task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument. 
The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= k <= 103

Example:
Input:
2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3
Output:
5 6 7 8 1 2 3 4
8 9 2 4 7
*/

/*------------------------------------------------------------------------------------------------------------------------------------*/


// Code

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void) {

    int t, k;

    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); 
        scanf("%d", &k);
        head = rotate(head, k); 
        printList(head);     
    }
    return (0);
}

Node* rotate(Node* head, int k) {
    Node *a=head,*b=head;
    for(int i=1;i<k;i++){
        a=a->next;
        b=b->next;
    }
    while(b->next!=NULL)
        b=b->next;
    
    b->next=head;
    head=a->next;
    a->next=NULL;
    return head;
}
