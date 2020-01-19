/**
 * LeetCode Problem (Medium)
 */
#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *tempList = NULL, *head = NULL;
        int carry = 0;
        while((l1 != NULL) || (l2 != NULL))
        {
            ListNode *l3 = new ListNode(0);
            int temp = 0;
            if(l1 == NULL)
            {
                temp = (l2->val);
            }
            else if(l2 == NULL)
            {
                temp = (l1->val);
            }
            else
            {
                temp = ((l1->val) + (l2->val));
            }
            
            if((carry + temp) < 10)
            {
                l3->val = carry + temp;
                carry = 0;
            }
            else
            {
                l3->val = (carry + temp)%10;
                carry = (carry + temp)/10;
            }
            if(tempList == NULL)
            {
                tempList = l3;
                head = tempList;
            }
            else
            {
                tempList->next = l3;
                tempList = tempList->next;
            }
            if(l1 != NULL)
            {
                l1 = l1->next;
            }
            
            if(l2 != NULL)
            {
                l2 = l2->next;
            }
        }
        if(carry != 0)
        {
            ListNode *l3 = new ListNode(0);
            l3->val = carry;
            tempList->next = l3;
        }
        return head;
    }

    /**
     * Alternate Solution...
     * 
     * ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=NULL||l2!=NULL||sum>0)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum/=10;
            node=&((*node)->next);
        }        
        return l3;
    }
    
     */

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    return 0;
}
    