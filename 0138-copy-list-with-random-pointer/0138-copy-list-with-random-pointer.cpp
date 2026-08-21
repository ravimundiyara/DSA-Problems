/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* temp = head;

        while (temp != NULL) {
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        temp = head;

        while (temp != NULL) {
            Node* copy = temp->next;

            if (temp->random != NULL)
                copy->random = temp->random->next;
            else
                copy->random = NULL;

            temp = copy->next;
        }

        temp = head;
        Node* copyHead = head->next;

        while (temp != NULL) {
            Node* copy = temp->next;

            temp->next = copy->next;

            if (copy->next != NULL)
                copy->next = copy->next->next;
            else
                copy->next = NULL;

            temp = temp->next;
        }

        return copyHead;
    }
};