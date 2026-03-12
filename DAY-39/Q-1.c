#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    while(index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void heapifyDown(int index)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;
    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}
void insert(int value)
{
    if(size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}
int extractMin()
{
    if(size == 0)
    {
        printf("Heap Underflow\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}
int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}
void display()
{
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main()
{
    insert(10);
    insert(4);
    insert(15);
    insert(20);
    insert(0);
    printf("Heap elements: ");
    display();
    printf("Min element: %d\n", peek());
    printf("Extracted Min: %d\n", extractMin());
    printf("Heap after deletion: ");
    display();
    return 0;
}