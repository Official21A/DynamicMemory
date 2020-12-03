#include <iostream>

using namespace std;

// ----------------- Classes -------------------


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
        }
};

// A method for creating the memory elements
Node* create_node(int key, long value)
{
    return new Node(key, value);
}

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
        }
        Node* give_a_way(int number)
        {
            switch(number)
            {
                case 0:
                    return mode_zero;
                case 1:
                    return mode_one;
                case 2:
                    return mode_two;
                case 3:
                    return mode_three;
                default:
                    return NULL;
            }
        }
};

Intersection* main_node = new Intersection();

// Methods we need to implement
void insertion(int key)
{
    Node* temp = create_node(key);
    Node* head = main_node->give_a_way(key % 4);
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->next = NULL;
}

Node* search(int key)
{
    Node* head = main_node->give_a_way(key % 4);
    while (head != NULL && head->key != key)
    {
        head = head->next;
    }
    return head;
}

Node* deletion(int key)
{
    Node* temp = search(key);
    Node* head = main_node->give_a_way(key % 4);
    if (head == temp)
    {
        head = temp->next;
    } else 
    {
        while (head->next != NULL && head->next != temp)
        {
            head = head->next;
        }
        head->next = temp->next;
    }
    return temp;
}

int way_lenght(Node* head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int size()
{
    return way_lenght(main_node->mode_zero) + way_lenght(main_node->mode_one) + way_lenght(main_node->mode_two) + way_lenght(main_node->mode_three);
}
void print();