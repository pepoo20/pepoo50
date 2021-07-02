#ifndef Header _h
#define  Header _h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Tnode {
    int data;
    Tnode* next;
    Tnode* prev;
};
struct Tlist {
    Tnode* tail;
    Tnode* head;
};
struct BackUpdata {
    Tlist list;
    string Command;
    Tnode* now;
};

void Addhead(Tlist& l, Tnode* node);
void addfirst(Tlist& l, int x);
void addtail(Tlist& l, int x);
void addAt(Tlist& l, int position, int x);
void Addhead(Tlist& l, Tnode* node);
Tlist InitialiseList();
Tnode* InitialiseNode();
void AddAtTailOfList(Tlist& l, Tnode* node);
void readListFromFile(Tlist& l);
void PrintList(Tlist l);
void DelAt(Tlist& l, int position);
#endif
