#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    struct node** adjlist;
    int* visited;
};

struct node* createNode(int v){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjlist = malloc(vertices * sizeof(struct node* ));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for(i=0;i<vertices;i++){
        graph->adjlist[i]= NULL;
        graph->visited[i]= 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    //edge from src to dest
    struct node* newnode = createNode(dest);
    newnode->next=graph->adjlist[src];
    graph->adjlist[src] = newnode;

    //edge from dest to src
    newnode = createNode(src);
    newnode->next=graph->adjlist[dest];
    graph->adjlist[dest] = newnode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjlist[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void dfs(struct Graph* graph, int vertex){
    struct node* adjList = graph->adjlist[vertex];
    struct node* temp = adjList;

    graph->visited[vertex]=1;
    printf("Visited %d \n", vertex);

    while(temp){
        int adjVertex = temp->vertex;
        if(graph->visited[adjVertex] == 0) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  dfs(graph, 2);

  return 0;
}

