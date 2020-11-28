#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    Graph G;
    CreateEmptyGraph(&G);

    MakeGraph(&G, 4);
    AddLink(&G, 1, 2);
    AddLink(&G, 1, 3);
    AddLink(&G, 2, 4);
    AddLink(&G, 3, 4);

    PrintGraph(G);
    PrintLink(G, 1);
    PrintLink(G, 4);

    return 0;
}