#include <iostream>
#include <list>

using namespace std;

// ----------------- Classes -------------------
// Each data element that we store in memory
class Node 
{
    public:
        int key;
        int data;
        Node* next;
        Node(int newkey, int nodedata)
        {
            key = newkey;
            data = nodedata;
            next = NULL;
        };
};

// The slots are the gates the lead us to the right list
class Slot 
{
    public:
        int key;
        Node* listhead;
        Slot()
        {
            listhead = NULL;
        }
        void insert(Node* newnode)
        {
            newnode->next = listhead;
            listhead = newnode;
        }
};
// ----------------- End Classes -------------------

// ---------------- Data structure functions ---------------------
// This function creates a new single node
Node* create_node(int key, int data)
{
    Node* temp = new Node(key, data);
    return temp;
}

// Hashes the key given to a new key
int hash_function(int key)
{
    return key % 100;
}

// Inserting
void insertNode(Slot slots[], int key, int data)
{
    int hashedkey = hash_function(key);
    slots[hashedkey].insert(create_node(key, data));
}

// Deleting
void deleteNode(Node* head, Node* n)  
{  
    // When node to be deleted is head node  
    if(head == n)  
    {  
        if(head->next == NULL)  
        {  
            return;  
        }  
        /* Copy the data of next node to head */
        head->key = head->next->key;  
        // store address of next node  
        n = head->next;  
        // Remove the link of next node  
        head->next = head->next->next;  
        // free memory  
        delete n;  
        return;  
    }  
    Node* prev = head;  
    while(prev->next != NULL && prev->next != n)  
        prev = prev->next;  
    // Check if node really exists in Linked List  
    if(prev->next == NULL)  
    {  
        return;  
    }  
    // Remove node from Linked List  
    prev->next = prev->next->next;  
    // Free memory  
    delete n;
    return;  
}

// Searching and removing
void remove(Slot slots[], int key)
{
    int hashedkey = hash_function(key);
    Node* head = slots[hashedkey].listhead;
    while(head != NULL)
    {
        if (head->key == key)
            break;
        else
            head = head->next;
    }
    deleteNode(slots[hashedkey].listhead, head);
}

// It creates 100 slots from 0 to 99
void create_slots(Slot slots[])
{
    for (int i = 0; i < 100; i++)
    {
        slots[i].key = i;
    }
}

// Testbench
int main()
{
    Slot slots[100];
    create_slots(slots);
    return 0;
}