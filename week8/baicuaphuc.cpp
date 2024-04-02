#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
int find(node *root,int x){
    if (root == NULL) return 0;
    if(root->data==x) return 1;
    node *p = root;
    if(p->left!=NULL) return find(p->left,x);
    if (p != NULL) return 1;
    return find(root->right,x);   
}
void insertleft(node *root,int u,int v){
    
    if(root==NULL) return;
    if(find(root,u)==1 || find(root,v)==0){
        return ;
    }
    else if(root->data==v){
        if(root->left==NULL){
            root->left=new node(u);
        }
    }
    else{
        insertleft(root->left,u,v);
        insertleft(root->right,u,v);
    }
}
void insertright(node *root,int u,int v){
    
    if(root==NULL) return;
    if(find(root,u)==1 || find(root,v)==0){
        return ;
    }
    else if(root->data==v){
        if(root->right==NULL){
            root->right=new node(u);
        }
    }
    else{
        insertright(root->left,u,v);
        insertright(root->right,u,v);
    }
}
void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=new node(1);
    insertleft(root,2,1);
    insertright(root,3,1);
    cout<<find(root,3);
    preorder(root);

}

