//given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
//the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump).
//A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) with cost as the number of jumps taken.
// Given a source and destination, the frog has to reach the destination minimizing the cost (jump).
#include<bits/stdc++.h>
using namespace std;
bool visited[10][10];
int arr[10][10];
int m,n;
bool isSafe(int i,int j){
if(i<n&&i>=0&&j>=0&&j<m&&visited[i][j]==false)
return 1;
return 0;
}
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int z[4]={0,0,1,1};
void func(int sx,int sy,int dx,int dy,int n,int m,int &cost,int curr){
if(sx==dx&&sy==dy){
cost=min(cost,curr+1);
//cout<<"heyyyyyyyyyy";
return ;
}
for(int i=0;i<4;i++){
if(isSafe(sx+x[i],sy+y[i])&&arr[sx+x[i]][sy+y[i]]==1){
visited[sx+x[i]][sy+y[i]]=1;
//cout<<sx+x[i]<<" "<<sy+y[i]<<" "<<i<<" "<<curr<<endl;
func(sx+x[i],sy+y[i],dx,dy,n,m,cost,curr+z[i]);
visited[sx+x[i]][sy+y[i]]=0;
}
}
return ;
}
int main(){
cin>>n>>m;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
cin>>arr[i][j];
}
}
memset(visited,0,sizeof(visited));
int sx,sy,dx,dy;
cin>>sx>>sy>>dx>>dy;
int cost=INT_MAX;
visited[sx][sy]=true;
func(sx,sy,dx,dy,n,m,cost,0);
cout<<cost<<endl;
}
