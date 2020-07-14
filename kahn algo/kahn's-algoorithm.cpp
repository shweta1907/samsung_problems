#include<bits/stdc++.h>
using namespace std;
class Graph{
int V;
vector<int>*adj;
public:
Graph(int V){
this->V=V;
adj=new vector<int>[V];
}
void addEdge(int u,int v){
adj[u].push_back(v);
}
void topologicalSort(){
int in_degree[V];
memset(in_degree,0,sizeof(in_degree));
  for(int i=0;i<V;i++){
  for(auto itr=adj[i].begin();itr!=adj[i].end();itr++){
  in_degree[*itr]++;
  }
  }
  queue<int>q;
  for(int i=0;i<V;i++){
  if(in_degree[i]==0)
  q.push(i);
}
int count=0;
vector<int>ans;
while(!q.empty()){
int front=q.front();
q.pop();
ans.push_back(front);
for(auto itr=adj[front].begin();itr!=adj[front].end();itr++){
in_degree[*itr]--;
if(in_degree[*itr]==0)
q.push(*itr);
}
count++;
}
if(count!=V)
cout<<"solution doesn't exist";
else{
for(int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";
}
}
};
int main(){
Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
}
