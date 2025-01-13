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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        /*if one of the lists is empty return the other*/
        if(list1 == nullptr || list2 == nullptr)
            return list1 == nullptr? list2 : list1;
        
        ListNode* newHead = list1;
        /*base list that will be the result*/
        ListNode* base = list1;
        ListNode* basePrev = nullptr;
        /*the list to be inserted in the base list*/
        ListNode* insList = list2;
        ListNode* temp;

        /*iterate through the base list until you find an element with value greater than inserted element*/
        while(base && insList)
        {

            if(base->val >= insList->val)
            {
                /*insert the node before base*/
                temp = insList->next;
                insList->next = base;
                if(basePrev != nullptr)
                    basePrev->next = insList;
                else
                    newHead = insList;

                basePrev = insList;
                insList = temp;
            }
            else
            {
                temp = base->next;
                basePrev = base;
                base = temp;
            }
        }
        /*if there are remaining elements in the inserted list, append them to the end of the base list*/
        if(insList != nullptr)
        {
            basePrev->next = insList;
        }   
        return newHead;
    }
};