#include <iostream>

using namespace std;

// ----------------- Classes -------------------
// A sentinel in the middle which has 4 pointers to 4 lists
class Intersection
{
    public:
        // Each list has its header inside this class
        Node* mode_zero;
        Node* mode_one;
        Node* mode_two;
        Node* mode_three;
        Intersection()
        {
            mode_zero = NULL;
            mode_one = NULL;
            mode_two = NULL;
            mode_three = NULL;
        };
};

// Each data element that we store in memory
class Node 
{
    public:
        int key
        long data;
        Node* next;
        Node(int nodekey, long nodedata)
        {
            key = nodekey;
            data = nodedata;
            next = NULL;
        };
};

// A method for creating the memory elements
Node* create_node(int key, long value)
{
    return new Node(key, value);
}


// Methods we need to implement
void insertion(Node* temp, int key);
Node* deletion(int key);
Node* search(int key);
int size();
void print();