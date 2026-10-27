
#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void initialize()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert an element
void insert()
{
    int key, index, i;

    printf("Enter key: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            printf("Key inserted at index %d\n", pos);
            return;
        }
    }

    printf("Hash Table is Full!\n");
}

// Search an element
void search()
{
    int key, index, i;

    printf("Enter key to search: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
        {
            break;
        }

        if (hashTable[pos] == key)
        {
            printf("Key found at index %d\n", pos);
            return;
        }
    }

    printf("Key not found!\n");
}

// Display hash table
void display()
{
    int i;

    printf("\nIndex\tValue\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d\tEmpty\n", i);
        else
            printf("%d\t%d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice;

    initialize();

    while (1)
    {
        printf("\n--- HASHING USING LINEAR PROBING ---\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
