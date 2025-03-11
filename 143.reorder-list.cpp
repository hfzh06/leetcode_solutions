/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL, *cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    ListNode* findMiddle(ListNode* head){
        ListNode* low = head, *fast = head, *pre = head;
        while(fast && fast->next){
            pre = low;
            low = low->next;
            fast = fast->next->next;
        }
        return pre;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head1;
        // ListNode* cur = pre_head;
        ListNode* head1tmp = head1;
        ListNode* head2tmp = head2;
        while(head1 && head2){
            
            // cur->next = head1;
            // head1 = head1->next;
            // cur = cur->next;
            // cur->next = head2;
            // head2 = head2->next;
            // cur = cur->next;
            head1tmp = head1->next;
            head2tmp = head2->next;
            
            head1->next = head2;
            head1 = head1tmp;
            if(head1 == NULL) break;;

            head2->next = head1;
            head2 = head2tmp;
        }

        // cur->next = nullptr;
        return pre_head->next;
    }
    void reorderList(ListNode* head) {
        
        ListNode* tmp = findMiddle(head);
        ListNode* mid = tmp->next;
        
        tmp->next = nullptr;
        
        ListNode* head2 = reverse(mid);
        merge(head, head2);
                
    }
};
// @lc code=end

