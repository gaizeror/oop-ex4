#include <iostream>
#include "allClasses_copy.h"

int main() {
    Mammals m1("Pink", 5, 5.0, 5.0, 2.3);
    int b = m1.GetChildCount();
    cout << b;
}