# **Valid Parentheses**
## **Problem link**
https://leetcode.com/problems/valid-parentheses/<br>

## **Descritprion**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.<br>

An input string is valid if:<br>

Open brackets must be closed by the same type of brackets.<br>
Open brackets must be closed in the correct order.<br>
Every close bracket has a corresponding open bracket of the same type.<br>
 

**Example 1:**<br>

Input: s = "()"<br>
Output: true<br>
**Example 2:**<br>

Input: s = "()[]{}"<br>
Output: true<br>
**Example 3:**<br>

Input: s = "( ]"<br>
Output: false<br>
 

**Constraints:**<br>

1 <= s.length <= $10^{4}$<br>
s consists of parentheses only '()[]{}'.<br>

## **Solution**
A common way to handle arithmetic  operations parsing is using stack, and this problem is like a simple version of that operations.<br>
You can check how POSTFIX and PREFIX are evaluated and how you can implement software to do that using a stack.<br>
After analyzing the problem we can say that Valid Parentheses must be as follows:
- After any open bracket we can only have a close bracket from the same type, if we find a close bracket from another type then it's not valid.
- The order of closing parentheses must be from inner to outer, the last open parenthesis must be closed first and the first open parenthesis must be closed last.
### Approach (Stack)
- Stack is a "last in first out" data structure so, if we traversed the input and put the open brackets in the stack we will have the inner bracket on the top of the stack, and the bracket before it will be in 2nd place in the stack and so on.
- While traversing the input, if we find a close bracket, we will check if it's compatible with the top of the stack (the inner brackets must be closed first).
- After we finish traversing the input, we must check if the stack is empty or not because if it's not empty, that means that we have extra open brackets without their closed brackets and that means we have invalid Parentheses.
- To check the compatibility of the brackets type we can use conditions like this: " if(s[i] == ')' && stack.top() == '(') " but it will be better to use unorderd_map to avoid redundant code, in our map the key will be the open bracket " (, {, [ " and the value assigned to the key will be the close bracket " ), }, ] ".

#### **Complexity**
##### **Time complexity:**<br>
O(n) <br>

##### **Space complexity:**
O(n) used by the stack we created.<br>
