#include<bits/stdc++.h>
using namespace std;
#define V 4
void tsp(int graph[][V],bool visited[],int curr,int n,int count,int cost,int &ans){
if(count==n&&graph[curr][0]){
ans=min(ans,cost+graph[curr][0]);
return ;
}
for(int i=0;i<n;i++){
if(!visited[i]&&graph[curr][i]){
visited[i]=true;
tsp(graph,visited,i,n,count+1,cost+graph[curr][i],ans);
visited[i]=false;
}

}
}
int main(){
int n=4;
int graph[][V] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };
bool visited[n];
memset(visited,0,sizeof(visited));
visited[0]=true;
int ans=INT_MAX;
tsp(graph,visited,0,n,1,0,ans);
cout<<ans;
}
