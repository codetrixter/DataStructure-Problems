/** 
 * Delete duplicates form the list 
 * input -->    1->1->2->3.
 * output -->   2->3.
 */

#include <iostream>

/**----------------------------shit approach
ListNode *node = head;
        bool clone = false;
        
        if(node == NULL || node->next == NULL)
            return head;
        
        while(node->next != NULL)
        {
            if(node->next->next == NULL)
            {
                if(clone)
                    node->next = NULL;
                else
                    node = node->next;
            }
            if((node->val != node->next->val) && (node->next->val != node->next->next->val))
            {
                if(clone)
                {
                    if(node == head)
                    {
                        head = head->next;
                        clone = false;
                    }
                    else
                    {
                        node->next = node->next->next;
                        clone = false;
                    }
                }
                else
                    node = node->next;
            }
            else
            {
                clone = true;
                node->next = node->next->next;
            }
        }
        if(clone)
            head = NULL;
        return head;
    }
*/

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
