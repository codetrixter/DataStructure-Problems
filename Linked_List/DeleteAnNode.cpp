#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* deleteNode(ListNode *head, int data)
 {
     ListNode *node = head;
     while(node->next != NULL)
     {
         if(head->val == data)
         {
             head = head->next;
         }
         else if(node->next->val == data)
         {
             node->next = node->next->next;
         }
         else
         {
             node = node->next;
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
    ListNode *head = deleteNode(&newNode, 50);
    while(head != NULL)
    {
        std::cout << head->val;
        head = head->next;
    }
    return 0;
}
