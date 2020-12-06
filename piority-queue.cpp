#include <iostream>
#include <string>

using namespace std;

// ----------------- Classes -------------------
// Each data element that we store in memory
class Node 
{
    public:
        int piority_key;
        string big_data;
        Node(int key, string data)
        {
            piority_key = key;
            big_data = data;
        };
};

// A method for creating the memory elements
Node* create_node(int key, string value)
{
    return new Node(key, value);
}


// Testbench
int main()
{
    return 0;
}