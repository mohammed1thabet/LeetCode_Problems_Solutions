# **Longest Consecutive Sequence**
## **Problem link**
https://leetcode.com/problems/longest-consecutive-sequence/<br>

## **Descritprion**
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.<br>

You must write an algorithm that runs in O(n) time.<br>

 

**Example 1:**<br>

Input: nums = [100, 4, 200, 1, 3, 2]<br>
Output: 4<br>
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.<br>
**Example 2:**<br>

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]<br>
Output: 9<br>
 

**Constraints:**<br>

0 <= nums.length <= $10^{5}$<br>
$-10^{9}$ <= nums[i] <= $10^{9}$<br>

## **Solution**
This problem can be solved easily by sorting the input array but the best time complexity we can get from sorting algorithms is O(nLogn) and the solution must be O(n) as mentioned in the description.<br>
To solve this problem without sorting we can use a data structure that has a fast accessing time and can also be fast for searching for elements in some conditions, that data structure is **Hash Set**.<br>
Hash Set will help us to check the Consecutive Sequence fast. because searching for a number if it exists in a hash set or not will take O(1) time, so we need to get the start number of each Consecutive Sequence and then search  in the Hash Set for all following numbers<br>

### Approach (Hash Set)
- create an unordered_set(c++ implemntation for hash set) and insert the input numbers(insert method takes O(1) time).
- unordered_set can contain one entity of each key so, repeated numbers will have no effect.
- traverse the hash set and check for a start of a Consecutive Sequence(Consecutive Sequence starts with a number so that number-1 doesn't exist in the array).
- when finding a start of a Consecutive Sequence, search in the set for the following numbers and count the length of the Sequence.

#### **Complexity**
##### **Time complexity:**<br>
O(n), since the we will visit each number twice in the worst case<br>

##### **Space complexity:**
O(n) used by the set we created.<br>
