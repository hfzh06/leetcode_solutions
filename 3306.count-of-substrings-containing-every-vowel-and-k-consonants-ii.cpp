/*
 * @lc app=leetcode.cn id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */

// @lc code=start
class Solution {
public:
    string vowels = "aeiou";
    long long solve(string word, int k) {
        unordered_map<char,int> charCount;
        int cnt = 0;
        int left = 0;
        long long res = 0;
        for(auto x : word) {
            if(vowels.find(x) != string::npos){
                charCount[x]++;
            }
            else{
                cnt++;
            }
            while(charCount.size() == 5 && cnt >= k){
                if(vowels.find(word[left]) != string::npos) {
                    charCount[word[left]]--;
                    if(charCount[word[left]] == 0){
                        charCount.erase(word[left]);
                    }
                }
                else{
                    cnt--;
                }
                left++;
                
            }
            res += left;
        }
        return res;
        
    }
    long long countOfSubstrings(string word, int k) {
        
        return solve(word, k) - solve(word, k + 1);
    }
};
// @lc code=end

