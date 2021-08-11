/**
 * @file heightOfBinaryTree.cpp
 * @brief 
 * Height of binary tree considering even level leaves only
 * Find the height of the binary tree given that only the nodes on the even levels are considered as the valid leaf nodes.
 * The height of a binary tree is the number of edges between the tree’s root and its furthest leaf. 
 * But what if we bring a twist and change the definition of a leaf node.
 * Let us define a valid leaf node as the node that has no children and is at an even level (considering root node as an odd level node).
 * @version 0.1
 * @date 2021-08-11
 *  
 */
#include "header.h"

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int evenRowHeightUtil(struct Node *root,bool isEven){
    if (!root)
        return 0;
    if  (!root->left && !root->right){
        if(isEven)
            return 1;
        return 0;
    }
    int left = evenRowHeightUtil(root->left, !isEven);
    int right = evenRowHeightUtil(root->right, !isEven);
    if (left==0 && right==0){
        return 0;
    }
    return 1 + max(left, right);
}

struct Node* newNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int evenRowHeight(Node *root){
    return evenRowHeightUtil(root, false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    cout << "Height of tree is " << evenRowHeight(root);
    return 0;
}