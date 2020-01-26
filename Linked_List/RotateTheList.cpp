/**
 * Rotate the list k times
 * input -->    1->2->3->4 ; k = 2.
 * output -->   3->4->1->2
 * TBD--> maintaining k difference of nodes. (similar to alt. approach used in Remove the nth node form the end of the linked list) 
 */


#include <iostream>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
        
        std::map<int, ListNode*> memoryList;
        ListNode *temp = head;
        int pos = 0;
        
        if(head == NULL || k == 0)
            return head;
        
        while(temp != NULL)
        {
            memoryList.insert({++pos, temp});
            temp = temp->next;
        }
        
        if((k%pos) == 0)
            return head;
        else 
        {
            k = k%pos;
            
            memoryList[pos-k]->next = NULL;
            memoryList[pos]->next = head;
            head = memoryList[(pos-k)+1];
            return head;
        }
    }

int main(int argc, char const *argv[])
{
    ListNode newNode(10), newNode1(20), newNode2(30), newNode3(40), newNode4(50);
    newNode.next = &newNode1;
    newNode1.next = &newNode2;
    newNode2.next = &newNode3;
    newNode3.next = &newNode4;
    newNode4.next = NULL;
    rotateRight(&newNode, 2);
    return 0;
}
