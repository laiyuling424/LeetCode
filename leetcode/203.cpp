//
// Created by 赖於领 on 2021/8/14.
//


#include <iostream>

using namespace std;

//移除链表元素


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

//    ListNode *removeElements(ListNode *head, int val) {
//        ListNode *ptr = head;
//        ListNode *next;
//        while (head) {
//            if (head->val == val) {
//                head = head->next;
//                ptr = ptr->next;
//            } else {
//                break;
//            }
//        }
//        while (head && (next = head->next)) {
//            if (next->val == val) {
//                head = head->next->next;
//            } else {
//                head = head->next;
//            }
//            print(ptr);
//        }
//        return ptr;
//    }
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *ptr = new ListNode();
        ListNode *temp = ptr;
        while (head) {
            if (head->val != val) {
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }
        print(ptr->next);
        return ptr->next;
    }

};

//int main() {
//    Solution *solution = new Solution();
//    //head = [1,2,6,3,4,5,6], val = 6
//    ListNode *seventh = new ListNode(6);
//    ListNode *sixth = new ListNode(5, seventh);
//    ListNode *fifth = new ListNode(4, sixth);
//    ListNode *fourth = new ListNode(3, fifth);
//    ListNode *thrid = new ListNode(6, fourth);
//    ListNode *second = new ListNode(2, thrid);
//    ListNode *head = new ListNode(1, second);
//    solution->removeElements(head, 6);
//    return 0;
//}

