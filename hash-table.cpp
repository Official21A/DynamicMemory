#include <iostream>
#include <list>

using namespace std;

// Each data element that we store in memory
class Node 
{
    public:
        int key;
        int data;
        Node(int newkey, int nodedata)
        {
            key = newkey;
            data = nodedata;
        };
};

// The slots are the gates the lead us to the right list
class Slot 
{
    public:
        int key;
        list <Node> hash_list;
};

// Hashes the key given to a new key
int hash_function(int key)
{
    return key % 100;
}

// It creates 100 slots from 0 to 99
void create_slots(Slot slots[])
{
    for (int i = 0; i < 100; i++)
    {
        slots[i].key = i;
    }
}

// This function creates a new single node
Node create_node(int key, int data)
{
    Node temp(key, data);
    return temp;
}

// Methods
// Inserting
void insert(Slot slots[], int key, int data)
{
    int hashedkey = hash_function(key);
    slots[hashedkey].hash_list.push_front(create_node(key, data));
}

// Deleting
void remove(Slot slots[], int key)
{
    int hashedkey = hash_function(key);
    int size = slots[hashedkey].hash_list.size();
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (slots[hashedkey].hash_list[i].key == key)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        slots[hashedkey].hash_list.erase(index);
    }
}

int main()
{
    // Create an array of pointer as slots
    // Create a table to generate a key
    // Create a linked list for any slots to point at
    // Add the methods
    // Create the diagram of data structure
    Slot slots[100];
    create_slots(slots);
    insert(slots, 10, 500);
    return 0;
}