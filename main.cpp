

#include <iostream>
#include "Header.h"
int main(int argc, const char* argv[]) {
    Tlist l;
    int p, k,d;
    readListFromFile(l);
    PrintList(l);
    cin.ignore();
    cout << "Moi ban nhap vi tri muon them " << endl;
    cin >> p;
    cout << "gia tri muon them:" << endl;
    cin >> k;
    cout << "Nhap vi tri muon xoa node:";
    cin >> d;
    addAt(l, p, k);
    PrintList(l);
    DelAt(l, d);
    return 1;
}
