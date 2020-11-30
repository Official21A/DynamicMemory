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

Node* create_node(int value)
{
    return new Node(value);
}

class Head
{
    public:
        int size;
        Node* head;
        Head()
        {
            size = 0;
            head = NULL;
        };
        void add_to_head(Node* temp)
        {
            temp->next = head;
            head = temp;
        };
        void remove(Node* temp)
        {
            Node* prev = NULL; 
            
            if (head != NULL && head == temp) 
            { 
                head = temp->next; 
                delete temp;
                return; 
            } 

            while (head != NULL && head != temp) 
            { 
                prev = head; 
                head = head->next; 
            } 
        
            if (head == NULL) 
                return; 
         
            prev->next = head->next; 
            delete temp; 
        };
};

void insert(int value)
{
    Node* temp = create_node(value);

}



int main()
{
    return 0;
}