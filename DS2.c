#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        
        fast = fast->next->next;    
    }
    return slow->data;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
   
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    printf("Original Linked List: ");
    printList(head);
    int middle = findMiddle(head);
    printf("Middle node data is: %d\n", middle);
    head->next->next->next->next->next = newNode(6);
    printf("Updated Linked List with even number of nodes: ");
    printList(head);
    middle = findMiddle(head);
    printf("Middle node data is: %d\n", middle);
    return 0;
}
