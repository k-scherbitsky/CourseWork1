#include <iostream>
#include "Menu/menu.h"

using namespace std;

StackList *stackList = NULL;

int main() {
    stackList = createStack();
    menu(stackList);
    system("pause");
    return 0;
}