#include <iostream>
#include <list>

using namespace std;

// ----------------- Classes -------------------
// Each data element that we store in memory
class Node 
{
    public:
        int data;
        Node* next;
        Node(int nodedata)
        {
            data = nodedata;
            next = NULL;
        };
};



int main()
{
    return 0;
}