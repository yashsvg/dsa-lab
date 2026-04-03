#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

int dequeue() {
    if (front == -1) {
        printf("Queue Empty\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    return val;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d\n", dequeue());
}