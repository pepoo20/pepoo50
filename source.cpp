//
//  source.cpp
//  đồ án
//
//  Created by admin on 7/2/21.
//

#include "Header.h"
Tlist InitialiseList() {
    Tlist l;
    l.head = l.tail = 0;
    return l;
}
Tnode* InitialiseNode() {
    Tnode* node = new Tnode;
    node->next = node->prev = 0;
    return node;
}
void AddAtTailOfList(Tlist& l, Tnode* node) {
    if (l.head == NULL) {
        l.tail = l.head = node;
    }
    else {
        l.tail->next = node;
        node->prev = l.tail;
        l.tail = node;
    }
}
void Addhead(Tlist& l, Tnode* node) {
    if (l.head == NULL) {
        l.head =l.tail = NULL;
    }
    else
    {
        node->next = l.head;
        l.head = node;
    }
}
void addfirst(Tlist& l,int x)
{
    Tnode* a;
    a = InitialiseNode();
    a->data = x;
    if (l.head == NULL)
    {
        l.head = a;
        l.tail = l.head;
    }
    else
    {
        a->next = l.head;
        l.head = a;
    }
}
void addtail(Tlist& l,int x) {
    Tnode* a, * p;
    a = InitialiseNode();
    a->data = x;
    if (l.head == NULL) {
        l.head = a;
    }
    else {
        p = l.head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = a;
    }
}
void addAt(Tlist& l, int position, int x) {
    if (position == 0 || l.head == NULL) {
        addfirst(l,x);
    }
    else {
        int k = 1;
        Tnode* p = l.head;
        while (p != NULL && k != position) {
            p = p->next;
            ++k;
        }
        if (k != position) {
            addtail(l,x);
        }
        else {
            Tnode* temp;
            temp = InitialiseNode();
            temp->data = x;
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void DelAt(Tlist& l, int position) {
    if (position == 0 || l.head == NULL || l.head->next == NULL) {
        return;
    }
    else {
        int k = 1;
        Tnode* p = l.head;
        while (p->next->next != NULL && k != position) {
            p = p->next;
            ++k;
        }
        if (k != position) {
            cout << "vi tri vuot qua so luong node trong list" << endl;
            return;
        }
        else {
            Tnode* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

}
void readListFromFile(Tlist& l) {
    ifstream f;
    f.open("input.txt",ios_base::in);
    if (f.fail()) {
        cout << "ko the mo file:" << endl;
    }
    while (!f.eof()) {
        Tnode* node = InitialiseNode();
        f >> node->data;
        Addhead(l, node);
    }
    f.close();
}
void PrintList(Tlist l) {
    Tnode* p;
    cout << "Xuat danh sach:";
    for (p = l.head; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

