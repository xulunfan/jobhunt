/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sum(TreeNode* root){
    if(!root) return 0;
    return sum(root->left)+sum(root->right)+root->val;
}
unordered_map<int,int>allTreeSUm(TreeNode* root){
    unordered_map<int,int>m;
    if(!root) return m;
    unordered_map<int,int>lm=allTreeSUm(root->left);
    unordered_map<int,int>rm=allTreeSUm(root->right);
    for(auto it=lm.begin();it!=lm.end();it++){
        m[it->first]=it->second+rm[it->first];
    }    
    for(auto it=rm.begin();it!=rm.end();it++){
        m[it->first]=it->second+lm[it->first];
    }
    m[sum(root)]++;
    return m;
}
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int>m=allTreeSUm(root);
        int maxcnt=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second > maxcnt) maxcnt=it->second;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second == maxcnt){
                ans.emplace_back(it->first);
            }
        }        
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().findFrequentTreeSum(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
