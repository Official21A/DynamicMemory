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
        Head* next;
        Head()
        {
            size = 0;
            head = NULL;
        };
        void add_to_head(Node* temp)
        {
            size++;
            temp->next = head;
            head = temp;
        };
        void remove(int vale)
        {
            Node* prev = NULL; 
            
            if (head != NULL && head->data == vale) 
            { 
                head = temp->next; 
                delete temp;
                size--;
                return; 
            } 

            while (head != NULL && head->data != vale) 
            { 
                prev = head; 
                head = head->next; 
            } 
        
            if (head == NULL) 
                return; 
         
            prev->next = head->next; 
            delete temp; 
            size--;
        };
};

Head* main_head = NULL;

void insert(int index, int value)
{
    Head* current = main_head;
    for (int i = 0; i < index; i++)
    {
        if (current->next == NULL)
        {
            return;
        }
        current = current->next;
    }
    Node* temp = create_node(value);
    current->add_to_head(temp);
}

void deletion(int value)
{
    Head* current = main_head;
    while (current != NULL)
    {
        current->remove(value);
        current = current->next;
    }
}

int main()
{
    return 0;
}