/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        serialize_traverse(root,str);
        return str;
        
    }

    void serialize_traverse(TreeNode* root, string& str){
        if (root  == nullptr) {
            str+="null,";
            return;
        }

        str += to_string(root->val) + ',';
        serialize_traverse(root->left, str);
        serialize_traverse(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    // 将字符串转化成列表
    vector<string> nodes;
    stringstream ssin(data);
    string val;
    while (getline(ssin, val, ','))
        nodes.push_back(val);
    reverse(nodes.begin(), nodes.end());
    return deserialize1(nodes);
}

/* 辅助函数，通过 nodes 列表构造二叉树 */
    TreeNode* deserialize1(vector<string>& nodes) {
    if (nodes.empty()) return nullptr;

    /****** 前序位置 ******/
    // 列表最左侧就是根节点
    string first = nodes.back();
    nodes.pop_back();
    if (first == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(first));

    /***********************/

    root->right = deserialize1(nodes);
    root->left = deserialize1(nodes);

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

