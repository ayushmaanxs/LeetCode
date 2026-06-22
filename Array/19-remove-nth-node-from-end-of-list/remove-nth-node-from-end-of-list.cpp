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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp = temp-> next;
        }
        int del;
        del = size - n + 1;
        if(size == 1) {
            head = NULL;
            return head;
        }
        else if(n == size){
            head = head->next;
            return head;
        }
        int count = 1;
        temp = head;
        while(count!=del-1){
            temp = temp->next;
            count ++;
        }
        temp->next = temp->next->next;
        return head;
    }
};