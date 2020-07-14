#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
TreeNode *left,*right;
int data;
TreeNode(int data){
this->data=data;
this->left=NULL;
this->right=NULL;
}
};
void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
TreeNode * insert1(TreeNode *root,int data){
if(root==NULL){
TreeNode *p=new TreeNode(data);
return p;
}
if(data<root->data)
root->left=insert1(root->left,data);
else
root->right=insert1(root->right,data);
return root;
}
void kthLargest(TreeNode *root,int k,int &ans){
if(root==NULL||k<=0)
return ;
kthLargest(root->right,k,ans);
if(k==0){
ans=root->data;
}
k--;
kthLargest(root->left,k,ans);
}
int main(){
int n;
cin>>n;
TreeNode *root=nullptr;
for(int i=0;i<n;i++){
   int k;
   cin>>k;
   root=insert1(root,k);
}
int k;
cin>>k;
inorder(root);
int ans=-1;
kthLargest(root,k,ans);
cout<<ans<<endl;
}
