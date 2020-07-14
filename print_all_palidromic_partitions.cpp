#include<bits/stdc++.h>
using namespace std;
bool ispal(string str, int low, int high){
    while (low < high){
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
void myfunc(string s,vector<vector<string>>&ans,vector<string>&x,int start,int end){
if(start>end){
ans.push_back(x);
return ;
}
for(int i=start;i<=end;i++){
if(ispal(s,start,i)){
x.push_back(s.substr(start,i-start+1));
myfunc(s,ans,x,i+1,end);
x.pop_back();
}
}
}
int main(){
string s="beb";
vector<vector<string>>ans;
vector<string>x;
myfunc(s,ans,x,0,s.length()-1);
for(int i=0;i<ans.size();i++){
for(int j=0;j<ans[i].size();j++)
cout<<ans[i][j]<<" ";
cout<<endl;
}
}
