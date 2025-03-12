/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution {
public:
    int Max = 0;
    int findMax(vector<int> &nums){
        for(int i = 0;i < nums.size(); ++i){
            Max = max(Max, nums[i]);
        }
        return Max;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = findMax(nums);
        int left = 0, cnt = 0;
        long long res = 0;
        for(auto x : nums){
            if(x == maxEle) cnt++;

            while(cnt >= k){
                if(nums[left] == x) cnt--;
                left++;
            }
            res += left;           
        }
        return res;
    }
};
// @lc code=end

