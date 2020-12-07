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

// Structure needes
int memory_space = 100;
int index = 0;
Node* memory[memory_space];

// Check the new adding
void check_to_root(int index)
{
    int parent = int(index / 2);
    while(parent != -1 && memory[parent] > memory[index])
    {
        Node* temp = memory[parent];
        memory[parent] = memory[index];
        memory[index] = temp;
        index = parent;
        parent = int(index / 2);
    }
}

// Add a new event
void add_event(int key, string value)
{
    if (index == memory_space)
    {
        cout << "Overflow" << endl;
        return;
    }
    memory[index] = create_node(key, value);
    check_to_root(index);
    index++;
}



// Testbench
int main()
{
    
}