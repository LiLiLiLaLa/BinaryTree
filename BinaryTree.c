#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

BTNode* BuyNewNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x; 
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

//����һ�Ŷ�����
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)//aΪ��Ÿ��ڵ����ݵ����飬n�涨���鳤�ȣ�pi�����������±��ָ��
{
	if ((a[*pi] != '#') && ((*pi) < n))//��ֹ���������Խ��
	{
		BTNode* root = BuyNewNode(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
		return NULL;
}

//����һ��������
void BinaryTreeDestory(BTNode** root)
{
	//��Ϊ��
	if (root == NULL || *root == NULL)
	{
		return;
	}
	//ֻ��һ�����
	if ((*root)->_left != NULL)
	{
		BinaryTreeDestory(&((*root)->_left));
	}
	//����ڵ�
	if ((*root)->_right != NULL)
	{
		BinaryTreeDestory(&((*root)->_right));
	}
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
}

int BinaryTreeLeafSize(BTNode* root)
{
	//����
	if (root == NULL)
	{
		return 0;
	}
	//ֻ��һ���ڵ�
	if (root->_right == NULL&&root->_right == NULL)
	{
		return 1;
	}
	//����ڵ�
	else
	{
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	}
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//����
	if (root == NULL)
	{
		return 0;
	}
	//��һ��
	if (k == 1)
	{
		return k;
	}
	//����
	else
	{
		return(BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1));
	}
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//����ֵΪx�Ľڵ�ĵ�ַ
{
	BTNode* ret = NULL;
	if (root == NULL || root->_data == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret != NULL)
	{
		return ret;
	}
	return BinaryTreeFind(root->_right, x);
}

int BinaryTreeDepth(BTNode* root)
{
	int leftDepth = 0;
	int rightDepth = 0;
	if (root == 0)
	{
		return 0;
	}
	leftDepth = BinaryTreeDepth(root->_left) + 1;
	rightDepth = BinaryTreeDepth(root->_right) + 1;
	return leftDepth > rightDepth ? leftDepth : rightDepth;
}

// ����
void BinaryTreePrevOrder(BTNode* root)//ǰ�����
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		return;
	}
	if (root->_left != NULL)
	{
		BinaryTreeInOrder(root->_left);
	}
	printf("%c", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		return;
	}
	if (root->_left != NULL)
	{
		BinaryTreePostOrder(root->_left);
	}
	if (root->_right!= NULL)
	{
		BinaryTreePostOrder(root->_right);
	}
	printf("%c", root->_data);
}

void BinaryTreePrevOrderNonR(BTNode* root)//ǰ�����,�ǵݹ�
{
	BTNode* cur = root;
	BTNode* top;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			printf("%c", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		StackPop(&s);
		cur = top->_right;
	}
}

void BinaryTreeInOrderNonR(BTNode* root)//����������ǵݹ�
{
	BTNode* cur = root;
	BTNode* top;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		StackPop(&s);
		printf("%c", top->_data); 
		cur = top->_right;
	}
}

void BinaryTreePostOrderNonR(BTNode* root)//����������ǵݹ�
{
	BTNode* cur = root;
	BTNode* top;
	BTNode* prev = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 0)
	{
		QUDataType front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	printf("\n");
}


int BinaryTreeComplete(BTNode* root)//�ж���������
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
	}
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	return 0;
}