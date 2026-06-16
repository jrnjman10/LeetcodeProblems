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
    ListNode* deleteMiddle(ListNode* head) {
        int leg = 1; //length
        ListNode* curr = head;
        //get length
        while(curr->next != nullptr){
            curr = curr->next;
            leg++;
        }
        // n//2 is the index we want
        // need 2 pointers
        // one pointing at prev and one pointing at curr
        //dealing with length 1 case
        if(leg == 1){
            return nullptr;
        }
        curr = head->next;
        ListNode* prev = head;
        for(int n = 1; n < leg/2; n++){
            prev = curr;
            curr = curr->next;
        }
        //now we have the previous node before the node to be deleted and the node to be deleted
        prev->next = curr->next;
        //free(curr);
        return head;
    }
};