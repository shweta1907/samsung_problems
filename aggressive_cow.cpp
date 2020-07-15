#include<bits/stdc++.h>
using namespace std;
bool isPoss(int arr[],int n,int mid,int cows){
int count=1;
int start=0;
for(int i=1;i<n;i++){
int diff=arr[i]-arr[start];
if(diff>=mid){
count++;
if(count>=cows)
return true;
start=i;
}

}
return false;
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
sort(arr,arr+n);
int ans=INT_MIN;
int cows;
cin>>cows;
int l=0;
int r=arr[n-1]-arr[0];
while(l<=r){
int mid=l+(r-l)/2;
cout<<ans<<" "<<mid<<endl;
if(isPoss(arr,n,mid,cows)){
ans=max(ans,mid);
l=mid+1;
}
else r=mid-1;
}
cout<<ans;
}
