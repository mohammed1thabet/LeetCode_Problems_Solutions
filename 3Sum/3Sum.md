# **3Sum**
## **Problem link**
https://leetcode.com/problems/3sum/ <br>

## **Descritprion**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.<br>

Notice that the solution set must not contain duplicate triplets.<br>

 

**Example 1:**<br>
Input: nums = [-1,0,1,2,-1,-4]<br>
Output: [[-1,-1,2],[-1,0,1]]<br>
Explanation: <br>
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.<br>
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.<br>
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.<br>
The distinct triplets are [-1,0,1] and [-1,-1,2].<br>
Notice that the order of the output and the order of the triplets does not matter.<br><br>
**Example 2:**<br>
Input: nums = [0,1,1]<br>
Output: []<br>
Explanation: The only possible triplet does not sum up to 0.<br><br>
**Example 3:**<br>
Input: nums = [0,0,0]<br>
Output: [[0,0,0]]<br>
Explanation: The only possible triplet sums up to 0.<br>
 

**Constraints:**

3 <= nums.length <= 3000<br>
-$10^{5}$ <= nums[i] <= $10^{5}$<br>

## **Solution**
It's recommended to check Two Sum II problem before solve this problem, you will find the solution in the repository.<br>
We will use Two Pointers algorithm but this problem can also be solved using HashMaps.<br>
The main idea is to fix one element and find the two elements that if we add them to the fixed element we get 0.<br>
To avoid getting duplicate triplets we need to sort the numbers to skip the repeated numbers easily.
### Approach (Two Poninters)
- Traverse the input array from index 0, and for each iteration apply the Two Pointers algorithm(explained below) on the remaining part of the traversed array(sub array), by doing that we will fix one number in each iteration.
- The Two pointers algorithm works as follows:
    - We left and right pointers, points to the start and the end of the sub array.
    - The left pointer will point to the element with the lowest value in the sub array, and the right pointer will point to the element with the greatest value(since the array is sorted).
    - We will check if the left element + right element + the fixed number:
        - if it's greater than 0 then we need to decrease the sum, and we can do that by shifting the right pointer to the left(every time we shift the right pointer to the left, we got lower value) and check again.
        - if the sum is less than 0 then we need to increase the sum, and we can do that by shifting the left pointer to the right and check again.
        - if sum is equat to zero then we will add the three numbers to our result and update the pointers to check for the rest of the array.

#### **Complexity**
##### **Time complexity:**<br>
O($n^{2}$) becuase we are traversing the input array and for each iteration make another traversing using the Two Pointers.<br>

##### **Space complexity:**
it depends on the sorting algorithm.<br>
