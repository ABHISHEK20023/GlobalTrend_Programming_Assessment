
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preorder(TreeNode* root,string &temp){
        if(root==nullptr) {
            temp+="N ";
            return;
        }
        temp+=to_string(root->val)+" ";
        preorder(root->left,temp);
        preorder(root->right,temp);
    }

    TreeNode* preorderDe(istringstream &d){
        string node;
        d>>node;
        if(node=="N") return nullptr;
        TreeNode* root=new TreeNode(stoi(node));
        root->left=preorderDe(d);
        root->right=preorderDe(d);
        return root;

    }
    string serialize(TreeNode* root) {
        string temp;
        preorder(root,temp);
        return temp;
    }

    TreeNode* deserialize(string data) {
        istringstream d(data);
         return preorderDe(d);
        // return nullptr;
    }
};



void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode *deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
