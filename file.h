#include <vector>

struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class LinkedList {
private:
    Node* Tail;
    Node* Head;

public:
    LinkedList() {
        Head = nullptr;
        Tail = Head;
    };
    ~LinkedList() {
        Node* p = Head;
        while (p != nullptr) {
            p->prev = nullptr;
            p = p->next;
        }
    };
    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();
    Node* GetHead();
    void deletenode(Node* l);
    void deletelist();

    int& operator[](int index);
    bool operator==(const LinkedList l1);
    void operator=(LinkedList& l1);

};
void print(LinkedList* l1);
Node* insert(Node* p/*куда*/, Node* pnext/*что*/);
void meagell(LinkedList* l1, LinkedList* l2);
/*
 */