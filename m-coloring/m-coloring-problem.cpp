#include<bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int color[])
{
    printf(
        "Solution Exists:"
        " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}
bool isSafe( int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
bool solutionExist(bool graph[V][V],int m,int color[],int i){
if(i==V){
return true;
}
for(int c=1;c<=m;c++){
if(isSafe(i,graph,color,c)){
color[i]=c;
if(solutionExist(graph,m,color,i+1))
return true;
color[i]=0;
}
}
return false;
}
bool graphColoring(bool graph[V][V],int m){
int color[V];
  memset(color,0,sizeof(color));
  if(!solutionExist(graph,m,color,0))
  cout<<"solution doesnt exist";
  else printSolution(color);
  //else return true;
}
int main(){
bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m=3;
    graphColoring(graph,m);
}
