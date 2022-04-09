//Milan Mundhra
//20JE0564
//.cpp file run in linux
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
const int inf = 2100000000;
int main()
{
    int n,m;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;

    int c[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        c[i][j]=inf;

    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cout<<"Edge "<<i<<"--\n";
        cout<<"Enter the edge u v [u->v]: ";
        cin>>a>>b;
        cout<<"Enter the edge weight from "<<a<<"->"<<b<<": ";
        cin>>w;
        adj[a].pb(b);
        c[a][b]=min(c[a][b],w);
    }

    int src,des;
    cout<<"Enter source: ";
    cin>>src;
    cout<<"Enter destination: ";
    cin>>des;

    vector<int> order;
    order.pb(0);
    vector<int> level(n+1,0);
    vector<vector<int>> stage(n+1);
    int stages=1;
    queue<int> q;
    q.push(src);
    level[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        stage[level[u]].pb(u);
        stages=max(stages,level[u]);
        for(auto v: adj[u])
        {
            if(level[v]==0)
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    cout<<"Nodes in different stages are as follows--\n";
    for(int i=1;i<=stages;i++)
    {
        cout<<"Stage "<<i<<": ";
        for(int j=0;j<stage[i].size();j++)
        {
             cout<<stage[i][j]<<" ";
             order.pb(stage[i][j]);
        }
        cout<<"\n";

    }


    vector<int> cost(n+1),d(n+1),p(stages+1);
    cost[order[n]]=0;
    for(int i=n-1;i>=1;i--)
    {
        int mini=inf;
        int a=order[i];
        for(int j=i+1;j<=n;j++)
        {
            int b=order[j];
            if(c[a][b]!=inf && c[a][b]+cost[b]<mini)
            {
                mini=c[a][b]+cost[b];
                d[i]=j;
            }
        }
        cost[a]=mini;
    }

    p[1]=1;
    for(int i=2;i<=stages;i++)
        p[i]=d[p[i-1]];

    for(int i=1;i<=stages;i++)
        p[i]=order[p[i]];

    cout<<"The minimum cost from "<<src<<"->"<<des<<" is = "<<cost[src]<<"\n";
    cout<<"The sequence of vertice in shortest path is--\n";
    for(int i=1;i<stages;i++)
        cout<<p[i]<<" -> ";

    cout<<p[stages]<<"\n";

}
