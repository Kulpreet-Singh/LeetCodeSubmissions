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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        ListNode* temp1 = headA;
        while(temp1){
            len1++;
            temp1 = temp1->next;
        }
        int len2 = 0;
        ListNode* temp2 = headB;
        while(temp2){
            len2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        if(len1<=len2){
            int skipNodes = len2 - len1;
            while(skipNodes){
                temp2 = temp2->next;
                skipNodes--;
            }
            while(temp1){
                if(temp1==temp2){
                    return temp1;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        } else{
            int skipNodes = len1 - len2;
            while(skipNodes){
                temp1 = temp1->next;
                skipNodes--;
            }
            while(temp1){
                if(temp1==temp2){
                    return temp1;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};