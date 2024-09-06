# **Delete Nodes From Linked List Present in Array**
## **Problem link**
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/<br>

## **Descritprion**
**Example 1:**

Input: nums = [1,2,3], head = [1,2,3,4,5]<br>

Output: [4,5]<br>

Explanation:<br>
![alt text](linkedlistexample0.png)<br>
Remove the nodes with values 1, 2, and 3.<br><br>

**Example 2:**

Input: nums = [1], head = [1,2,1,2,1,2]<br>

Output: [2,2,2]<br>

Explanation:<br>
![alt text](linkedlistexample1.png)<br>
Remove the nodes with value 1.<br><br>


**Example 3:**

Input: nums = [5], head = [1,2,3,4]<br>

Output: [1,2,3,4]<br>

Explanation:<br>
![alt text](linkedlistexample2.png)<br>
No node has value 5.<br><br>

 

**Constraints:**

1 <= nums.length <= $10^{5}$<br>
1 <= nums[i] <= $10^{5}$<br>
All elements in nums are unique.<br>
The number of nodes in the given list is in the range [1, $10^{5}$].<br>
1 <= Node.val <= $10^{5}$<br>
The input is generated such that there is at least one node in the linked list that has a value not present in nums.<br>

## **Solution**
We need to traverse the linked list and remove any number exists in the input array.<br>
this can be done easliy by traversing the nodes and for each node we will traverse the input array to check if the value exists in the array or not.<br>
This solution will be valid but it will not be efficet and it will result in O(nodes_count * array_elements_count).<br>
This can be enhanced if we used Hash Set to store the array elements and access the elements in a constant time.<br>
### Approach (Hash Set)
-   Hash Set will be used to store **nums** elements.
-   We will iterate through the List and if we found a node have value exists in Hash Set, we will remove the node.
-   if the node to be removed is the first node, simply we will shift the head to the next node and remove the first node.
-   if the node to be removed is not the head we will make the previous(we must track the previous node) node points to the node next to the node to be removed then we will remove the node.

#### **Complexity**<br>

##### **Time complexity:**<br>
O(nodes_count + array_elements_count)<br>

##### **Space complexity:**
O(array_elements_count).<br>
