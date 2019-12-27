/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
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
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if (l1 == NULL && l2 == NULL)
        //     return NULL;
        // else if (l1 == NULL)
        //     return l2;
        // else if (l2 == NULL)
        //     return l1;
        // else {
        //     ListNode* res = NULL;
        //     ListNode* res_2 = NULL;
        //     ListNode* p_l1 = l1;
        //     ListNode* p_l2 = l2;
            
        //     while (!(p_l1 == NULL || p_l2 == NULL)) {
        //         ListNode* next = NULL;
                
        //         if (p_l1 -> val < p_l2 -> val) {
        //             next = new ListNode(p_l1 -> val);
        //             p_l1 = p_l1 -> next;
        //         }
        //         else {
        //             next = new ListNode(p_l2 -> val);
        //             p_l2 = p_l2 -> next;
        //         }

        //         if (res == NULL) {
        //             res = next;
        //             res_2 = next;
        //         }
        //         else {
        //             res_2 -> next = next;
        //             res_2 = next;
        //         }
        //     }

        //     if (p_l1 == NULL)
        //         res_2 -> next = p_l2;
        //     else
        //         res_2 -> next = p_l1;
            
        //     return res;
        // }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 ->next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }

        if (l1)
            cur -> next = l1;
        else
            cur -> next = l2;
        
        ListNode* res = dummy -> next;
        delete dummy;
        return res;
    }
};

