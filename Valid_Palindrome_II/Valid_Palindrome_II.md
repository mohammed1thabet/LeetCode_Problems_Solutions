# Valid Palindrome
## Problem link
https://leetcode.com/problems/valid-palindrome-ii/<br>

## Descritprion
Given a string s, return true if the s can be palindrome after deleting at most one character from it.<br>

 

Example 1:<br>

Input: s = "aba"<br>
Output: true<br>
Example 2:<br>

Input: s = "abca"<br>
Output: true<br>
Explanation: You could delete the character 'c'.<br>
Example 3:<br>

Input: s = "abc"<br>
Output: false<br>
 

Constraints:<br>

1 <= s.length <= 105<br>
s consists of lowercase English letters.<br>

## Solution
This problem is the 2nd par of a problem we have solved before(check part 1 solution, you can find it in the repository)<br>
The solution is almost the same as the previous part but with some additions<br>

### Approach (Two pointers algorithm)
in addition to the solution for Valid Palindrome I:
- in case of comparison failure state, we will skip one character and continue to check for the Palindrome.
- we will skip one charcter from the left then check and f it fails we will return to the state before skipping from the left and try to skip the character from the right side.
- left and right pointers are sotred before left char skipping to restore the state before first skipping try.
- to track the skipping operation, skipCounter variable is used to count the number of skip tries.
#### Complexity
##### Time complexity:<br>
O(n) as we are traversing the entire input.<br>

##### Space complexity:
O(1) as we are only using a few variables .<br>
