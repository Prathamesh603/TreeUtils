// some functions of treeutils :-

#include "tree_utils.h"
#include<iostream>
using namespace std;
int main() {
    node * root=NULL;
    node * root2=NULL;
    Build_from_LOT(root);
    levelOrder(root);
    cout<<endl;
    inorder(root);
    preorder(root);
    postorder(root);
    isBalance(root);
    Build_from_LOT(root2);
    isIndentical(root,root2)?cout<<"Identiacal":cout<<"not identical";
    cout<<getHeight(root);
    return 0;

}   


