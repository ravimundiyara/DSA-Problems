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
    ListNode* mergesort(ListNode* list1, ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(list1!=0 && list2!=0){
            if(list1->val< list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else {
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
            if(list1) temp->next=list1;
            else temp->next=list2;
        return dummyNode->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp2=slow->next;
        slow->next=NULL;
        ListNode*temp1=head;
     
        ListNode* left = sortList(temp1);
        ListNode* right = sortList(temp2);
        return mergesort(left,right);
        
    }
};