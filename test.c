#include "BinaryTree.h"

void TestBinaryTree()
{
	BTDataType a[] = { 'A', 'B', '#', 'C', '#', '#', 'D', 'E', '#', 'F', '#', 'G', '#', '#', 'H', '#', '#' };
	int len = sizeof(a) / sizeof(a[0]);
	int index = 0;
	BTNode* tree = BinaryTreeCreate(a, len, &index);
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreeInOrderNonR(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreePostOrderNonR(tree);
	printf("\n");
	printf("��������%d\n", BinaryTreeSize(tree));
	printf("Ҷ�ӽ�������%d\n", BinaryTreeLeafSize(tree));
	printf("��k��������%d\n", BinaryTreeLevelKSize(tree, 2));
	printf("������%d\n", BinaryTreeDepth(tree));
	BinaryTreeLevelOrder(tree);
	printf("���������жϣ�%d\n", BinaryTreeComplete(tree));
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}

