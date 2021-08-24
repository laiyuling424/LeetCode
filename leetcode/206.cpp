//
// Created by 赖於领 on 2021/8/16.
//



#include <iostream>

using namespace std;


//反转链表

//优化 new ListNode(ptr->val);

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    void print(ListNode *head) {
        cout << "head:";
        while (head) {
            cout << head->val << ",";
            head = head->next;
        }
        cout << endl;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *new_head = new ListNode();
        ListNode *ptr = head;
        ListNode *temp;

        while (ptr) {

            temp = new ListNode(ptr->val);

            if (new_head->next) {
                temp->next = new_head->next;
                new_head->next = temp;
            } else {
                new_head->next = temp;
            }

            ptr = ptr->next;
        }
        print(new_head);
        return new_head->next;
    }

//    ListNode *reverseList(ListNode *head) {
//        ListNode *new_head = NULL;
//        ListNode *ptr = head;
//
//        while (ptr) {
//            ListNode* next = ptr->next;
//            ptr->next = new_head;
//            new_head = ptr;
//            ptr = next;
//        }
//        print(new_head);
//        return head;
//    }
};


//int main() {
//    Solution *solution = new Solution();
//    //head = [1,2,6,3,4,5,6], val = 6
////    ListNode *seventh = new ListNode(6);
////    ListNode *sixth = new ListNode(5, seventh);
//    ListNode *fifth = new ListNode(5);
//    ListNode *fourth = new ListNode(4, fifth);
//    ListNode *thrid = new ListNode(3, fourth);
//    ListNode *second = new ListNode(2, thrid);
//    ListNode *head = new ListNode(1, second);
//    solution->reverseList(head);
//    return 0;
//}

