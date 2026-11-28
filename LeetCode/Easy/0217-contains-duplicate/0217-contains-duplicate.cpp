class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // 일일이 숫자를 저장하지 말고,
        // *** 정렬을 한 뒤, 인접한 숫자들끼리만 확인하기
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size() -1 ; i++)
        {
            // 만약 동일한 값이 2개 이상 있다면, 분명 인접해있을 것이므로
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};