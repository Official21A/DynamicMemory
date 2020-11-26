#include <iostream>
#include <list>

using namespace std;

// Each data element that we store in memory
class Node {
    int key;
    int data;
    Node(int newkey, int nodedata)
    {
        key = newkey;
        data = nodedata;
    }
}

// The slots are the gates the lead us to the right list
class Slot {
    int key;
    Node* table;
    Slot(int keypart, Node* tablepointer)
    {
        key = keypart;
        table = tablepointer;
    }
}

// Hashes the key given to a new key
int hash_function(int key)
{
    return key % 100;
}

int main()
{
    // Create an array of pointer as slots
    // Create a table to generate a key
    // Create a linked list for any slots to point at
    // Add the methods
    // Create the diagram of data structure
}