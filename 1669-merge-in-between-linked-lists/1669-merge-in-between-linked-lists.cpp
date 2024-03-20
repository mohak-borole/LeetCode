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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *parent = nullptr;
        ListNode *current = list1;
        
        if (list1 == nullptr)
            return list2;
        else{
        for(int i = 0; i < a ; i++) {
            parent = current;
            current = current->next;
        }
        
        parent->next = list2;
        while(parent->next != NULL)
            parent = parent->next;
        
        for(int i = a ; i < b ; i++){
            current = current->next;
        }
        
        parent->next = current->next;
        
        return list1;
        }
    }
};