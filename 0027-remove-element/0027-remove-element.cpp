class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // in-place가 뭔가요?

        // 새 배열을 만들지 않고, 주어진 배열 nums 자체를 수정해서 해결하라는 뜻입니다. (추가 메모리 O(1))

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                i -= 1;
            }

        }
        
        return nums.size();
    }
};