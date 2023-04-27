#include "file.h"
#include <vector>
#include <iostream>

int Node::countNodes = 0;/*написать функции, которые будут работать между классом и кодом
 переопределить оператор вывода (<<)
 */
void LinkedList::push_back(int nameNode) {
    if (Head == nullptr) {
        Head = new Node();
        Tail = new Node();
        Head->prev == nullptr;
        Head->next = Tail;
        Tail->prev = Head;
        Tail->next = nullptr;
        Head->nameNode = nameNode;
        Node::countNodes++;
        return;//заканчиваем выполнение функции
    }
    Tail->next = new Node();
    Node* t = Tail->next;
    Tail->nameNode = nameNode;
    t->prev = Tail;
    t->next = nullptr;
    Tail = t;
    Node::countNodes++;
}
void LinkedList::writeToFileFromTail() {
    FILE* fout = fopen("result_task6_Tail", "w");
    Node* p = Tail->prev;
    while (p != nullptr) {
        fprintf(fout, "%d; ", p->nameNode);
        p = p->prev;
    }
    fclose(fout);
}
void LinkedList::writeToFileFromHead() {
    FILE* fout = fopen("result_task6_Head", "w");
    Node* p = Head;
    while (p->next != nullptr) {
        fprintf(fout, "%d; ", p->nameNode);
        p = p->next;
    }
    fprintf(fout, "\n");
    fclose(fout);
}
Node* LinkedList::GetHead(){
    return Head;
}

int& LinkedList::operator[](int index) {//придумать второй(правильный способ), который понравится Денису Алексеевич
    Node *p = Head;
    for (int i = 0; i < index; i++) {
        if(p->next == nullptr){
            push_back(0);
        }
        p = p->next;
    }
    if(p->next == nullptr)//работает некорректно
        push_back(index);
    return p->nameNode;
}
bool LinkedList::operator==(LinkedList l1){//функцию, которая возвращает Head. сам Head дописать в private
    Node* p1 = l1.GetHead();
    Node* p2 = Head;
    while(p1->next != nullptr || p2->next != nullptr){
        if(p1->nameNode != p2->nameNode){
            return false;
        }
        if(p1->next == nullptr || p2->next == nullptr){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
};
void LinkedList::operator=(LinkedList& l1/*откуда*/){
    Node* p2_from = l1.Head;
    deletelist();
    while(p2_from->next != nullptr){
        push_back(p2_from->nameNode);
        p2_from = p2_from->next;
    }
}

void LinkedList::deletenode(Node* l) {
    delete l;
}
void LinkedList::deletelist() {
    Node* p = Head;
    Node* d = p->next;
    while (d != nullptr) {
        delete(p);
        p = d;
        d = p->next;
    }
    Head = nullptr;
}

void print(LinkedList* l1){
    Node* p = l1->GetHead();
    while( p->next != nullptr){
        printf("%d\t", p->nameNode);
        p = p->next;
    }
}
Node* insert(Node* p/*куда*/, Node* pnext/*что*/){
    pnext->next = p->next;
    p->next = pnext;
    return pnext;
}
void meagell(LinkedList* l1, LinkedList* l2){
    Node* chet = l1->GetHead();
    Node* nech = l2->GetHead();
    while(chet->next != nullptr || nech->next != nullptr) {
        if (chet->next && (chet->nameNode | 0x01)) {//проверка, что число нечетное
            Node *f = chet->next;
            chet->next = f->next;
            nech = insert(nech, f);
            continue;
        }
        if (chet->next && (chet->nameNode | 0x01)) {
            chet = chet->next;
            continue;
        }
        if (nech->next && (nech->nameNode & 0x01)) {//проверка, что число четное
            Node *f = nech->next;
            nech->next = f->next;
            chet = insert(chet, f);
            continue;
        }
        nech = nech->next;
    }
}

