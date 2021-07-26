#include<iostream>
using namespace std;

void heapAdjust(int a[] , int i , int n)
{
      int key=a[i];
      int j=2*i;
      while(j<=n)
      {
            if(j<n and a[j]<a[j+1])       /*4 3 1 6 5 2
                                            5 4 2 6 3 1          */

                  j=j+1;
            if(key>=a[j]) break;
            a[j/2]=a[j];
            j*=2;
      }
      a[j/2]=key;
}
void heapify(int a[] , int n)
{

      for(int i=n/2 ; i>=1 ; --i)
      {
            heapAdjust(a , i , n);
      }
}
void heap_sort(int a[] , int n)
{
      heapify(a , n);
      cout<<"Max Heap: ";
      for(int i=1 ; i<=n ; ++i) cout<<a[i]<<" ";
      cout<<endl;
      int k=1;
      int t=1;
      for(int i=n ; i>=2 ; --i)
      {

            int temp=a[k];
            a[k]=a[i];
            a[i]=temp;
            heapAdjust(a , k , i-1);
            cout<<"pass "<<t++<<":";
            for(int i=1 ; i<=n ; ++i) cout<<a[i]<<" ";
            cout<<endl<<endl;

      }
}
int main()
{
    int n;
    cin>>n;
    n+=1;
    int a[n];
    for(int i=1 ; i<n ; ++i)
    {
          cin>>a[i];
    }
    heap_sort(a , n-1);
    cout<<"sorted array : ";
    for(int i=1 ; i<n ; ++i)
      cout<<a[i]<<" ";
    cout<<endl;

}
