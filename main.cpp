#include <iostream>

#include "Node.h"
#include "RBFS.h"

int main() {
    RBFS test;
    test.create_map();
    test.goal="Bucuresti";
    test.rbfs("None",test.nodes[1],999,"");

    return 0;
}