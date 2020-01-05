/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstddef>

// struct ListNode {
//     int val;
//     ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next != NULL && fast->next->next == NULL) slow = slow->next;

        return slow;
    }
};
// @lc code=end

