#include<bits/stdc++.h>
using namespace std;
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int board[10][10];
bool isSafe(int i,int j,int n){
if(i>=0&&i<n&&j>=0&&j<n&board[i][j]==-1)
return true;
else return false;
}
bool knightmove(int i,int j,int n,int k){
if(k==n*n)
return 1;
for(int l=0;l<8;l++){
if(isSafe(i+xMove[l],j+yMove[l],n)){
board[i+xMove[l]][j+yMove[l]]=k;
if(knightmove(i+xMove[l],j+yMove[l],n,k+1))
return true;
else
board[i+xMove[l]][j+yMove[l]]=-1;
}
}
return 0;
}
int main(){
int n;
cin>>n;
memset(board,-1,sizeof(board));
board[0][0]=0;
if(knightmove(0,0,n,1)){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++)
cout<<board[i][j]<<" ";
cout<<endl;
}
}
else
cout<<"-1";
}
