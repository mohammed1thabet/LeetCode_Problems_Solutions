# Valid Palindrome
## Problem link
https://leetcode.com/problems/valid-palindrome <br>

## Descritprion
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.<br>

Given a string s, return true if it is a palindrome, or false otherwise.<br>


Example 1:<br>

Input: s = "A man, a plan, a canal: Panama"<br>
Output: true<br>
Explanation: "amanaplanacanalpanama" is a palindrome.<br>
Example 2:<br>

Input: s = "race a car"<br>
Output: false<br>
Explanation: "raceacar" is not a palindrome.<br>
Example 3:<br>

Input: s = " "<br>
Output: true<br>
Explanation: s is an empty string "" after removing non-alphanumeric characters.<br>
Since an empty string reads the same forward and backward, it is a palindrome.<br>
 

Constraints:<br>

1 <= s.length <= 2 * $10^{5}$ <br>
s consists only of printable ASCII characters.<br>

## Solution
There are two approaches we can use, the second one is more efficient.<br>
### Approach 1 (linear input traversing to get the required string)
- first, we need to get rid of the uneeded characters and we can do that by creating a new string called original, traverse the input string then add all the characters in that new string except the non-alphanumeric characters.<br>
- second, we need to compare the new string(original) with it's reversed one so, create a new string with the same data as original then use function reverse() to reverse it.<br>
- compare the two strings and return comparison result.<br>
#### Complexity
##### Time complexity:<br>
O(n) as we are traversing the entire input linearly.<br>

##### Space complexity:
O(n) as we are creating two strings with size = input in the worst case(when the input contains alphanumeric only).<br>

### Approach 2(Two pointers algorithm)
- we will traverse the input form the start and the end using two pointers(leftPtr and rightPtr) and compare the two elements we are pointing to 
- if the two elements are equal we will check the next two elements until we finish traversing the input and in this case, the result will be true, other than that the result will be false.
- if one of the pointers points to a non-alphanumeric character it will be skipped and the pointer will point to the next element.
- helper function getAlphanumeric(char c) takes element from the input string and return 0 if it's non-alphanumeric other than that, it will return the lower case alphanumeric character. 
#### Complexity
##### Time complexity:<br>
O(n) as we are traversing the entire input.<br>

##### Space complexity:
O(1) as we are only using a few variables .<br>
#### Why approach 2 is better than approach 1 
- space complexity is O(1) .<br>
- in approach 2 we are traversing the input string for one time while, in approach 1 we are using std::string::reverse function which takes O(n) to execute, and we also traverse the input string.<br>
