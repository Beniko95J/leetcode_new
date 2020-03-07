/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int res = 0;
        while (i < n && j < n && res < n) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            if (j >= n) {
                nums[res] = nums[i];
                res++;
                break;
            }
            else {
                nums[res] = nums[i];
                i = j;
                res++;
            }
        }

        return res;
        // heap overflow !!!!!!!!!

        // int pre = 0;
        // int cur = 0;
        // int n = nums.size();
        // while (cur < n) {
        //     if (nums[cur] == nums[pre]) cur++;
        //     else nums[++pre] = nums[cur++];
        // }

        // return nums.empty() ? 0 : pre + 1;
    }
};

// int main(int argc, char** argv) {
//     Solution s;
//     vector<int> nums{1,1,2};
//     s.removeDuplicates(nums);

//     return 0;
// }

