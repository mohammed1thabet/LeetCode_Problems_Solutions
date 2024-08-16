class Solution {
public:
    bool isValid(string s) {
        
        /*stack used to track the order of parentheses*/
        stack<char> charStack;

        /*this map is used for making links(key-value link) between open and close parentheses isntead of using multiple if-else statements*/
        unordered_map<char,char> parenthesesMap ={{'(', ')'},
                                                  {'{', '}'},
                                                  {'[', ']'} };

        for(auto i:s)
        {
            /*if i is one of the open parentheses it will be pushed in the stack to keep track the order of parentheses*/
            if(parenthesesMap.find(i) != parenthesesMap.end())
                charStack.push(i); 
            /*
            if there's no keys equal to i that means that i is one of the close parentheses and we need to check if the top of the stack is the correct open bracket
            if the stack is empty, that means that we have a close bracket without having any open bracket
            */
            else if(!charStack.empty() && parenthesesMap[charStack.top()] == i)
                charStack.pop();
            else
                return false;
        }
        /*make sure that the stack is empty and each open bracket has it's close bracket*/
        return charStack.empty();
    }
};