#include <bits/stdc++.h>
using namespace std;

struct node{
    int p;
    int d;
    int j;
};

//first descend second descend
bool custom_sort(node a, node b)
{
   if(a.p == b.p)
   {
      return a.d > b.d;
   }
   return a.p > b.p;
}
int main()
{
    int n;
    cout<<"Enter the no of jobs: ";
    cin>>n;

    vector<node> v(n+1);
    int max_dead=0;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nFor Job "<<i<<"\n";
        cout<<"----------------\n";
        cout<<"Enter Profit: ";
        cin>>v[i].p;
        cout<<"Enter Deadline: ";
        cin>>v[i].d;
        v[i].j=i;
        max_dead=max(max_dead,v[i].d);
    }

    sort(v.begin()+1,v.end(),custom_sort);
    vector<int> sched(max_dead+1,0);

    int profit=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i].d;j>=1;j--)
        {
            if(sched[j]==0)
            {
                sched[j]=v[i].j;
                profit+=v[i].p;
                break;
            }
        }
    }

    cout<<"\nThe task scheduling is as follows\n";
    cout<<"-----------------------------------\n";
    for(int i=1;i<=max_dead;i++)
    {
        cout<<i-1<<"-"<<i<<": Job ";
        if(sched[i]==0)
            cout<<"No Job";
        else
            cout<<sched[i];

        cout<<"\n";
    }
    cout<<"-------------------------------------\n";
    cout<<"Total profit = "<<profit<<"\n";

}
