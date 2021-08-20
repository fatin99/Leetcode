#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree
void preorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the left subtree
    preorder(root->left);
 
    // Traverse the right subtree
    preorder(root->right);
}
 
// Iterative function to perform preorder traversal on the tree by pushing only the left children to the stack
void preorderIterativeLeft(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}
 
// Iterative function to perform preorder traversal on the tree by pushing only the right children to the stack
void preorderIterativeRight(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // if the current node exists, print it and push its right child
        // to the stack before moving to its left child
        if (curr != nullptr)
        {
            cout << curr->data << " ";
 
            if (curr->right) {
                stack.push(curr->right);
            }
 
            curr = curr->left;
        }
        // if the current node is null, pop a node from the stack
        // set the current node to the popped node
        else {
            curr = stack.top();
            stack.pop();
        }
    }
}

// Recursive function to perform inorder traversal on the tree
void inorder(Node* root)
{
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    inorder(root->left);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the right subtree
    inorder(root->right);
}

// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

// Recursive function to perform postorder traversal on the tree
void postorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    postorder(root->left);
 
    // Traverse the right subtree
    postorder(root->right);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
}

// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}