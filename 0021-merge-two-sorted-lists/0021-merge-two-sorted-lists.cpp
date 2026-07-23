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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        //the question can be solved using dummy node 

        ListNode* dummy = new ListNode(-1);

        ListNode* t1=list1;
        ListNode* t2=list2;
        // dummy->val=-1;
        // dummy->next=NULL;
        ListNode* temp=dummy;
        

        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                temp->next=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
            }
            temp = temp->next;



        }

        if(t1) temp->next=t1;
        else temp->next=t2;

        
        return dummy->next;

        
    }
};