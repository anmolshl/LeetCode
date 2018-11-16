//
// Created by Anmol Singh on 2018-11-15.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


#endif //LEETCODE_SOLUTION_H
