#include<bits/stdc++.h>
using namespace std;
int n;
int visitedlocal[n][n];
int maze[n][n];
bool visitedpath[n][n];
int maximumjewels=INT_MIN;
void maximumJewels(int i,int j,int jewelCount){
if(i==n-1&&j==n-1){
if(maximumjewels<jewelCount+maze[i][j]){
maximumjewels=jewelCount+maze[i][j];
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
visitedpathinfo[i][j]=visitedlocal[i][j];
return ;
}
}

}
int main(){
cin>>n;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cin>>maze[i][j];
visited[i][j]=false;
visitedlocal[i][j]=maze[i][j];
}
}
visitedlocal[0][0]=3;
maximumJewels(0,0,0,visitedlocal);
}
