#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct BstNode{
	long long int data;
	BstNode* left;
	BstNode* right;
};
BstNode* root;
BstNode* GetNewNode(long long int x){
	BstNode* newnode = new BstNode();
	newnode->data=x;
	newnode->left=newnode->right=NULL;
	return newnode;
}
BstNode* Insert(BstNode* root,long long int x){
	if(root == NULL)
	root= GetNewNode(x);
	else
	{
		if(x<=root->data)
		root->left=Insert(root->left,x);
		else
		root->right=Insert(root->right,x);
	}
	return root;
}
void LevelOrder(BstNode* root){
	if(root == NULL)
	return ;
  else{
    queue<BstNode*> qu;
  	qu.push(root);
  	while(!qu.empty()){
  	root=qu.front();
		qu.pop();
  	cout<<root->data<<" ";
		if(root->left)
  	qu.push(root->left);
  	if(root->right)
  	qu.push(root->right);
  	}
  }
	}
int main() {
	// your code goes here
	root=NULL;
	int i,N,temp;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>temp;
		root=Insert(root,temp);
	}
	LevelOrder(root);
	return 0;
}
