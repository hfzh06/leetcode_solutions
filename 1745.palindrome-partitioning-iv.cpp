/*
 * @lc app=leetcode.cn id=1745 lang=cpp
 *
 * [1745] Palindrome Partitioning IV
 */

// @lc code=start
class Solution {
public:
    bool check(string s){
        string tmp = s;
        reverse(s.begin(), s.end());
        if(tmp == s)
            return true;
        else
            return false;
    }
    bool checkPartitioning(string s) {
        bool flag = false;
        for(int i = 1; i < s.length() -1; ++ i){
            for(int j = i; j < s.length() - 1; ++ j){
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i + 1);
                string s3 = s.substr(j+1, s.length() - j -1);
                if(check(s1) && check(s2) && check(s3)) {
                    flag = true;
                    return true;
                }
                        
            }

        }


        
        return false;
    }
};
// @lc code=end

