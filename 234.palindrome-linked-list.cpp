/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    int get_len(ListNode* head){
        int cnt = 0;
        while(head){
            cnt ++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* FindMiddle(ListNode* head){
        ListNode* fast = head, *low = head;
        while (fast && fast->next){
            s.push(low->val);
            low = low->next;
            fast = fast->next->next;
        }
        s.push(low->val);
        return low;
    }
    bool isPalindrome(ListNode* head) {
        bool flag = true;
        ListNode *mid = FindMiddle(head);
        int len = get_len(head); 
        if(len % 2 == 0) s.pop();
        while(mid) {
            if(mid->val != s.top()) {
                flag = false;
                break;
            }
            mid = mid->next;            
            s.pop();
        }
        return flag;
    }
};
// @lc code=end

