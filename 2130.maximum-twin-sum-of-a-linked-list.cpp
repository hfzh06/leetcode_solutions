/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    stack<int> s;
    ListNode* findMiddle(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = findMiddle(head);
        int maxSum = -1;
        while(mid){
            maxSum = max(maxSum, s.top() + mid->val);
            s.pop();
            mid = mid->next;
        }
        return maxSum;
    }
};
// @lc code=end

