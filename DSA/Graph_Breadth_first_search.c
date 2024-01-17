#include<stdio.h>
#include<stdlib.h>
#define size 40

struct queue{
    int items[size];
    int front;
    int rear;
};

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

struct queue* createQueue(){
    struct queue* q = malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
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

int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct queue* q, int value) {
  if (q->rear == size - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue* q) {
    int i = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty");
    } 
    else {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

void bfs(struct Graph* graph, int StartVertex){
    struct queue* q= createQueue();

    graph->visited[StartVertex]=1;
    enqueue(q,StartVertex);

    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct node* temp= graph->adjlist[currentVertex];

        while(temp){
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex]==0){
                graph->visited[adjVertex]=1;
                enqueue(q,adjVertex);
            }
            temp=temp->next;
        }
    }
}

void main(){
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0);
}