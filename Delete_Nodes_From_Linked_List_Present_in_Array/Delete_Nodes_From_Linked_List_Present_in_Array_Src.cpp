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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        /*these pointers are used to traverse the linked list*/
        ListNode* cur = head;
        ListNode* prev = head;

        /*hash set used to hold the numbers to be removed from the list*/
        unordered_set<int> removeSet;
        for(int i:nums)
        {
            removeSet.insert(i);
        }
        while(cur != nullptr)
        {
            /*if value stored in current node exists in the set, the node will be removed*/
            if(removeSet.find(cur->val) != removeSet.end())
            {
                /*if the current node is the head*/
                if(prev == head && cur == head)
                {
                    /*update head*/
                    head = head->next;
                    prev = head;
                    delete cur;
                    cur = head;
                }
                else
                {
                    /*previ node will point to the node after cur node*/
                    prev->next = cur->next; 
                    delete cur;
                    cur = prev->next;
                }

            }
            else
            {
                /*update pointers to check the next node*/
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
        
    }
};