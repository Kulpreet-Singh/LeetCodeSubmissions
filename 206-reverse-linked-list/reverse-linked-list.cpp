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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* next = head;
        ListNode* prev = NULL;
        while(next){
            next = head->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            if(next!=NULL) head = next;
        }
        return head;
    }
};