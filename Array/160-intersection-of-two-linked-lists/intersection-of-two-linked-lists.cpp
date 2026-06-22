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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != NULL || tempB != NULL) {
            if (tempA != NULL) {
                tempA = tempA->next;
                lenA++;
            }
            if (tempB != NULL) {
                tempB = tempB->next;
                lenB++;
            }
        }
        tempA = headA;
        tempB = headB;
        while (abs(lenA - lenB) > 0) {
            if (lenA > lenB) {
                tempA = tempA->next;
                lenA--;
            } else if (lenA < lenB) {
                tempB = tempB->next;
                lenB--;
            }
        }
        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};