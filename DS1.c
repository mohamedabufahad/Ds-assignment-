#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct CircularQueue {
    struct Node *front, *rear;
};
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct CircularQueue* createQueue() {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(struct CircularQueue* q) {
    return q->front == NULL;
}
int Front(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}
int Rear(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->rear->data;
}
void enQueue(struct CircularQueue* q, int value) {
    struct Node* temp = newNode(value);
    if (isEmpty(q)) {
        q->front = q->rear = temp;
        q->rear->next = q->front;
    } else {
        q->rear->next = temp;
        q->rear = temp; 
        q->rear->next = q->front;
    }
    printf("Enqueued: %d\n", value);
}
int deQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value;
    struct Node* temp = q->front;
    if (q->front == q->rear) {
        value = temp->data;
        q->front = q->rear = NULL;
        free(temp);
    } else { 
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front; 
        free(temp);
    }
    printf("Dequeued: %d\n", value);
    return value;
}
int main() {
    struct CircularQueue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    printf("Front item is: %d\n", Front(q));
    printf("Rear item is: %d\n", Rear(q));
    deQueue(q);
    deQueue(q);
    printf("After two dequeues, Front item is: %d\n", Front(q));
    printf("After two dequeues, Rear item is: %d\n", Rear(q));
    return 0;
}
