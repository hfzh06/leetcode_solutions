/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 *
 * [3305] Count of Substrings Containing Every Vowel and K Consonants I
 */

// @lc code=start
class Solution {
public:
    string s = "aeiou";
    int solve(string word, int k){
        unordered_map<char, int> cnt1;
        int cnt2 = 0;
        int left = 0;
        int res = 0;
        for(auto x : word){
            if(s.find(x) != string::npos) {
                cnt1[x]++;
            }
            else {
                cnt2++;
            }
            while(cnt1.size() == 5 && cnt2 >= k){
                if(s.find(word[left]) != string::npos){
                    cnt1[word[left]]--;
                    if(cnt1[word[left]] == 0){
                        cnt1.erase(word[left]);
                    }
                }
                else{
                    cnt2--;
                }

                left++;
            } 
            res += left;
        }
        return res;
    }
    int countOfSubstrings(string word, int k) {
        return solve(word, k) -solve(word, k + 1);
    }
};
// @lc code=end

