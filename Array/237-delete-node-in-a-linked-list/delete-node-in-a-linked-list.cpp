/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // p -> node which we want to delete
        ListNode* p = node;
        // q -> next node of p
        ListNode* q = p->next;
        /*
            Since we cannot access previous node,
            we copy next node's value into current node.

            Example:

            Before:
            4 -> 5 -> 1 -> 9
                 p    q

            After copying:
            4 -> 1 -> 1 -> 9
        */
        p->val = q->val;
        /*
            Now remove q from linked list.

            p should directly point to node after q.

            Before:
            p -> q -> next

            After:
            p ------> next
        */
        p->next = q->next;

        /*
            Free memory of deleted node
        */
        delete(q);
    }
};