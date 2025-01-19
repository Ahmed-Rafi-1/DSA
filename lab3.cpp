// Solution to Lab Assignment - 3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Question 1: Factorial (Recursive and Non-Recursive)
#include<bits/stdc++.h>
using namespace std;
int rec_way(int n)
{
    if(n==0)
    {return 1;}
    return n*rec_way(n-1);
}
int nonrec_way(int n)
{
    int i;
    int ans = 1;
    for ( int i=1; i<=n; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    if(n<0)
    {
        return 1;
    }
    cout << "Using recursion " << rec_way(n) << endl;
    cout << "Using non recursion " << nonrec_way(n) << endl;
}

// Question 2: Fibonacci (Recursive and Non-Recursive)
#include<bits/stdc++.h>
using namespace std;

int fibonacci_rec(int n)
{
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int fibonacci_nonrec(int n)
{
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    int a = 0, b = 1, fib = 0;
    for( int i=2; i<=n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main()
{
    int n;
    cin >> n;
    if(n<0)
    {
        return 1;
    }
    cout << "Using recursion " << fibonacci_rec(n) << endl;
    cout << "Using non-recurion " << fibonacci_nonrec(n) << endl;
}

// Question 3: Tower of Hanoi
#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char aux, char des)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << des << endl;
        return;
    }
    towerOfHanoi(n - 1, source, des, aux);
    cout << "Move disk " << n << " from " << source << " to " << des << endl;
    towerOfHanoi(n - 1, aux, source, des);
}
int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}

// Question 4: Ackermann Function
#include<bits/stdc++.h>
using namespace std;
int ackerman(int m, int n)
{
    if(m == 0)
    {
        return n+1;
    }
    else if(n == 0)
    {
        return ackerman(m-1,1);
    }
    else
        return ackerman(m-1, ackerman(m, n-1));
}
int main()
{
    int m, n;
    cin >> m >> n;
    int result = ackerman(m,n);
    cout << "Result = " << result << endl;
}

// Question 5: Circular Queue Insert and Delete
#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
public:
    int fr, rear, sz;
    int *queue;
    CircularQueue(int s)
    {
        fr = rear = -1;
        sz = s;
        queue = new int[s];
    }
    void enqueue(int val)
    {
        if((fr == -1 && rear == sz-1) || (rear == (fr - 1 )%(sz - 1)))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if(fr == -1) //first element push
        {
            fr = rear = 0;
        }
        else if(rear == sz-1 && fr != 0)
        {
            rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = val;

    }
    int dequeue()
    {
        if(fr == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        int ans = queue[fr];
        queue[fr] = -1;
        if(fr == rear)
        {
            fr = rear = -1;
        }
        else if(fr == sz-1)
        {
            fr = 0;
        }
        else
        {
            fr++;
        }
        return ans;
    }
    void display()
    {
        if(fr == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if(fr<=rear)
        {
            for(int i=fr; i<=rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else{
            for(int i=fr; i<sz; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i=0; i<=rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Deleted value = " << q.dequeue() << endl;
    cout << "Deleted value = " << q.dequeue() << endl;
    q.display();

    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.display();

    return 0;
}

// Question 6: Priority Queue using Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    int prior;
    Node *next;

public:
    Node(int val, int pval)
    {
        data = val;
        prior = pval;
        next = 0;
    }
    friend class pc;
};
class pc
{
    Node *head;

public:
    pc()
    {
        head = 0;
    }
    void enque(int val, int pval)
    {
        Node *newnode = new Node(val, pval);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
            head->next = 0;
        }
        else if (head->prior < newnode->prior)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != 0 && tmp->next->prior > newnode->prior)
            {
                tmp = tmp->next;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
        }
    }
     void display()
     {
         Node *tmp = head;
         while (tmp != 0)
         {
             cout << tmp->data << " ";
             tmp = tmp->next;
         }
     }
    void deque()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    int front()
    {
        return head->data;
    }
    bool isempty()
    {
        return head == 0;
    }
};
int main()
{

    pc a;
    a.enque(10, 6);
    a.enque(15, 5);
    a.enque(16, 3);
    a.enque(9, 4);

    a.display();
    while (!a.isempty())
    {
        cout << a.front() << " ";
        a.deque();
    }
}

// Questions 8-13: Linked Lists (Single, Circular, and Doubly Linked List Operations)

// Single Linked List
class SinglyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add new node at the end
    }

    void deleteNode(int value) {
        if (!head) return; // Empty list
        if (head->data == value) {
            Node* temp = head;
            head = head->next; // Delete head node
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next; // Search for the node to delete
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next; // Unlink the node
            delete toDelete;
        }
    }

    void display() {
        Node* temp = head;
        cout << "Singly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Circular Linked List
class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail; // Point to itself
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode; // Update tail to the new node
    }

    void display() {
        if (!tail) {
            cout << "Circular Linked List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

// Doubly Linked List
class DoublyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode;
        newNode->prev = temp; // Link the new node
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Question 14: Find 100! using strings
#include<bits/stdc++.h>
using namespace std;
string multiplyStrings(string num1, int num2) {
    int carry = 0;
    string result = "";
    for (int i = num1.size() - 1; i >= 0; i--) {
        int product = (num1[i] - '0') * num2 + carry;
        result = char(product % 10 + '0') + result;
        carry = product / 10;
    }
    while (carry) {
        result = char(carry % 10 + '0') + result;
        carry /= 10;
    }
    return result;
}

int main() {
    int n; cin >> n;
    string result = "1";
    for (int i = 2; i <= n; i++) {
        result = multiplyStrings(result, i);
    }
    cout << result << endl;
}


// Question 15: Fibonacci using strings
#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2) {
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    string result = "";
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }
    return result;
}

string fibonacciString(int n) {
    if (n == 1 || n == 2) return "1";
    string a = "1", b = "1", c;
    for (int i = 3; i <= n; i++) {
        c = addStrings(a, b);
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n = 500;  // Example: Find the 10th Fibonacci number
    cout << "Fibonacci number at position " << n << ": " << fibonacciString(n) << endl;
    return 0;
}

