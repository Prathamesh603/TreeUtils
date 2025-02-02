#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};


node* BuildTree(node *root);
void levelOrder(node *root);
void inorder(node *root);
void  preorder(node *root);
void postorder(node *root);
void Build_from_LOT(node *&root);
int countLeaf(node *root);
pair<bool, int> balanceCheck(node *root);
void isBalance(node *root);
bool isIndentical(node *r1, node *r2);
pair<bool, int> sum(node *root);
bool isSumTree(node *root);
int getHeight(node * root);

#endif 
