#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

//struct TreeNode
//{
//	TNDataType data;
//	struct TreeNode* childs[N];
//	SeqList childs; //->struct TreeNode*
//}; 

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;//左结点
	struct BinaryTreeNode* _right;//右结点
}BTNode;

// a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);//创建一颗二叉树
void BinaryTreeDestory(BTNode** root);//二叉树的销毁
int BinaryTreeSize(BTNode* root);//返回二叉树的节点数
int BinaryTreeLeafSize(BTNode* root);//返回二叉树的叶子节点数
int BinaryTreeLevelKSize(BTNode* root, int k);//返回第K层节点数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//返回值为x的节点的地址
// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历
void BinaryTreePrevOrderNonR(BTNode* root);//前序遍历
void BinaryTreeInOrderNonR(BTNode* root);//中序遍历
void BinaryTreePostOrderNonR(BTNode* root);//后序遍历
int BinaryTreeDepth(BTNode* root);//深度
void BinaryTreeLevelOrder(BTNode* root);//层遍历
int BinaryTreeComplete(BTNode* root);//判断满二叉树

void TestBinaryTree();