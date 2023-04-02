// TODO: Add any extra #includes that you need

#include "graph.h"
#include "pagerank.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free etc ..
#include <stddef.h> // for defining NULL
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>


// TODO: Add your data structure definitions
//***need Vertex, Edge, GraphRepr:

typedef struct Vertex {
    string name;
    struct Edge *edges;
    size_t num_edges;
} Vertex;


typedef struct Edge {
    Vertex *dest;
    weight w;
    struct Edge *next;
} Edge;


typedef struct GraphRepr {
    Vertex **vertices;
    size_t num_vertices;
} GraphRepr;


// need also a helper function to find a vertex by name
static Vertex *find_vertex(graph g, string name) {
    for (size_t i = 0; i < g->num_vertices; i++) {
        if (strcmp(g->vertices[i]->name, name) == 0) {
            return g->vertices[i];
        }
    }
    return NULL;
}



// TODO: Fill in these function stubs
graph graph_create(void) {
    GraphRepr * g = malloc(sizeof(GraphRepr));
    //check if malloc success:
    if (g == NULL) {
        return NULL;
    }
    //initialize g:
    g->vertices = NULL;
    g->num_vertices = 0;
    return g;
}


void graph_destroy(graph g) {
    //check whether g is NULL or:
    if (g == NULL) {
        return;
    }
    //loop throwgh vertices and their edges:
    for (size_t i = 0; i < g->num_vertices; i++) {
        Vertex *v = g->vertices[i];
        Edge *e = v->edges;
        while (e != NULL) {
            Edge *next = e->next;
            //free edges
            free(e);
            e = next;
        }
        //free name and vertix.
        free(v->name);
        free(v);
    }
    //free all g.
    free(g->vertices);
    free(g);
}


void graph_add_vertex(graph g, string v) {
    // check if the vertex already exists
    if (find_vertex(g, v) != NULL) {
        return;
    }
    // create a new vertex with the given name and add it to the graph
    Vertex *new_vertex = malloc(sizeof(Vertex));
    new_vertex->name = strdup(v);//duplicates a given string in memory and returns a pointer to the new string
    new_vertex->edges = NULL;
    new_vertex->num_edges = 0;
    //add to g:
    g->vertices = realloc(g->vertices, (g->num_vertices + 1) * sizeof(Vertex));
    g->vertices[g->num_vertices] = new_vertex;
    g->num_vertices++;
}


bool graph_has_vertex(graph g, string v) {
    return (find_vertex(g, v) != NULL);
}



size_t graph_vertices_count(graph g) {
    return g->num_vertices;
}


void graph_add_edge(graph g, string v1, string v2, weight w) {
    // find the vertices with the given names
    Vertex *vertex1 = find_vertex(g, v1);
    Vertex *vertex2 = find_vertex(g, v2);

    // if either vertex is not found, return without adding the edge
    if (vertex1 == NULL || vertex2 == NULL) {
        return;
    }

    // create a new edge with the given weight
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->dest = vertex2;
    new_edge->w = w;
    new_edge->next = NULL;

    // add the new edge to the tail of vertex1's list of edges
    if (vertex1->edges == NULL) {
        // if vertex1 is empty, set the new edge as its first edge
        vertex1->edges = new_edge;
    } else {
        // otherwise, traverse the list to get to the tail:
        Edge *current_edge = vertex1->edges;
        while (current_edge->next != NULL) {
            current_edge = current_edge->next;
        }
        current_edge->next = new_edge;
    }
    vertex1->num_edges++;
}
    // create a new edge with the given weight and add it to vertex2's list of edges
   /* new_edge = malloc(10*sizeof(Edge));
    new_edge->dest = vertex1;
    new_edge->w = w;
    new_edge->next = vertex2->edges;
    vertex2->edges = new_edge;
    vertex2->num_edges++;*/



bool graph_has_edge(graph g, string v1, string v2) {
    // find the vertices with the given names
    Vertex *vertex1 = find_vertex(g, v1);
    Vertex *vertex2 = find_vertex(g, v2);

    // icheck if the two vertices is found:
    if (vertex1 == NULL || vertex2 == NULL) {
        return false;
    }

    //heckif there is edge between the vertices
    Edge *edge = vertex1->edges;
    while (edge != NULL) {
        if (edge->dest == vertex2) {
            return true;
        }
        edge = edge->next;
    }
    return false;
}



void graph_update_edge(graph g, string v1, string v2, weight w) {
    graph_add_edge(g, v1, v2, w);
}



weight graph_get_edge(graph g, string v1, string v2) {
    Vertex *vertex1 = find_vertex(g, v1);
    if (vertex1 == NULL) {
        return 0.000; // or some other default weight
    }

    Edge *edge = vertex1->edges;
    while (edge != NULL) {
        if (strcmp(edge->dest->name, v2) == 0) {
            return edge->w;
        }
        edge = edge->next;
    }

    return 0.000; //or s ome other default weight
}






void graph_show(graph g, FILE *output) {
    if (g == NULL) {
        return;
    }
    // print the vertices
    for (size_t i = 0; i < g->num_vertices; i++) {
        fprintf(output, "%s\n", g->vertices[i]->name);
    }
    // print the edges
    for (size_t i = 0; i < g->num_vertices; i++) {
        Vertex *verrt = g->vertices[i];
        Edge *edge = verrt->edges;
        while (edge!= NULL) {
            fprintf(output, "%s %s %.3lf\n", verrt->name, edge->dest->name, edge->w);
            edge = edge->next;
        }
    }
}




void graph_pagerank(graph g, double damping, double delta) {
    // TODO: Delete the code below when you're ready to implement this function
    (void) g;
    (void) damping;
    (void) delta;
    return;
}

void graph_show_pagerank(graph g, FILE *file) {
    // TODO: Delete the code below when you're ready to implement this function
    (void) g;
    (void) file;
    return;
}

void graph_worst_path(graph g, string source, double damping, double delta) {
    // TODO: Delete the code below when you're ready to implement this function
    (void) g;
    (void) source;
    (void) damping;
    (void) delta;
    return;
}

void graph_show_path(graph g, string destination) {
    // TODO: Delete the code below when you're ready to implement this function
    (void) g;
    (void) destination;
    return;
}









