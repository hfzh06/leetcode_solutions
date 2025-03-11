/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre_head = new ListNode(-1);
        pre_head->next = head;
        ListNode* low = pre_head;
        ListNode* fast = head;
        while(fast && fast->next){
            if(fast->val == fast->next->val){
                int x = fast->val;
                while(fast && fast->val == x){
                    fast = fast->next;
                }
                low->next = fast;
            }
            else{
                low = low->next;
                fast = fast->next;
            }
        }
        
        return pre_head->next;
    }
};
// @lc code=end

