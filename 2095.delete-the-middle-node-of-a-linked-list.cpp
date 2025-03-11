/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* findMiddle_pre(ListNode* head){
        ListNode* low = head, *fast = head, *pre = head;
        while (fast && fast->next){
            pre = low;
            low = low->next;
            fast = fast->next->next;
        }
        
        return pre;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next){
            return NULL;
        }

        
        ListNode* pre = findMiddle_pre(head);
        ListNode* tar = pre->next;
        if(tar->next) pre->next = tar->next;
        else pre->next = NULL;
        return head;
    }
};
// @lc code=end

