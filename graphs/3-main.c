#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

/**
 * main - Entry point to test graph_delete
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	graph_t *graph;

	graph = graph_create();
	if (!graph)
	{
		fprintf(stderr, "Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	/* Build a small graph with vertices and edges */
	graph_add_vertex(graph, "San Francisco");
	graph_add_vertex(graph, "Seattle");
	graph_add_vertex(graph, "New York");
	graph_add_vertex(graph, "Chicago");

	graph_add_edge(graph, "San Francisco", "Seattle", UNIDIRECTIONAL);
	graph_add_edge(graph, "San Francisco", "New York", BIDIRECTIONAL);
	graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL);
	graph_add_edge(graph, "New York", "Chicago", BIDIRECTIONAL);

	printf("=== Graph before deletion ===\n");
	graph_display(graph);
	printf("\n");

	/* Delete the whole graph */
	graph_delete(graph);
	graph = NULL;          /* avoid dangling pointer */

	printf("Graph successfully deleted.\n");
	/* After this point the graph is gone.
	 * You can run the program under valgrind to confirm
	 * there are no memory leaks:
	 *   valgrind ./3-graph_delete
	 */

	return (EXIT_SUCCESS);
}