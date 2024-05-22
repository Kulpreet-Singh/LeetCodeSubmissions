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
    bool isPalindrome(ListNode* head) {

        stack<int> s;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            s.push(slow->val);
            slow=slow->next;
        }
        s.push(slow->val);
        if(fast->next==nullptr){
            s.pop();
        }
        while(slow->next){
            int top = s.top();
            s.pop();
            slow = slow->next;
            if(top!=slow->val){
                return false;
            }
        }
        if(!s.empty()){
            return false;
        }
        return true;
    }
};