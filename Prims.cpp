#include <bits/stdc++.h>
using namespace std;
#define V 6

int minKey(int key[],bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int i=0;i<V;i++)
    {
		if (mstSet[i]==false && key[i]<min) // mstSet[i]==false -> not includes in output tree
        {
			min=key[i];
			min_index=i;
        }
    }
	return min_index;
}

void print(int parent[],int graph[V][V])
{
    cout<<"Result->"<<endl;
    for(int i=1;i<=V;i++)
    {
        if(parent[i]!=i)
        {
            cout<<char(parent[i] + 'A')<<"->"<<char(i+'A')<<endl;
        }
    }
}

void prim(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i=0;i<V;i++)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	for(int i=0;i<V;i++)
	{
		int u=minKey(key, mstSet);
		mstSet[u]=true;
		for (int v=0;v<V;v++)
		{
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
		}
	}
	print(parent, graph);
}

int main()
{

	fstream infile;
	infile.open("Prims_input.txt", ios::in);
	if (!infile)
	{
 		printf("\nError to open the file\n");
 		exit (1);
 	}
 	cout<<"Number of vertices in the given graph: "<<V<<endl;

 	int graph[V][V];
 	int i,j;
 	for(i=0;i<V;i++)
 	{
 		for(j=0;j<V;j++)
 		{
 			infile>>graph[i][j];
 		}
	}

	cout<<"Adjacency matrix of the given graph is: "<<endl;
	for(i=0;i<V;i++)
 	{
 		for(j=0;j<V;j++)
 		{
 			cout<<graph[i][j]<<" ";
 		}
 		cout<<endl;
	}
	cout<<endl;

	prim(graph);
	return 0;
}

/*
cout<<"Result:"<<endl;
	for (int i =1;i<V;i++)
		cout<<parent[i]<<" -> "<<i<<" \n";
		\*/
