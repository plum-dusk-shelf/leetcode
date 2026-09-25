/*
Runtime
O(n)
0ms
Beats
100.00%

Memory
O(1)
14.91MB
Beats
47.22%
*/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallDummy = new ListNode(0), *bigDummy = new ListNode(0);
        ListNode *smallHead = smallDummy, *bigHead = bigDummy;

        while(head){
            if (head->val < x){
                smallHead->next = head;
                smallHead = smallHead->next;
            } else {
                bigHead->next = head;
                bigHead = bigHead->next;
            }
            head = head->next;
        }

        bigHead->next = nullptr;
        smallHead->next = bigDummy->next;
        return smallDummy->next;
    }
};
