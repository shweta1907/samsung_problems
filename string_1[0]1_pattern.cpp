/*Given a string, your task is to find the number of patterns of form 1[0]1 where [0] represents any number of zeroes (minimum requirement is one 0) there should not be any other character except 0 in the [0] sequence.

Input:

The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string.

Output:

For each test case, output the number of patterns.

Constraints:

1<=T<=20

1<=Length of String<=2000
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int count=0;
char last=s[0];
for(int i=1;i<s.length();i++){
if(s[i]=='0'&&last=='1'){
while(s[i]=='0'&&i<s.length())
i++;
if(i<s.length()&&s[i]=='1')
count++;
}
last=s[i];
}
cout<<count<<endl;
}
