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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode();
        add(l1,l2,head,0);
        return head->next;
    }
    
    void add(ListNode* l1, ListNode* l2,ListNode* l3,int carry){
        ListNode* temp=new ListNode(carry);
        if(!l1&&!l2){
            if(carry)
                l3->next=temp;
            return;   
        }
        if(l1){
            temp->val+=(l1->val);
            l1=l1->next;
        }
        if(l2){
            temp->val+=(l2->val);
            l2=l2->next;
        }
        carry=temp->val/10;
        temp->val%=10;
        l3->next=temp;
        l3=l3->next;
        add(l1,l2,l3,carry);
    }
};