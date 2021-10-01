#include<stdio.h>
#define V 4
#define INF 99999

void printSolution(int d[][V]);
void floydWarshall (int graph[][V])
{
	int d[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			d[i][j] = graph[i][j];


	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	printSolution(d);
}

void printSolution(int d[][V])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (d[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", d[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int graph[V][V] = {{0, 3, INF, 5},
                       {2, 0, INF, 4},
                       {INF, 1, 0, INF},
                       {INF, INF, 2, 0}
                    };
	floydWarshall(graph);
	return 0;
}