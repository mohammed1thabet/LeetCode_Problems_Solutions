# **Valid Sudoku**
## **Problem link**
https://leetcode.com/problems/valid-sudoku/<br>

## **Descritprion**
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:<br>

Each row must contain the digits 1-9 without repetition.<br>
Each column must contain the digits 1-9 without repetition.<br>
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.<br>
**Note:**<br>

A Sudoku board (partially filled) could be valid but is not necessarily solvable.<br>
Only the filled cells need to be validated according to the mentioned rules.<br>
 

**Example 1:**<br>
![alt text](Example1.png)<br>
**Input:** board = <br>
[[ "5", "3", ".", ".", "7", ".", ".", ".", "." ]<br>
,[ "6", ".", ".", "1", "9", "5", ".", ".", "." ]<br>
,[ ".", "9", "8", ".", ".", ".", ".", "6", "." ]<br>
,[ "8", ".", ".", ".", "6", ".", ".", ".", "3" ]<br>
,[ "4", ".", ".", "8", ".", "3", ".", ".", "1" ]<br>
,[ "7", ".", ".", ".", "2", ".", ".", ".", "6" ]<br>
,[ ".", "6", ".", ".", ".", ".", "2", "8", "." ]<br>
,[ ".", ".", ".", "4", "1", "9", ".", ".", "5" ]<br>
,[ ".", ".", ".", ".", "8", ".", ".", "7", "9" ]]<br>
**Output:** true<br>

**Example 2:**<br>
Input: board = <br>
[[ "8", "3", ".", ".", "7", ".", ".", ".", "." ]<br>
,[ "6", ".", ".", "1", "9", "5", ".", ".", "." ]<br>
,[ ".", "9", "8", ".", ".", ".", ".", "6", "." ]<br>
,[ "8", ".", ".", ".", "6", ".", ".", ".", "3" ]<br>
,[ "4", ".", ".", "8", ".", "3", ".", ".", "1" ]<br>
,[ "7", ".", ".", ".", "2", ".", ".", ".", "6" ]<br>
,[ ".", "6", ".", ".", ".", ".", "2", "8", "." ]<br>
,[ ".", ".", ".", "4", "1", "9", ".", ".", "5" ]<br>
,[ ".", ".", ".", ".", "8", ".", ".", "7", "9" ]]<br>
**Output:** false<br>
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.<br>
 

**Constraints:**<br>

board.length == 9<br>
board[ i ].length == 9<br>
board[ i ][ j ] is a digit 1-9 or ' . '.<br>

## **Solution**
The most easy way to solve this problem is to brute force each row, column and sub box using two loops and check for repeated numbers.<br>
To enhance this solution we will use Hash set to use one loop to check each row, column, sub box.<br>
There is solution can be enhanced by using dynamic programming to store output of the repeated calcuation ,you can check how dynamic programming works to find out how to apply it on this problem.<br>
### Approach (Hash Set)
Hash sets have almost constant access time so for example, we can traverse a row using a loop and for each iteration we will check if the current element is in the set or not:
- if the number is exists in the set that means that this is the appearance for this number.
- if the number is not in the set, we will insert it and continue to traverse the rest of the row.
- We will do the same steps with the columns and the sub boxes to check for the repeated numbers.
- Input traversing will be using one loop and for each iteration we will check one row, one column and one sub box.

#### **Complexity**<br>
**note:** n is constant number= 9 * 9<br>

##### **Time complexity:**<br>
O(3*n) = (3 * 9 * 9)<br>

##### **Space complexity:**
O(3n) = (3 * 9 * 9).<br>
