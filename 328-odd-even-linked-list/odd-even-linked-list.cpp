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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = NULL;
        ListNode* evenHead = NULL;
        if(odd->next){
            even = odd->next;
            evenHead = even;
        } 
        while(odd->next && even->next){
            odd->next = even->next;
            odd=odd->next;
            even->next = odd->next;
            if(even->next)
                even=even->next;
        }
        odd->next = even->next;
        if(odd->next)
            odd = odd->next;
        odd->next = evenHead;
        even->next = NULL;
        return head;
    }
};