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
	printf("结点个数：%d\n", BinaryTreeSize(tree));
	printf("叶子结点个数：%d\n", BinaryTreeLeafSize(tree));
	printf("第k层结点树：%d\n", BinaryTreeLevelKSize(tree, 2));
	printf("层数：%d\n", BinaryTreeDepth(tree));
	BinaryTreeLevelOrder(tree);
	printf("满二叉树判断：%d\n", BinaryTreeComplete(tree));
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}

