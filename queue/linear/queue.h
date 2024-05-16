#include <stdbool.h>
#ifndef HEADER_FILE
#define HEADER_FILE
typedef struct Node{
    unsigned int data;
    struct Node *next;
}Node;


typedef struct Queue{
    Node *front;
    Node *rear;
    int max_length;
    int length;
}Queue;

void enqueue(Queue *queue,unsigned int item);
int dequeue(Queue *queue);
void peek(Queue *queue);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
#endif

