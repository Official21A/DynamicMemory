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

// A method for creating the memory elements
Node* create_node(int value)
{
    return new Node(value);
}

// Each linkedlist has a head that holdes the information about
// that list among of the pointers to the starting memory element
// and the next head.
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
                prev = head;
                head = head->next; 
                delete prev;
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
            delete head; 
            size--;
        };
        void clear_all()
        {
            Node* current = head;
            Node* after = NULL;
            while(head != NULL)
            {
                after = head->next;
                delete head;
                head = after;
            }
        };
};

// Head of the headers
Head* main_head = NULL;

// This method inserts a new node at a gate ( in case of exists )
void insert(int index, int value)
{
    Head* current = main_head;
    for (int i = 1; i <= index; i++)
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

// This method will remove all the nodes with given value in lists
void deletion(int value)
{
    Head* current = main_head;
    while (current != NULL)
    {
        current->remove(value);
        current = current->next;
    }
}

// This method will create some gates at the start
void initalize(int number)
{
    for (int i = 0; i < number; i++)
    {
        Head* temp = new Head();
        temp->next = main_head;
        main_head = temp;
    }
}

// For adding a new slot or gate to the first dimention of linkedlists
int new_gate()
{
    Head* temp = new Head();
    Head* current = main_head;
    int index = 0;
    while(current->next != NULL)
    {
        current = current->next;
        index++;
    }
    current->next = temp;
    temp->next = NULL;
    return index;
}

// This method will remove a gate and all of the nodes init
void delete_gate(int number)
{
    Head* prev = NULL; 
    Head* current = main_head;
    int index = 0;
            
    if (current != NULL && number == 0) 
    { 
        main_head = current->next; 
        current->clear_all();
        delete current;
        return; 
    } 

    while (current != NULL && index != number) 
    { 
        prev = current; 
        current = current->next; 
        index++;
    } 

    if (current == NULL) 
        return; 
    
    prev->next = current->next; 
    current->clear_all();
    delete current; 
}


// Testbench
int main()
{
    initalize(5); // Starting with 5 ports for y
    // Some insertions
    insert(1, 100);
    insert(4, 50);
    insert(4, 63);
    insert(2, 27);
    insert(3, 27);
    // Some deletion
    deletion(50);
    deletion(27);
    // Adding gates
    new_gate();
    new_gate();
    // Removing gate
    delete_gate(4);
    return 0;
}