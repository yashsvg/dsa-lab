#include <stdio.h>

int heap[100];
int size = 0;

void insert(int val) {
    int i = size++;
    heap[i] = val;

    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMin() {
    if (size <= 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (2*i+1 < size) {
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;

        if (heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
    return root;
}

int main() {
    insert(10);
    insert(5);
    insert(20);
    printf("%d\n", extractMin());
}
