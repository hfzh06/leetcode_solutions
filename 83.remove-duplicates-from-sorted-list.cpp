/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            if(fast->val == fast->next->val){
                int x = fast->val;
                while(fast && fast->val == x){
                    fast = fast->next;
                }
                slow->next = fast;
            }
            else{
                fast = fast->next;
            }
            slow = fast;
        } 
        return pre_head->next;
    }
};
// @lc code=end

