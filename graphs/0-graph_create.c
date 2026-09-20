#include <stdlib.h>
#include "graphs.h"

graph_t *graph_create(void)
{
    graph_t *graph;

    graph = calloc(1, sizeof(graph_t));
    if (!graph)
        return (NULL);
    return (graph);
}