#include <stdio.h>
#include <stdbool.h>

#define max 100

struct CircularQueue {
    int items[max];
    int front, rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

bool isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % max == q->front);
}

void enqueue(struct CircularQueue *q, int item) {
    if (isFull(q)) {
        printf("Circular Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % max;
        q->items[q->rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
    } else {
        int removedItem = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % max;
        }
        printf("%d dequeued successfully.\n", removedItem);
    }
}

void traverse(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % max;
        }
        printf("\n");
    }
}

int main() {
    struct CircularQueue cq;
    initQueue(&cq);

    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Is Empty?\n");
        printf("5. Is Full?\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&cq, item);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 3:
                traverse(&cq);
                break;
            case 4:
                if (isEmpty(&cq)) {
                    printf("Circular Queue is empty.\n");
                } else {
                    printf("Circular Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull(&cq)) {
                    printf("Circular Queue is full.\n");
                } else {
                    printf("Circular Queue is not full.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}