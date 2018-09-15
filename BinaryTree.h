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
	struct BinaryTreeNode* _left;//����
	struct BinaryTreeNode* _right;//�ҽ��
}BTNode;

// a��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);//����һ�Ŷ�����
void BinaryTreeDestory(BTNode** root);//������������
int BinaryTreeSize(BTNode* root);//���ض������Ľڵ���
int BinaryTreeLeafSize(BTNode* root);//���ض�������Ҷ�ӽڵ���
int BinaryTreeLevelKSize(BTNode* root, int k);//���ص�K��ڵ���
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//����ֵΪx�Ľڵ�ĵ�ַ
// ����  �ݹ�&�ǵݹ�
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������
void BinaryTreePrevOrderNonR(BTNode* root);//ǰ�����
void BinaryTreeInOrderNonR(BTNode* root);//�������
void BinaryTreePostOrderNonR(BTNode* root);//�������
int BinaryTreeDepth(BTNode* root);//���
void BinaryTreeLevelOrder(BTNode* root);//�����
int BinaryTreeComplete(BTNode* root);//�ж���������

void TestBinaryTree();