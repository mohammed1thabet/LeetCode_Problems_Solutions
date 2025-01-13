# Merge Two Sorted Lists
## Problem link
https://leetcode.com/problems/merge-two-sorted-lists/ <br>

## Descritprion
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

**Example 1:**<br>
![alt text](Example1.jpg)<br>

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

**Example 2:**<br>

Input: list1 = [], list2 = []
Output: []

**Example 3:**<br>

Input: list1 = [], list2 = [0]
Output: [0]
 

**Constraints:**<br>

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

## Solution
We take use the following Approaches.<br>
### Approach 1 (Create a new list and add the elements in sorted order)
- create a new list to store the sorted list.
- start traversing the input lists and compare element by element and take the lower value and create a new node with this value then add it to the new list.
- traversing and comparing is terminated if you reched the end of one of the two lists.
- after comaring termination, if one of the lists have remaining elemnts append these elements to the end of the result list.
#### Complexity
##### Time complexity:<br>
O(n) as we are traversing the entire input linearly.<br>

##### Space complexity:
O(n) as we are creating a new list containing the input lists elements.<br>

### Approach 2(insert one of the lists in the other inplace)
Instead of creating a new list for the result, we can optimize that and get our list sorted in place by inserting one of the lists elements in the other list(lets name it as base list) in sorted order.<br>
That will also result in optimizing execution time because new node creation instructions will be removed.<br>
The solution will be as follows:
- Take an element from the inserted list and iterate through the base list until you find an element with value greater than inserted element.
- The inserted element is greater than all the previous elements in the base list and lower than the element that we have found in the previous point.
- Add the inserted element before the element we found, and take the next element in the inserted list.
- After reaching the end of the base list, if the inserted list have remaining elements then, append the rest of the inserted list to the base list.
#### Complexity
##### Time complexity:<br>
O(n) as we are traversing the entire input.<br>

##### Space complexity:
O(1) as we are only using a constant count of variables .<br>