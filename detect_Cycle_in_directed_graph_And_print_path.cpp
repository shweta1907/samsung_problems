#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<int>dfs(vector<int>adj[],bool visited[],int src){
    visited[src]=true;
    ans.push_back(src);
for(auto it=adj[src].begin();it!=adj[src].end();it++){
    if(!visited[*it])
    dfs(adj,visited,*it);
}
return ans;
}
bool detect(vector<int>adj[],bool visited[],int src,bool recs[]){
    visited[src]=1;
    recs[src]=1;
for(auto it=adj[src].begin();it!=adj[src].end();it++){
    if(!visited[*it]&&detect(adj,visited,*it,recs))
         return true;;
    if(recs[*it])
         return true;
}
recs[src]=false;
return false;
}
bool detect_cycle(vector<int>adj[],int V){
     bool visited[V];
     bool recs[V];
     memset(visited,0,sizeof(visited));
     memset(recs,0,sizeof(recs));
for(int i=0;i<V;i++){
     if(!visited[i])
           if(detect(adj,visited,i,recs))
                 return true;
}
return false;
}
int main(){
int vertices,edges;
cout<<"enter vertices and edges"<<endl;
cin>>vertices>>edges;
vector<int>adj[vertices];
for(int i=0;i<edges;i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
}
bool ans=detect_cycle(adj,vertices);
if(ans==true)
cout<<"1";
else{
bool visited[vertices];
memset(visited,0,sizeof(visited));
vector<int>path=dfs(adj,visited,0);
for(int i=0;i<path.size();i++){
cout<<path[i]<<" ";
}
}
}
