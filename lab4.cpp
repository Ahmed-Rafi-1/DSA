//1. Insertion Sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
    }

    for(int i=1; i<n; i++)
    {
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

//2. Selection Sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[j]<v[i])
            {
                swap(v[j], v[i]);
            }
        }
    }
    for(int i:v)
    {
        cout << i << " ";
    }
}

//3. Quick Sort
#include<bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quickSort(int arr[], int l, int r)
{
    if (l<r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

//4. Merge Two Sorted Lists
#include <iostream>
using namespace std;

void mergeSortedLists(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }
    while (i < n1)
        result[k++] = arr1[i++];
    while (j < n2)
        result[k++] = arr2[j++];
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[n1 + n2];

    mergeSortedLists(arr1, n1, arr2, n2, result);

    cout << "Merged sorted list: ";
    for (int i = 0; i < n1 + n2; i++)
        cout << result[i] << " ";
    return 0;
}

//5. Merge Sort
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];

    for (int i=0; i<n1; i++)
    {
        a[i] = arr[l+i];
    }
    for (int i=0; i<n2; i++)
    {
        b[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k] = a[i];
            k++; i++;
        }
        else
        {
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i<n1)
    {
        arr[k] = a[i];
        k++; i++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

//67. BST
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int v;
    Node* left;
    Node* right;
    Node(int v)
    {
        this->left = NULL;
        this->right = NULL;
        this->v = v;
    }
};
void insert_bst(Node* &root, int v)
{
    if (root == NULL)
    {
        root = new Node(v);
        return;
    }
    if(root->v > v)
    {
        if(root->left == NULL)
        {
            root->left = new Node(v);
        }
        else{
            insert_bst(root->left, v);
        }
    }
    if(root->v < v)
    {
        if(root->right == NULL)
        {
            root->right = new Node(v);
        }
        else{
            insert_bst(root->right, v);
        }
    }
}
void pre_order(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->v << " ";
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(Node* root)
{
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout << root->v << " ";
}
void in_order(Node* root)
{
    if(root==NULL)
        return;
    in_order(root->left);
    cout << root->v << " ";
    in_order(root->right);
}
bool search_bst(Node* root, int v)
{
    if(root == NULL) return false;
    if(root->v == v) return true;
    if (root->v > v)
    {
        bool l = search_bst(root->left, v);
        if (l == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return search_bst(root->right, v);
    }
}
int main()
{
    Node* root = NULL;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int v; cin >> v;
        insert_bst(root, v);
    }
    cout << "Printing in pre-order" << endl;
    pre_order(root);
    cout << endl;
    cout << "Printing in post-order" << endl;
    post_order(root);
    cout << endl;
    cout << "Printing in in-order" << endl;
    in_order(root);
    cout << endl;
    int x; cin >> x;
    if (search_bst(root, x))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

//910.Create a Maxheap and Display its Elements  and Delete an Element
#include <bits/stdc++.h>
using namespace std;

void heapifyUp(vector<int>& heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(vector<int>& heap, int index)
{
    int size = heap.size();
    while (true)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;
        if (largest == index) break;
        swap(heap[index], heap[largest]);
        index = largest;
    }
}

void insert(vector<int>& heap, int value)
{
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

void deleteelement(vector<int>& heap, int index)
{
    if (index < 0 || index >= heap.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    heap[index] = heap.back();
    heap.pop_back();

    heapifyDown(heap, index);
    heapifyUp(heap, index);
}
void display(vector<int>& heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> heap;
    int n, value, index;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(heap, value);
    }
    display(heap);
    cin >> index;
    deleteelement(heap, index);
    display(heap);
    return 0;
}

//11. Heap Sort Algorithm
#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}
void heapSort(vector<int>& heap)
{
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}
void display(const vector<int>& heap)
{
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    heapSort(nums);
    display(nums);
    return 0;
}

//12. adjancy matrix
#include <iostream>
using namespace std;

void displayAdjacencyMatrix(int graph[][4], int n) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    displayAdjacencyMatrix(graph, 4);

    return 0;
}

//15. Adjancy list
#include <iostream>
#include <vector>
using namespace std;

void displayAdjacencyList(vector<int> adj[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<int> adj[5];

    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);

    displayAdjacencyList(adj, n);

    return 0;
}

//18. Hash Table Using Division Method and Linear Probing
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct HashTable {
    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
            isOccupied[i] = false;
        }
    }

    void insert(int key) {
        int index = key % TABLE_SIZE;
        while (isOccupied[index]) {
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        table[index] = key;
        isOccupied[index] = true;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (isOccupied[i])
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(27);

    ht.display();

    return 0;
}

//19. Hash Table Using Division Method and Double Hashing
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct HashTable {
    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
            isOccupied[i] = false;
        }
    }

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7); // Secondary hash function
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (isOccupied[index]) {
            index = (index + step) % TABLE_SIZE; // Double hashing
        }
        table[index] = key;
        isOccupied[index] = true;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (isOccupied[i])
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(27);

    ht.display();

    return 0;
}


// 20. Hash Table Using Chaining
#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

struct HashTable {
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key); // Insert using chaining
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            for (int key : table[i]) {
                cout << key << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(27);

    ht.display();

    return 0;
}
