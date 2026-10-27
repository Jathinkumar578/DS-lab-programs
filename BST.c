
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Create a new node
struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Insert a node
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Duplicate values are not allowed!\n");
    }

    return root;
}

// Search an element
void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    if (key == root->data)
    {
        printf("Element found!\n");
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

// Inorder: Left, Root, Right
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find minimum value node
struct node *findMin(struct node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node
struct node *deleteNode(struct node *root, int key)
{
    struct node *temp;

    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- BINARY SEARCH TREE ---\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. INORDER\n");
        printf("4. PREORDER\n");
        printf("5. POSTORDER\n");
        printf("6. DELETE\n");
        printf("7. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
