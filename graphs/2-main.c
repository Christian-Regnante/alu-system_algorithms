#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

/**
 * main - Entry point to test graph_add_edge
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

	/* Add vertices */
	graph_add_vertex(graph, "San Francisco");
	graph_add_vertex(graph, "Seattle");
	graph_add_vertex(graph, "New York");
	graph_add_vertex(graph, "Chicago");
	graph_add_vertex(graph, "Houston");
	graph_add_vertex(graph, "Washington");

	printf("=== Graph before adding edges ===\n");
	graph_display(graph);
	printf("\n");

	/* Add edges */
	printf("Adding edges...\n");
	printf("SF -> Seattle          (UNI) : %d\n",
	       graph_add_edge(graph, "San Francisco", "Seattle", UNIDIRECTIONAL));
	printf("SF <-> New York        (BI)  : %d\n",
	       graph_add_edge(graph, "San Francisco", "New York", BIDIRECTIONAL));
	printf("Seattle -> Chicago     (UNI) : %d\n",
	       graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL));
	printf("Chicago <-> Houston    (BI)  : %d\n",
	       graph_add_edge(graph, "Chicago", "Houston", BIDIRECTIONAL));
	printf("New York -> Washington (UNI) : %d\n",
	       graph_add_edge(graph, "New York", "Washington", UNIDIRECTIONAL));

	/* Failure cases */
	printf("Non-existent vertex          : %d\n",
	       graph_add_edge(graph, "San Francisco", "Paris", UNIDIRECTIONAL));
	printf("NULL source                  : %d\n",
	       graph_add_edge(graph, NULL, "Seattle", UNIDIRECTIONAL));

	printf("\n=== Graph after adding edges ===\n");
	graph_display(graph);

		graph_display(graph);

	/* Temporary: free later when graph_delete is ready */
	return (EXIT_SUCCESS);
}