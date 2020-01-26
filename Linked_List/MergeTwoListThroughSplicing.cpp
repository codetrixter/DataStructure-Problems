/**
 * Merge two list thrugh splicing.
 */

#include <iostream>
#include <map>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head= NULL;
    ListNode *l3 = head;
    //std::cout << l1->val << l2->val;
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                if(head == NULL)
                {
                    //The below code can be put into a method and reused at other places.
                    ListNode *newListNode = new ListNode(l1->val);
                    head = newListNode;
                    l1 = l1->next;
                    l3 = head;
                }
                else
                {
                    ListNode *newListNode = new ListNode(l1->val);
                    l3->next = newListNode;
                    l1 = l1->next;
                    l3 = l3->next; 
                }
            }
            else
            {
                if(head == NULL)
                {
                    ListNode *newListNode = new ListNode(l2->val);
                    head = newListNode;
                    l2 = l2->next;
                    l3 = head;
                }
                else
                {
                    ListNode *newListNode = new ListNode(l2->val);
                    l3->next = newListNode;
                    l2 = l2->next; 
                    l3 = l3->next;
                }
            }
        }
        else if(l1 == NULL && l2 != NULL)
        {
            if(head == NULL)
            {
                ListNode *newListNode = new ListNode(l2->val);
                head = newListNode;
                l2 = l2->next;
                l3 = head;
            }
            else
            {
                ListNode *newListNode = new ListNode(l2->val);
                l3->next = newListNode;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        else if(l2 == NULL && l1 != NULL)
        {
            if(head == NULL)
            {
                ListNode *newListNode = new ListNode(l1->val);
                head = newListNode;
                l1 = l1->next;
                l3 = head;
            }
            else
            {
                ListNode *newListNode = new ListNode(l1->val);
                l3->next = newListNode;
                l1 = l1->next;
                l3 = l3->next;
            }
        }
    }
    return head;
}    


int main(int argc, char const *argv[])
{
    ListNode newNode(2), newNode1(3), newNode2(20);
    newNode.next = &newNode1;
    newNode1.next = &newNode2;
    newNode2.next = NULL;
    ListNode newNode00(5), newNode10(10), newNode20(15);
    newNode00.next = &newNode10;
    newNode10.next = &newNode20;
    newNode20.next = NULL;
    //std::cout << newNode.val << newNode00.val;
    ListNode * head = mergeTwoLists(&newNode, &newNode00);
    while(head != NULL)
    {
        std::cout << head->val;
        head = head->next;
    }
    return 0;
}
