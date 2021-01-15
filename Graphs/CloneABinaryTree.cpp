//Copy a Binary Tree using Hashing //
/*
Algorithn -
This code uses hashmap to map clone node to the original node.
First copy the left and right node, then copy the random Node
//Important for Interview point of view

*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* random;
};

Node* newNode(int val){
    Node* temp = new Node();
    temp->val = val;
    temp->left = temp->right = temp->random = NULL;
    return temp;
}
void Inorder(Node* node){
    if(node != NULL){
        Inorder(node->left);
        cout << "[" << node->val << " "; 
        if (node->random == NULL) 
            cout << "NULL], "; 
        else
            cout << node->random->val << "], ";
        Inorder(node->right);
    
    }
}

Node* CloneLeftRight(Node* treeNode, unordered_map<Node*, Node*> &myMap){
    if(treeNode == NULL) return NULL;
    Node* cloneNode = newNode(treeNode->val);
    myMap[treeNode] = cloneNode;
    cloneNode->left = CloneLeftRight(treeNode->left, myMap);
    cloneNode->right = CloneLeftRight(treeNode->right, myMap);
    return cloneNode;

}

void CopyRandom(Node* treeNode, Node* cloneNode, unordered_map<Node*, Node*> &myMap){
    if(treeNode == NULL) return;
    cloneNode->random = myMap[treeNode->random];
    CopyRandom(treeNode->left, cloneNode->left, myMap);
    CopyRandom(treeNode->right, cloneNode->right, myMap);
}

Node* CopyTree(Node* treeNode){
    if(treeNode == NULL) return NULL;
    unordered_map<Node*, Node*> mp;
    Node* newTree = CloneLeftRight(treeNode,mp);
    CopyRandom(treeNode,newTree,mp);
    return newTree;
}

int main() 
{ 
    //Test No 1 
    Node *tree = newNode(1); 
    tree->left = newNode(2); 
    tree->right = newNode(3); 
    tree->left->left = newNode(4); 
    tree->left->right = newNode(5); 
    tree->random = tree->left->right; 
    tree->left->left->random = tree; 
    tree->left->right->random = tree->right; 
  
    //  Test No 2 
    //    tree = NULL; 
  
    //  Test No 3 
    //    tree = newNode(1); 
  
    //  Test No 4 
    /*    tree = newNode(1); 
        tree->left = newNode(2); 
        tree->right = newNode(3); 
        tree->random = tree->right; 
        tree->left->random = tree; 
    */
  
    cout << "Inorder traversal of original binary tree is: \n"; 
    Inorder(tree); 
  
    Node *clone = CopyTree(tree); 
  
    cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
    Inorder(clone); 
  
    return 0; 
} 