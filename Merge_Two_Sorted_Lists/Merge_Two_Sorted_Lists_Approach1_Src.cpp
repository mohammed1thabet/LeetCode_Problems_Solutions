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
        
        /*pointer to the result list*/
        ListNode* newHead = nullptr;
        ListNode* priv = nullptr;

        /*iterate through until you reach the end of one of the lists*/
        while(list1 && list2)
        {
            ListNode* newNode = nullptr;
            
            /*check for the element with lower value and add it to the result list*/
            if(list1->val > list2->val)
            {
                newNode = addNode(list2);
                list2 = list2->next;
            }
            else
            {
                newNode = addNode(list1);
                list1 = list1->next;
            }
            
            if(newHead == nullptr)
            {
                /*if its the first node to be added, store the head*/
                newHead = newNode;
            }
            else
            {
                priv->next = newNode;
            }
            priv = newNode;
        }
        /*add the remaining elements in list1*/
        addRemaining(list1, priv);
        /*add the remaining elements in list2*/
        addRemaining(list2, priv);

        return newHead;
    }

/*helper function used to create a new node to be added to the sorted list*/
ListNode* addNode(ListNode* list)
{
    /*create a new node in to be added to the new list*/
    ListNode* newNode = new ListNode;
    newNode->val = list->val;
    newNode->next = nullptr;

    return newNode;
}

/*helper function used to iterate through the remaining elemnets in a list and append it to other list*/
void addRemaining(ListNode* list, ListNode* tail)
{
    while(list)
    {
        ListNode* newNode = new ListNode;
        newNode->val = list->val;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        list = list->next;
    }
}
};