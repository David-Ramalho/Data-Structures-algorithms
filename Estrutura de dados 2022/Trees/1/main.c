#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_SIZE 100
#define LEFT 0
#define RIGHT 1
#define ROOT -1

// Structure for tree node
typedef struct TreeNode {
    char data;
    int left;
    int right;
    int parent;
} TreeNode;

// Global Variables
TreeNode Tree[MAX_SIZE];
int currentIndex = 0;

// Function Prototypes
void InsertNode(char data, int parentIndex, int side);
int SearchNode(char data);
void DisplayMenu(void);
void ClearInputBuffer(void);

int main(void) {
    int option = -1;
    char parentNodeValue, nodeValue;
    int side, parentIndex;

    do {
        DisplayMenu();
        scanf("%d", &option);
        ClearInputBuffer(); // Clear the input buffer to handle the newline character

        switch (option) {
            case 1:
                printf("\nEnter the value of the parent node: ");
                scanf("%c", &parentNodeValue);
                ClearInputBuffer();

                printf("Enter the value of the new node: ");
                scanf("%c", &nodeValue);
                ClearInputBuffer();

                printf("Enter the side for the subtree (LEFT=%d/RIGHT=%d/ROOT=%d): ", LEFT, RIGHT, ROOT);
                scanf("%d", &side);

                parentIndex = SearchNode(parentNodeValue);
                InsertNode(nodeValue, parentIndex, side);
                break;

            case 2:
                printf("Enter the value of the node to search: ");
                scanf("%c", &nodeValue);
                ClearInputBuffer();

                int index = SearchNode(nodeValue);
                if (index != -1) {
                    printf("Node %c\nLeft Child: %c\nRight Child: %c\n\n",
                           Tree[index].data,
                           Tree[Tree[index].left].data,
                           Tree[Tree[index].right].data);
                } else {
                    printf("Node not found.\n");
                }
                break;
        }
    } while (option != 0);

    return 0;
}

void InsertNode(char data, int parentIndex, int side) {
    if (currentIndex >= MAX_SIZE) {
        printf("Tree is full.\n");
        return;
    }

    if (side == ROOT || parentIndex == -1) { // Inserting root or when parent is not found
        Tree[currentIndex].data = data;
        Tree[currentIndex].parent = -1;
        Tree[currentIndex].left = -1;
        Tree[currentIndex].right = -1;
    } else {
        Tree[currentIndex].data = data;
        Tree[currentIndex].parent = parentIndex;

        if (side == LEFT) {
            Tree[parentIndex].left = currentIndex;
        } else if (side == RIGHT) {
            Tree[parentIndex].right = currentIndex;
        }

        Tree[currentIndex].left = -1;
        Tree[currentIndex].right = -1;
    }

    currentIndex++;
}

int SearchNode(char data) {
    int i;
    for (i = 0; i < currentIndex; i++) {
        if (Tree[i].data == data) {
            return i;
        }
    }
    return -1; // Return -1 if not found
}

void DisplayMenu(void) {
    system("clear"); // Use "cls" for Windows and "clear" for Unix/Linux
    printf("Binary Tree Management\n");
    printf("1 - Insert a node into the tree\n");
    printf("2 - Search for a node in the tree\n");
    printf("0 - Exit\n\n");
}

// Utility function to clear the input buffer
void ClearInputBuffer(void) {
    while (getchar() != '\n');
}

