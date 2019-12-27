/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow1 = head;
        ListNode* slow2 = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow1 = slow1->next;
            fast = fast->next->next;
            if (slow1 == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        while (slow1 != slow2) {
            slow1 = slow1->next;
            slow2 = slow2->next;
        }
        return slow1;
    }
};
// @lc code=end

