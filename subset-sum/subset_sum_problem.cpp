#include<bits/stdc++.h>
using namespace std;
void subset(int arr[],int n,int k,vector<int>&ans,int sum,int ite){
if(sum==k){
for(int i=0;i<ans.size();k++)
cout<<ans[i]<<" ";
cout<<endl;
ans.pop_back();
sum-=arr[ite];
subset(arr,n,k,ans,sum,ite+1);
return ;
}
else if(sum>k)
return ;
else{
for(int i=ite;i<n;i++){
sum+=arr[i];
ans.push_back(arr[i]);
subset(arr,n,k,ans,sum,i+1);
}
}
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
int k;
cin>>k;
vector<int>ans;
subset(arr,n,k,ans,0,0);
}
