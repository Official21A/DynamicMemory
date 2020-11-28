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

int main()
{
    // Create an array of pointer as slots
    // Create a table to generate a key
    // Create a linked list for any slots to point at
    // Add the methods
    // Create the diagram of data structure
    Slot slots[100];
    create_slots(slots);
    return 0;
}