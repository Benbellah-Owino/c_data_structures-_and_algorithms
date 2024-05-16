#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
typedef struct Node{
    int data;
    Node *next;
}Node;


typedef struct Queue{
    Node *front;
    Node *rear;
    int max_length;
    int length;
}Queue;

void enqueue(Queue *queue,int item);
int dequeue(Queue *queue);
int peek(Queue *queue);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
*/

void enqueue(Queue *queue, unsigned int item){
    if (isFull(queue)){
        printf("Error:-> Queue is full!!!");
        return;
    }

    Node *new =(Node *)malloc(sizeof(Node));
    new -> data = item;
    new -> next = NULL;
    bool is_empty = isEmpty(queue);
    if (is_empty == true){
        queue -> rear = new;
        queue -> front = new;
        queue -> length += 1;
        return;
    }else if(is_empty == false){
        Node *rear = queue -> rear;
        rear -> next = new;
        queue -> rear = new;
        queue -> length += 1;
        return;
    }

};

int dequeue(Queue *queue){
    if (isEmpty(queue)){
        printf("Error:-> Queue is empty!!!");
        return -1;
    }else{
        Node *front = queue -> front;
        queue -> front = front -> next;
        queue -> length -= 1;
        int ret = front -> data;
        free(front);
        return ret;
    }
};

void peek(Queue *queue){
    if (isEmpty(queue)){
        printf("Error:-> Queue is empty!!!");
        return;
    }else{
        printf("{\n  front:-> %d\n", queue -> front -> data);
    }
};

bool isEmpty(Queue *queue){
    if(queue -> length == 0){
        return true;
    }else{
        return false;
    }
};

bool isFull(Queue *queue){
    if(queue -> length == queue -> max_length){
        return true;
    }else{
        return false;
    }
};

void debug_print(Queue *queue){
    
    if (isEmpty(queue)){
        printf("Error:-> Queue is empty!!!");
        return;
    }else{
        Node *node = queue -> front;
        printf("[\nfront |");
        while(node != NULL){
            printf("{data: %d} ->", node -> data);
            node = node -> next;
        }
        printf("| rear\n");
        printf("queue details: {\n length: %d,\n max_length: %d\n}\n]", queue -> length, queue -> max_length);
        return;
    }
}

void EXIT(Queue *queue){

    if (isEmpty(queue)){
        printf("Error:-> Queue is empty!!!");
    }else{
        Node *node = queue -> front;
        while(node != NULL){
            Node *next = node -> next;
            Node *to_free = node;
            node = next;
            free(to_free);
        }
    }
    exit(EXIT_SUCCESS);
}


int main(){
    Queue queue = {
        NULL,
        NULL, 
        10,
        0
    };  

    while(true){
        int option;
        printf("\n\nPlease select an option below:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue.\n");
        printf("3. PeeK \n");
        printf("4. Check if it is empty \n");
        printf("5. Check if it is full \n");
        printf("6. Print queue \n");
        printf("7. EXIT \n");
        printf("\n\nCHOICE: \n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\n\nenqueue()=============================================\n");
                    unsigned int val;
                    printf("Enter a positive integer: ");
                    scanf("%d", &val);
                    enqueue(&queue, val);
                printf("\nend enqueue()===========================================\n");
                break;
            case 2:
                printf("\n\ndequeue()=============================================\n");
                    int val_deq = dequeue(&queue);
                    printf("%d has been removed from queue!", val_deq);
                printf("\nend dequeue()===========================================\n");
                break;
            case 3:
                printf("\n\npeek()=============================================\n");
                    peek(&queue);
                printf("\nend peek()===========================================\n");
                break;
            case 4:
                printf("\n\nisEmpty()=============================================\n");
                    bool is_empty = isEmpty(&queue);
                    if(is_empty == true){
                        printf("Queue is empty");
                    }else{
                        printf("Queue is not empty");
                    }

                printf("\nend isEmpty()===========================================\n");
                break;
            case 5:
                printf("\n\nisFull()=============================================\n");
                    bool is_full = isFull(&queue);
                    if(is_full == true){
                        printf("Queue is full");
                    }else{
                        printf("Queue is not full");
                    }
                printf("\nend isFull()===========================================\n");
                break;
            case 6:
                printf("\n\ndebug_print()=============================================\n");
                    debug_print(&queue);
                printf("\nend debug_print()===========================================\n");
                break;
            case 7:
                printf("\n\nEXIT()=============================================\n");
                    EXIT(&queue);
                break;
            default:
                printf("\n\n PLEASE ENTER A CORRECT CHOICE \n\n");
                break;
                       
        }

    }
}
