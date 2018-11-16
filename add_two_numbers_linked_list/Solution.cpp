//
// Created by Anmol Singh on 2018-11-15.
//

#include "Solution.h"

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    int first_sum = l1->val + l2->val;
    int carry = 0, nodeVal = 0;
    if(first_sum >= 10){
        nodeVal = first_sum - 10;
        carry = 1;
    } else{
        nodeVal = first_sum;
    }
    ListNode* sum = new ListNode(nodeVal);
    ListNode* trav = sum;
    nodeVal = 0;
    while(l1->next != nullptr || l2->next != nullptr) {
        if(l1->next != nullptr && l2->next != nullptr) {
            l1 = l1->next;
            l2 = l2->next;
            first_sum = l1->val + l2->val + carry;
            if(first_sum >= 10){
                nodeVal = first_sum - 10;
                carry = 1;
            } else{
                nodeVal = first_sum;
                carry = 0;
            }
            trav->next = new ListNode(nodeVal);
            trav = trav->next;
            nodeVal = 0;
        } else if(l1->next != nullptr && l2->next == nullptr) {
            l1 = l1->next;
            first_sum = l1->val + carry;
            if(first_sum >= 10){
                nodeVal = first_sum - 10;
                carry = 1;
            } else{
                nodeVal = first_sum;
                carry = 0;
            }
            trav->next = new ListNode(nodeVal);
            trav = trav->next;
            nodeVal = 0;
        } else if(l2->next != nullptr && l1->next == nullptr) {
            l2 = l2->next;
            first_sum = l2->val + carry;
            if(first_sum >= 10){
                nodeVal = first_sum - 10;
                carry = 1;
            } else{
                nodeVal = first_sum;
                carry = 0;
            }
            trav->next = new ListNode(nodeVal);
            trav = trav->next;
            nodeVal = 0;
        }
    }
    if(carry == 1){
        trav->next = new ListNode(carry);
    }
    return sum;
}
