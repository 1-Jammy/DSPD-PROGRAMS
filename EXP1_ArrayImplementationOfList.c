//Experiment 1: Array implementation of a list
#include <stdio.h>
#define MAX 100

int list[MAX];
int size = 0;

void display() {
    int i;
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    for (i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void insert(int value, int pos) {
    int i;
    if (size == MAX) {
        printf("List is full.\n");
        return;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid position.\n");
        return;
    }
    for (i = size; i > pos; i--)
        list[i] = list[i - 1];
    list[pos] = value;
    size++;
}

void deleteAt(int pos) {
    int i;
    if (pos < 0 || pos >= size) {
        printf("Invalid position.\n");
        return;
    }
    for (i = pos; i < size - 1; i++)
        list[i] = list[i + 1];
    size--;
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\nMenu:\n1. Insert element\n2. Delete element\n3. Display list\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 4)
            break;
        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value, pos);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                deleteAt(pos);
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
