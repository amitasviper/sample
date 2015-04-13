#include <iostream>
#include <stdio.h>
#include <climits>
#include <omp.h>

#define V 5

using namespace std;

int minKey(int key[],bool mstSet[])
{
	int min=INT_MAX;
	int min_index;


	#pragma omp parallel num_threads(V)
	{
		#pragma omp parallel for
		for(int v=0;v<V;v++)
		{
			if(mstSet[v]==false && key[v]<min)
			{
				#pragma omp critical
				{
					min=key[v];
					min_index=v;
				}
			}
		}
	}
	return min_index;
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	#pragma omp parallel for
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstSet[i]=false;
	}

	key[0]=0;
	parent[0]=-1;


	for(int count=0;count<V-1;count++)
	{
		int u=minKey(key,mstSet);

		//cout<<"u = "<<u<<endl;

		mstSet[u]=true;


		#pragma omp parallel for
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
			{
				#pragma omp critical
				{
					parent[v]=u;
					key[v]=graph[u][v];
				}
			}
		}
	}

	cout<<"Edge-----Weight\n";
	for(int i=1;i<V;i++)
	{
		printf("%d-----%d    %d\n",parent[i],i,graph[i][parent[i]] );
	}
}

int main()
{
	int graph[V][V]={{0,2,0,6,0},
					 {2,0,3,8,5},
					 {0,3,0,0,7},
					 {6,8,0,0,9},
					 {0,5,7,9,0},};
	primMST(graph);
}