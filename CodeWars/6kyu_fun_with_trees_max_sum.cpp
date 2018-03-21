class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
        if (!root)
        {
          return 0;
        }
        auto r = maxSum(root->right) + root->value;
        auto l = maxSum(root->left) + root->value;
        return r > l ? r : l;
    }
};