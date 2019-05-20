#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/time.h>

#define V 20

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d /t/t %d\n", i+1, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
     int dist[V];
     bool sptSet[V];
     src--;
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


     dist[src] = 0;


     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);


       sptSet[u] = true;


       for (int v = 0; v < V; v++)


         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolution(dist, V);
}

double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    srand(time(NULL));
    int graph[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<i;j++){
            graph[i][j]=rand() %10;
            graph[i][i]=0;
            graph[j][i]=graph[i][j];
        }
    }
    graph[0][0]=0;
    printf("   ");
    for(int i=0;i<20;i++)
        printf("%3d",i+1);
    printf("\n");
    printf("   ");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    for(int i=0;i<V;i++){
            printf("%2d| ",i+1);
        for(int j=0;j<V;j++){
          printf(" %d ", graph[i][j]);
        }
        printf("\n\n");
    }

    double time = wtime();
    dijkstra(graph, 1);
    time = wtime() - time;

    printf("Time: %f\n", time);
    return 0;
}
