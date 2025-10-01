#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node();
    Node(int);
    Node(int, Node*);
};

typedef Node* Nptr;

Node::Node(): data(0), next(nullptr) {}
Node::Node(int a): data(a), next(nullptr) {}
Node::Node(int a, Nptr ptr): data(a), next(ptr) {}

class LinkedList {
public:
    LinkedList();
    LinkedList(Node*);
    LinkedList(Node*, Node*);
    ~LinkedList();

    // methods
    void PrintList() const; 
    int len(); 
    void addTop(int);
    void addEnd(int);
    void popEnd();
    void popTop();
    int find(int);
    void pop();

private:
    Node* head;
    Node* tail;
};

// ---- Constructors ----
LinkedList::LinkedList(): head(nullptr), tail(nullptr) {}
LinkedList::LinkedList(Node* a): head(a), tail(nullptr) {}
LinkedList::LinkedList(Node* a, Node* b): head(a), tail(b) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        popTop();
    }
}

// ---- Methods ----
void LinkedList::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int LinkedList::len() {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::addTop(int a) {
    Node* NewNode = new Node(a);
    NewNode->next = head;
    head = NewNode;
    if (tail == nullptr) {
        tail = NewNode;
    }
}

void LinkedList::addEnd(int a) {
    Node* NewNode = new Node(a);
    if (head == nullptr) {
        head = tail = NewNode;
    } else {
        tail->next = NewNode;
        tail = NewNode;
    }
}

void LinkedList::popTop() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void LinkedList::popEnd() {
    if (head == nullptr) return;
    if (head == tail) { 
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
}
int LinkedList::find(int a){
  Node* current = head;
  int index=0;
  while (current->data!=a) {
      current = current->next;
      index+=1;
      if (index>len()){
        index=-1;
        break;
      }
    }
  return index;

}

// ---- MAIN ----
int main() {
    LinkedList list;
    list.addTop(10);
    list.addTop(20);
    list.addEnd(30);
    list.PrintList(); // 20 10 30

    cout << "Length: " << list.len() << endl; // 3

    list.popTop();
    list.PrintList(); // 10 30

    cout<<list.find(10)<<endl;
    list.PrintList();

    return 0;
}
