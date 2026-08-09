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
        stack<int>ans;
        ListNode*temp=head;
        while(temp!=NULL){
            ans.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(ans.top()!=temp->val){
                return false;
            }
            ans.pop();
            temp=temp->next;
        }
        return true;
    }
};