//Given a Binary Tree and a node x in it, find the distance of the closest leaf to x in Binary Tree. If given node itself is a leaf, then the distance is 0.
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
int data;
TreeNode *left;
TreeNode *right;
TreeNode(int data){
this->data=data;
this->left=NULL;
this->right=NULL;
}
};
void my_func(TreeNode *root,int &len,int curr){
if(root==NULL)
return ;
if(len>curr&&root->left==NULL&&root->right==NULL){
len=curr;
return ;
}

my_func(root->right,len,curr+1);
my_func(root->left,len,curr+1);
return ;
}
int from_parent(TreeNode *root,TreeNode *x,int &len){
if(root==NULL)
return -1;
if(root==x)
return 0;
int lef=from_parent(root->left,x,len);
//if it is not -1 it means that we found it in left subtree so lets call for leaf in right
if(lef!=-1){
my_func(root->right,len,lef+2);
return lef+1;
}
int ri=from_parent(root->right,x,len);
if(ri!=-1){
my_func(root->left,len,ri+2);
return ri+1;
}
return -1;
}
int minimumDistance(TreeNode *root,TreeNode *x){
 int len=INT_MAX;
 my_func(x,len,0);
 from_parent(root,x,len);
 return len;
}
int main(){
TreeNode *root  = new TreeNode(1);
    root->left  = new TreeNode(12);
    root->right = new TreeNode(13);

    root->right->left   = new TreeNode(14);
    root->right->right  = new TreeNode(15);

    root->right->left->left   = new TreeNode(21);
    root->right->left->right  = new TreeNode(22);
    root->right->right->left  = new TreeNode(23);
    root->right->right->right = new TreeNode(24);

    root->right->left->left->left  = new TreeNode(1);
    root->right->left->left->right = new TreeNode(2);
    root->right->left->right->left  = new TreeNode(3);
    root->right->left->right->right = new TreeNode(4);
    root->right->right->left->left  = new TreeNode(5);
    root->right->right->left->right = new TreeNode(6);
    root->right->right->right->left = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);

    TreeNode *x = root->right;

    cout<<minimumDistance(root,x);
}
