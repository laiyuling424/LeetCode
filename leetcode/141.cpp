//
// Created by 赖於领 on 2021/8/13.
//


#include <vector>
#include <iostream>

using namespace std;

// 环形链表


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next && slow->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
