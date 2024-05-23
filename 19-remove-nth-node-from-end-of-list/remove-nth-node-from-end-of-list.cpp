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
        ListNode* prev = NULL;
        ListNode* offsetN = head;
        n--;
        while(n--){
            offsetN = offsetN->next;
        }
        while(offsetN && offsetN->next){
            offsetN = offsetN->next;
            prev = temp;
            temp = temp->next;
        }
        if(prev==NULL){
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        return head;
    }
};