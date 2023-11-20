//Stefano Calheiros Stringhini - 2312123
//Victor Ribeiro Calado - 2313553

/*
Construa um programa para o algoritmo de menor caminho seguindo a matriz
de adjacência do grafo. Entrega, até o fim do dia 20/11
 int graph[V][V] = {{0, 1, 4, 0, 0, 0},
 {1, 0, 4, 2, 7, 0},
 {4, 4, 0, 3, 5, 0},
 {0, 2, 3, 0, 4, 6},
 {0, 7, 5, 4, 0, 7},
 {0, 0, 0, 6, 7, 0}
 };
*/

#include <stdio.h>
#define V 6
#define INF 99999

void printSolution(int dist[], int n){
    printf("Vertice   Distancia da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++){
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V-1; count++){
        int min = INF, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == 0 && dist[v] <= min)
                min = dist[v], min_index = v;
        int u = min_index;
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}

int main(){
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                        {1, 0, 4, 2, 7, 0},
                        {4, 4, 0, 3, 5, 0},
                        {0, 2, 3, 0, 4, 6},
                        {0, 7, 5, 4, 0, 7},
                        {0, 0, 0, 6, 7, 0}
                        };
    dijkstra(graph, 0);
    return 0;
}