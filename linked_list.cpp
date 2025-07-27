#include <bits/stdc++.h>
using namespace std;

/*  TOPIC To Be convered ;
 push_front, push_back , pop_front , pop_back, printLL
 insert in Middle of LL, search , printLL ;  

*/

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val ; 
        next = nullptr ; 
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val)                  // TC -> O(1);
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        { // case 1:  where head is null ;
            head = tail = newNode;
            return;
        }

        else
        {                         // case 2 : where head is not null
            newNode->next = head; // 19:16
            head = newNode;
        }
    }

    void push_back(int val)                // TC -> O(1);
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode; // link the new node to the end of the list
            tail = newNode;       // update the tail to the new node
        }
    }

    void pop_front()                       // TC -> O(1);
    {

        if (head == NULL)
        {
            cout << "LL is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()                           // TC -> O(N);  
    {
        if (head == NULL)
        {
            cout << "LL is empty";
            return;
        }
        else
        {
            // temp->next = tail or temp->next->next = NULL;
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    // insert in middle of LL
    void insert(int val, int pos)                // TC -> O(N);
    {
        if (pos < 0)
        {
            cout << "invalid pos";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "invalid pos\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key)                         // TC -> O(N);
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printLL()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// head -> 1.NULL  , 2. not NULL

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.pop_front();

    ll.printLL(); // Output: 3 2 1 4 ;

    ll.pop_back();
    ll.printLL();

    ll.insert(4, 1);
    ll.printLL();

    ll.search(4);
    return 0;
}
