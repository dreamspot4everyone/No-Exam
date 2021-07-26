#include<iostream>
#include "queuelink (1).cpp"
using namespace std;

int v;
int graph[100][100];
int visited[100]={0};

void bfs(int n)
{
    queue Q;
    visited[n]=1;
    Q.enqueue(n);
    while(!Q.isempty())
    {
        int i=Q.dequeue();
        char c=i+65;
        cout<<c<<"  ";
        for(int w=0;w<v;++w)
        {
            if(graph[i][w]==1)
            {
                if(visited[w]!=1)
                {
                    visited[w]=1;
        	        Q.enqueue(w);
                }
            }
        }
    }
}

int main()
{
    cout<<"Enter number of vertices"<<endl;
    cin>>v;
    for(int i=0;i<v;++i)
    {
        for(int j=0 ; j<v ; ++j)
            cin>>graph[i][j];
    }
    int m;
    cout<<"Enter the starting vertex: ";
    cin>>m;
    cout<<"BFS is: "<<endl;
    bfs(m);
    return 0;
}

/*
vertex: 7
0 1 0 1 0 0 0
1 0 1 1 0 1 1
0 1 0 1 1 1 0
1 1 1 1 0 0 0
0 0 1 1 0 0 1
0 1 1 0 0 0 0
0 1 0 0 1 0 0

A  B  D  C  F  G  E
*/
