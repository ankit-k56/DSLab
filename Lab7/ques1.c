#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct qu {
    int items[MAX];
    int front, rear;
};

void initQueue(struct qu *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct qu *q) {
    return (q->front == -1 && q->rear == -1);
}

bool isFull(struct qu *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct qu *q, int item) {
    if (isFull(q)) {
        printf("qu is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

void dequeue(struct qu *q) {
    if (isEmpty(q)) {
        printf("qu is empty. Cannot dequeue.\n");
    } else {
        int deleted= q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("%d dequeued successfully.\n",deleted);
    }
}

void traverse(struct qu *q) {
    if (isEmpty(q)) {
        printf("qu is empty.\n");
    } else {
        printf("qu elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    struct qu qu;
    initQueue(&qu);

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
                enqueue(&qu, item);
                break;
            case 2:
                dequeue(&qu);
                break;
            case 3:
                traverse(&qu);
                break;
            case 4:
                if (isEmpty(&qu)) {
                    printf("qu is empty.\n");
                } else {
                    printf("qu is not empty.\n");
                }
                break;
            case 5:
                if (isFull(&qu)) {
                    printf("qu is full.\n");
                } else {
                    printf("qu is not full.\n");
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