#include <stdio.h>

int heap[100];
int size = 0;

// Insert into max heap
void insert(int val) {
    int i = size++;
    heap[i] = val;

    // Heapify up (max heap)
    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

// Extract max element
int extractMax() {
    if (size <= 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (2*i + 1 < size) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else break;
    }

    return root;
}

// Display heap
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);

    display();

    printf("Max: %d\n", extractMax());

    display();

    return 0;
}
