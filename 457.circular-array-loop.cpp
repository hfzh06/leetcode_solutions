/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:

    int nextIndex(vector<int>& nums, int index){
        int n = nums.size();
        return ((index + nums[index]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        bool flag = false;
        for(int i = 0; i < n; ++ i){
            int low = i;
            int fast = nextIndex(nums, i);
            while(nums[low] * nums[fast] > 0 && nums[low] * nums[nextIndex(nums, fast)] > 0){
                if(low == fast){
                    if(low == nextIndex(nums, low)) break; //这不是很明白
                    flag = true;
                    return true;
                }
                low = nextIndex(nums, low);
                fast = nextIndex(nums, nextIndex(nums, fast));

            }
            // i = low;
        }

        return false;
    }
};
// @lc code=end

