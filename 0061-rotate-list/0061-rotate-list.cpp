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
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp=head;
        ListNode* newhead;
        int n=0;
        int count=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        
        while(temp!=NULL && temp->next!=NULL){
            int K=k%n;
            if(K==0) return head;
            count++;
            if(n-K==count){
                newhead=temp->next;
                temp->next=NULL;
            }
            temp=temp->next;
        }
        ListNode* temp2=newhead;
        while(temp2!=NULL){
            if(temp2->next==NULL){
                temp2->next=head;
                break;
            }
            temp2=temp2->next;
        }
        return newhead;
    }
};