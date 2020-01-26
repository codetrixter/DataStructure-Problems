/**
 * Remove the nth node form the end of the linked list.
 */

#include <iostream>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//  ListNode* removeNthFromEnd(ListNode* head, int n) {
//      int pos = 0;
//     std::map<int, ListNode*> memoryList;
//     ListNode *temp = head;
//     while(temp != NULL)
//     {
//         memoryList.insert({++pos, temp});
//         temp = temp->next;
//     }
//     if (pos == 1)
//     {
//         head = NULL;
//     }
//     else if(n == 1)
//     {
//         memoryList[pos-1]->next = NULL;
//     }
//     else if(pos == n)
//     {
//         head = head->next;
//     }
//     else 
//     {
//         memoryList[pos-n]->next = memoryList[(pos-n)+1]->next;
//     }
//     return head;    
//     }
 
 //Alternate way with same time complexity...

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *first = dummy;
        ListNode *second = dummy;
        
        for(int i = 1; i <= n+1; i++)
        {
            first = first->next;
        }
        
        while(first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }

 int main(int argc, char const *argv[])
 {
    ListNode newNode(10), newNode1(20), newNode2(30), newNode3(40), newNode4(50);
    newNode.next = &newNode1;
    newNode1.next = &newNode2;
    newNode2.next = &newNode3;
    newNode3.next = &newNode4;
    newNode4.next = NULL;
    removeNthFromEnd(&newNode, 2);
    return 0;
 }
 