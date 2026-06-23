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
        if(head == NULL || head->next ==NULL) return head;
        ListNode* temp = head;
        ListNode* tail = head;
        int n = 0; //length of ll
        //Finding length of list
        while(temp!=NULL){
            n++;
            if(temp->next == NULL) tail = temp;
            temp = temp->next;
        }
        k = k%n;
        if(k==0) return head;
        // now hme temp ko (n-k)th position pe place krna hai
        temp = head;
       for(int i = 1 ;i<n-k;i++){
        temp = temp->next;
       }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};