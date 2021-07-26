#include <iostream>
using namespace std;


bool Place(int mat[][10],int i,int j,int n)
{
    for (int row=0;row<i;row++) // check column
    {
        if (mat[row][j]==1)
            return false;
    }

    int x=i;
    int y=j;
    while(x>=0 && y>=0) //check left diagonal
    {
        if (mat[x][y]==1)
            return false;
        x--;
        y--;
    }

    x=i;
    y=j;
    while(x>=0 && y<n) //check right diagonal
    {
        if (mat[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}

bool N_Queen (int mat[][10],int i,int n)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                    cout<<" Q ";
                else
                    cout<<" - ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false; //for all possible solution
    }

    for (int j=0;j<n;j++)
    {
        if(Place(mat,i,j,n))
        {
            mat[i][j]=1;
            bool next_queen=N_Queen(mat,i+1,n);
            if (next_queen)
                return true;
            mat[i][j]=0; // backtrack
        }
    }
    return false;
}


int main ()
{
    int n;
    cin>>n;
    int x[10][10]={0};
    N_Queen(x,0,n);
    return 0;
}





