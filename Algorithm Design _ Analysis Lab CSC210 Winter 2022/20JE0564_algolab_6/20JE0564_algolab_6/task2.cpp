#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
const int inf = 1e9;
int main()
{
    int n;
    cout<<"Enter the no of nodes: ";
    cin>>n;
    int m;
    cout<<"Enter the no of edges: ";
    cin>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cout<<"For edge "<<i<<":\n";
        cout<<"Enter u v for [u->v]: ";
        cin>>u>>v;
        cout<<"Enter the weight of edge from "<<u<<"->"<<v<<": ";
        cin>>w;
        adj[u].pb({v,w});
    }
    cout<<"Enter the source node: ";
    int s;
    cin>>s;
    clock_t t1,t2;
    t1=clock();
    vector<int> d(n+1, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});

    while(!pq.empty())
    {
        int v = pq.top().second;
        int curr = pq.top().first;
        pq.pop();

        if(d[v] < curr)
           continue;

        d[v] = curr;
        for(auto it:adj[v])
        {
            int u = it.first;
            int w = it.second;
            if(d[u] > d[v] + w)
            {
                d[u] = d[v] + w;
                pq.push({d[u], u});
            }
        }
    }
    t2=clock();

    for(int i=1;i<=n;i++)
    {
        cout<<"Distance to node "<<i<<"=";
        if(d[i]==inf)
            cout<<"Non reachable\n";
        else
            cout<<d[i]<<"\n";
    }

    cout<<"Computation time is = "<<((float)(t2-t1))<<" microseconds\n";

}
