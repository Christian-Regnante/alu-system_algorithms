#include "graphs.h"

/**
 * graph_delete - Completely deallocates a graph
 * @graph: Pointer to the graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex;
	vertex_t *next_vertex;
	edge_t *edge;
	edge_t *next_edge;

	if (!graph)
		return;

	for (vertex = graph->vertices; vertex; vertex = next_vertex)
	{
		next_vertex = vertex->next;
		for (edge = vertex->edges; edge; edge = next_edge)
		{
			next_edge = edge->next;
			free(edge);
		}
		free(vertex->content);
		free(vertex);
	}
	free(graph);
}
