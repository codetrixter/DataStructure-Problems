/**
 * Swap Node in Pairs
 * example::
 * input -->    1->2->3->4
 * output -->   2->1->4->3
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapAdjacentNodes(ListNode *head)
{
    if(head == NULL || (head->next == NULL))
                return head;
            
    ListNode *first = head, *second = head->next;
    ListNode *dummy = first;
    bool once = true;  
    head = head->next;
    
    while(second != NULL)
    {
        ListNode *temp = dummy;
        if(once)
        {
            first->next = second->next;
            second->next = first;

            first = first->next;
            if(second->next->next != NULL)
                second = second->next->next->next;
            else
                second = second->next->next;
            once = false;
        }
        else
        {
            first->next = second->next;
            second->next = first;
            temp->next = second;
            dummy = first;
            
            first = first->next;
            if(second->next->next != NULL)
                second = second->next->next->next;
            else
                second = second->next->next;
        }
    }        
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode newNode(10), newNode1(20), newNode2(30), newNode3(40), newNode4(50);
    newNode.next = &newNode1;
    newNode1.next = &newNode2;
    newNode2.next = &newNode3;
    newNode3.next = &newNode4;
    newNode4.next = NULL;
    swapAdjacentNodes(&newNode);
    return 0;
}
