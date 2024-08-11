# **Two Sum II**
## **Problem link**
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ <br>

## **Descritprion**
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.<br>

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.<br>

The tests are generated such that there is exactly one solution. You may not use the same element twice.<br>

Your solution must use only constant extra space.<br>

 

**Example 1:**

Input: numbers = [2,7,11,15], target = 9<br>
Output: [1,2]<br>
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].<br>
**Example 2:**

Input: numbers = [2,3,4], target = 6<br>
Output: [1,3]<br>
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].<br>
**Example 3:**

Input: numbers = [-1,0], target = -1<br>
Output: [1,2]<br>
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].<br>
 

**Constraints:**

2 <= numbers.length <= 3 * 104<br>
-1000 <= numbers[i] <= 1000<br>
numbers is sorted in non-decreasing order.<br>
-1000 <= target <= 1000<br>
The tests are generated such that there is exactly one solution.<br>
## **Solution**
This problem is part two of another problem called Two Sum.<br>
You can solve this problem using HashMaps if there is no constrains about using extra space, so We will solve the problem using Two-Pointer algorithm.<br>
If you dont know what is Two pointers algorithm ,It's recommended to learn more about the algtorithm and how it works as it's so useful and it will help you in solving different problems.<br>
### Approach (Two Pointers)
- Start Traversing the input form the start and the end using two pointers(leftPtr and rightPtr).
-  Check the sum of the two elements:
    - if the sum is equal to target then return the left and right pointers after adding 1 to the two of them(as it's requested in the desciption).
    - if the sum value is less than target then we need to increase ower sum and that will be done by increasing the left pointer to get higher value since the array is sorted, so numbers[leftPtr+1] > numbers[leftPtr].
    - if the sum is greater than target then we need to decrease the sum and that can be done by decreasing the right pointer.

#### **Complexity**
##### **Time complexity:**<br>
O(n) since we are traversing the input array.<br>

##### **Space complexity:**
O(1) only few variables is used.<br>
