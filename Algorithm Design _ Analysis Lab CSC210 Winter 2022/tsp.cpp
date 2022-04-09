#include<bits/stdc++.h>
using namespace std;
//Milan Mundhra
//20JE0564
//.cpp file run in linux
#define int long long
int n,s;
int ans=INT_MAX;
vector<int> par;
void tsp(int cost,int pos,vector<int> & vis,vector<vector<int>> &graph,int count){

      if(count==n && graph[pos][s]!=-1){
        int curr=ans;
        ans=min(ans,cost+graph[pos][s]);
        if(curr>ans) par[s]=pos;
        return ;
      }
      for(int i=1;i<=n;i++){
        if(!vis[i] && graph[pos][i]!=-1){
          vis[i]=1;
          int currans=ans;
          tsp(cost+graph[pos][i],i,vis,graph,count+1);
          if(ans<currans) par[i]=pos;
          vis[i]=0;
        }
      }
}
int32_t main(){

    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    int m;
    cin>>m;
    vector<vector<int>> graph (n+1,vector<int> (n+1,-1));
    cout<<"Enter the edges as vertex vertex weight format\n";
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
      int a,b,cost;
      cin>>a>>b>>cost;
      graph[a][b]=cost;
      graph[b][a]=cost;
    }
    cout<<"Enter the source vertex\n";
    cin>>s;
    par.resize(n+1,-1);
    vis[s]=1;
    tsp(0,s,vis,graph,1);
    cout<<"Minimum tour tsp path= "<<ans<<endl;
    int curr=par[s];
    cout<<"Path = ";
    cout<<s<<" ";
     while(curr!=s){
      cout<<curr<<" ";
      curr=par[curr];
    }
  return 0;
}
