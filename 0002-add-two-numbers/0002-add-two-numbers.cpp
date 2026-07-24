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

        // ListNode* sum= new ListNode(0);
        // ListNode* carry= new ListNode(0);

        ListNode* temp1=l1;
        ListNode* temp2=l2;

        ListNode* dummy= new ListNode(-1);
        ListNode* temp3=dummy;
        int sum=0,carry=0;

        while(temp1!=NULL && temp2!=NULL){

            sum=temp1->val+temp2->val+carry;
            
                carry=sum/10;
                sum=sum%10;
            
            ListNode* d= new ListNode(sum);
            temp3->next=d;
            temp3=temp3->next;
            // if(carry>0){
            //     sum=carry;
            //     carry=0;
            // }
            // else{
            //     sum=0;
            //     carry=0;
            // }
            temp1=temp1->next;
            temp2=temp2->next;



        }
        while (temp1 != NULL) {

            sum = temp1->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            temp3->next = new ListNode(sum);
            temp3 = temp3->next;

            temp1 = temp1->next;
        }

        while (temp2 != NULL) {

            sum = temp2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            temp3->next = new ListNode(sum);
            temp3 = temp3->next;

            temp2 = temp2->next;
        }

        if(carry>0) temp3->next=new ListNode(carry);
        
        return dummy->next;




        




        
    }
};