#include<bits/stdc++.h>
using namespace std;
int m,n;
int matrix[100][100];
int l;//probe length
int visited[100][100],depth[100][100];
//queue for bfs
class node{
    public:
    int x;
    int y;
    int d;
};
bool s1(int i,int j){
if(i>=0&&i<m&&j>=0&&j<n&&!visited[i][j]&&(matrix[i][j]==1||matrix[i][j]==3||matrix[i][j]==6||matrix[i][j]==7))
return true;
else return false;
}
bool s2(int i,int j){
if(i>=0&&i<m&&j>=0&&j<n&&!visited[i][j]&&(matrix[i][j]==1||matrix[i][j]==2||matrix[i][j]==4||matrix[i][j]==7))
return true;
else return false;
}
bool s3(int i,int j){
if(i>=0&&i<m&&j>=0&&j<n&&visited[i][j]==0&&(matrix[i][j]==1||matrix[i][j]==3||matrix[i][j]==4||matrix[i][j]==5))
return true;
else return false;
}
bool s4(int i,int j){
if(i>=0&&i<m&&j>=0&&j<n&&!visited[i][j]&&(matrix[i][j]==1||matrix[i][j]==2||matrix[i][j]==5||matrix[i][j]==6))
return true;
else return false;
}
void bfs(int x,int y,int d){
   queue<node> q;
   node p;
   p.x=x,p.y=y,p.d=d;
   q.push(p);
   while(q.size()>0){
   node temp=q.front();
   q.pop();
   int i=temp.x;
   int j=temp.y;
   int c=temp.d;
   depth[i][j]=c;
   if(matrix[i][j]==1||matrix[i][j]==3||matrix[i][j]==4||matrix[i][j]==5)
   if(s1(i,j+1))//check bhi krege ki upar wala and neeche wala connected hai kya
   {
   node n;
   n.x=i,n.y=j+1,n.d=c+1;
   q.push(n);
   }
   if(matrix[i][j]==1||matrix[i][j]==3||matrix[i][j]==6||matrix[i][j]==7)
   if(s3(i,j-1)){
   node n;
   n.x=i,n.y=j-1,n.d=c+1;
   q.push(n);
   }
   if(matrix[i][j]==1||matrix[i][j]==2||matrix[i][j]==4||matrix[i][j]==7)
   if(s4(i-1,j)){
   node n;
   n.x=i-1,n.y=j,n.d=c+1;
   q.push(n);
   }
   if(matrix[i][j]==1||matrix[i][j]==2||matrix[i][j]==5||matrix[i][j]==6)
   if(s2(i+1,j)){
   node n;
   n.x=i+1,n.y=j,n.d=c+1;
   q.push(n);
   }
   }
}
int main(){
int x,y;//start indexes
cin>>x>>y;
cin>>l;
cin>>m>>n;
//front1=0,rear=0;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>matrix[i][j];
}
}
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
visited[i][j]=0;
depth[i][j]=INT_MAX;
}
}

if(matrix[x][y]!=0)
bfs(x,y,1);
int nc=0;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(depth[i][j]<=l)
nc++;
}
}
cout<<nc<<endl;
}
