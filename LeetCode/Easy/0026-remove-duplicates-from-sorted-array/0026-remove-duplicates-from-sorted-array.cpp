class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int preventNum = 999;
        vector <int> answers;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != preventNum)
            {
                preventNum = nums[i];
                answers.push_back(nums[i]);
            }
        }
        nums.clear();
        nums = answers;

        return answers.size();
    }
};