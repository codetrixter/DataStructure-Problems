/**
 * Remving duplicate items from the sorted list.
 * input -->    1->2->3->3->3.
 * output -->   1->2->3.
 */

#include <iostream>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

std::map<int, bool> memoryList;

ListNode* deleteDuplicates(ListNode* head) {
        
        bool state = false;
        if(head == NULL)
            return head;
        
        ListNode *node = head;
        
        while(node->next !=NULL)
        {
            if(node->val != node->next->val)
            {
                if(state)
                {
                    node = node->next;
                    state = false;
                }
                else
                {
                    memoryList.insert({node->val, false});
                    node = node->next;
                }
            }
            else
            {
                if(!state)
                {
                    memoryList.insert({node->val, true});
                    node->next = node->next->next;
                    state = true;
                }
                else
                {
                    node->next = node->next->next;
                }
            }
        }
        return head;
    }

// remove duplicates form the list.
// ListNode* deleteDuplicates(ListNode* head) {
        
//         if(head == NULL)
//             return head;
        
//         ListNode *node = head;
        
//         while(node->next !=NULL)
//         {
//             if(node->val != node->next->val)
//                 node = node->next;
//             else
//             {
//                 node->next = node->next->next;
//             }
//         }
//         return head;
//     }

int main(int argc, char const *argv[])
{
    ListNode newNode(10), newNode1(20), newNode2(30), newNode3(30), newNode4(40);
    newNode.next = &newNode1;
    newNode1.next = &newNode2;
    newNode2.next = &newNode3;
    newNode3.next = &newNode4;
    newNode4.next = NULL;
    ListNode *head = deleteDuplicates(&newNode);
    while(head != NULL)
    {
        std::cout << head->val << "\t";
        head = head->next;
    }
    std::map<int, bool>::iterator itr;
    std::cout << "\n";

    for(itr = memoryList.begin(); itr != memoryList.end(); ++itr)
    {
        std::cout << itr->first << "-->" << itr->second << std::endl;
    }
    return 0;
}
