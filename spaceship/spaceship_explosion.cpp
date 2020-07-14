/*There is one spaceship. X and Y co-ordinate of the source of spaceship and destination spaceship is given.
There is N number of wormholes; each wormhole has 5 values.
First 2 values are starting co-ordinate of the wormhole and after that value no. 3 and 4 represent ending co-ordinate of the wormhole
and last 5th value is represents a cost to pass through this wormhole. Now, these warmholes are bi-directional.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find the minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you won’t uses any warmhole.
*/
#include<bits/stdc++.h>
using namespace std;
class worm{
public:
int sx,sy,dx,dy,w;
};
class point{
public:
int x,y;
};
bool visited[100];
int n;
int c(point s,point d){
return abs(s.x-d.x)+abs(s.y-d.y);
}
void solve(point s,point d,int &ans,worm arr[],int cost){
ans=min(cost+c(s,d),ans);
for(int i=0;i<n;i++){
if(!visited[i]){
visited[i]=1;
point t1,t2;
t1.x=arr[i].sx,t1.y=arr[i].sy;
t2.x=arr[i].dx,t2.y=arr[i].dy;
cout<<"curr ans "<<ans<<" "<<iz<<endl;
solve(t2,d,ans,arr,cost+c(s,t1)+arr[i].w);
solve(t1,d,ans,arr,cost+c(s,t2)+arr[i].w);
visited[i]=0;
}
}
}
int main(){
point s,d;
cin>>s.x>>s.y>>d.x>>d.y;
cin>>n;
worm arr[n];
for(int i=0;i<n;i++){
cin>>arr[i].sx>>arr[i].sy>>arr[i].dx>>arr[i].dy>>arr[i].w;
}
int ans=INT_MAX;
memset(visited,0,sizeof(visited));
solve(s,d,ans,arr,0);
cout<<ans;
}
