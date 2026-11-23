class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == target)
            {
                return i;
            }
        }
        // 만약 없다면, 정렬된 순서로 삽입될 위치의 인덱스를 찾기
        int index = -1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > target)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            index = nums.size();
        }

        return index;
    }
};