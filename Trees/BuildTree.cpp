// Given the Preorder and Inorder traversal sequence of a Binary Tree, build the tree.

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
     TreeNode * build(vector<int> &preorder, int ip, int jp, vector<int> &inorder, int ii, int ji){
        if(jp<ip || ji<ii) return nullptr;
        
        int root = preorder[ip];
        if(ip==jp) return new TreeNode(root);

        int i;
        for(i=ii; i<=ji; i++){
            if(inorder[i]==root) break;
        }

        int j = ip + i - ii;
        TreeNode* left  = build(preorder, ip+1, j, inorder, ii, i-1); 
        TreeNode* right = build(preorder, j+1, jp, inorder, i+1, ji); 
        
        return new TreeNode(root, left, right);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    } 
};

int main(){
    int n;  
    cout<<"Enter the number of elements in the tree: ";
    cin>>n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    cout << "\nPreorder traversal:";
    for(int i=0; i<n; i++){
        cin>>preorder[i];
    }
    cout << "\nInorder traversal:\n";
    for(int i=0; i<n; i++){
        cin>>inorder[i];
    }
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    // level order traversal of obtained tree
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
    return 0;
}