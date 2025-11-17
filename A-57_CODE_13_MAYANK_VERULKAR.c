#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at beginning
void insertBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// 2. Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// 3. Insert at position
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// 4. Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// 5. Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// 6. Delete at position
void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// 7. Display forward
void display() {
    struct Node* temp = head;
    if (!temp) {
        printf("List empty\n");
        return;
    }

    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 8. Reverse the doubly linked list
void reverse() {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

// 9. Merge two sorted DLLs
struct Node* mergeDLL(struct Node* h1, struct Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    struct Node* result = NULL;

    if (h1->data < h2->data) {
        result = h1;
        result->next = mergeDLL(h1->next, h2);
        if (result->next) result->next->prev = result;
    } else {
        result = h2;
        result->next = mergeDLL(h1, h2->next);
        if (result->next) result->next->prev = result;
    }
    return result;
}

// 10. Find middle node (Tortoise-Hare)
void findMiddle() {
    if (!head) {
        printf("List empty\n");
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element = %d\n", slow->data);
}

// 11. Sort DLL (Bubble sort)
void sortList() {
    if (!head) return;

    struct Node* i = head;
    struct Node* j = NULL;
    int temp;

    while (i->next != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// 12. Detect loop (Floyd cycle detection)
void detectLoop() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Loop detected!\n");
            return;
        }
    }

    printf("No loop detected.\n");
}

// 13. Sum of all nodes
void sumOfData() {
    int sum = 0;
    struct Node* temp = head;

    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all elements = %d\n", sum);
}

// 14. Print odd and even elements
void printOddEven() {
    struct Node* temp = head;

    printf("Odd elements: ");
    while (temp) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nEven elements: ");
    temp = head;
    while (temp) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ==========================
// MAIN MENU
// ==========================
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert beginning\n");
        printf("2. Insert end\n");
        printf("3. Insert at position\n");
        printf("4. Delete beginning\n");
        printf("5. Delete end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Reverse list\n");
        printf("9. Sort list\n");
        printf("10. Find middle\n");
        printf("11. Sum of all nodes\n");
        printf("12. Odd/Even elements\n");
        printf("13. Detect loop\n");
        printf("14. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data & position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;

            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7: display(); break;
            case 8: reverse(); break;
            case 9: sortList(); break;
            case 10: findMiddle(); break;
            case 11: sumOfData(); break;
            case 12: printOddEven(); break;
            case 13: detectLoop(); break;

            case 14: exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
