/*
Runtime
O(n)
0ms
Beats
100.00%

Memory
O(1)
16.37MB
Beats
63.82%
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head, *slow, *dummy;
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        int length = 1;
        while (fast->next){
            fast = fast->next;
            length++;
        }
        k = k % length;
        for (k; k>0; k--){
            fast = head; slow = head;
            while (fast->next){
                length++;
                if (slow == fast){
                    fast = fast->next;
                } else{
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            fast->next = head;
            head = fast;
            slow->next = nullptr;
        }
        return head;        
    }
};
