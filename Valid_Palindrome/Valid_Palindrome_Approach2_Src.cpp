class Solution {
public:
    bool isPalindrome(string s) {
        int leftPtr = 0,rightPtr = s.size() -1;
        
        //these two variables are used to hold the lower case character (for left and right pointers) if its alphanumeric else it will hold 0
        char RAlphanumeric =0;       
        char LAlphanumeric =0;
        
        //traverse the input string using left and write pointers
        while(leftPtr < rightPtr)
        {
            RAlphanumeric = getAlphanumeric(s[rightPtr]);
            LAlphanumeric = getAlphanumeric(s[leftPtr]);

            //check if the left and right characters are alphanumeric
            if(RAlphanumeric != 0 && LAlphanumeric != 0)
            {
                //compare the lower case left and right characters
                if(RAlphanumeric != LAlphanumeric)
                return false;
                
                rightPtr--;
                leftPtr++;
            }
            else
            {
                /*skip to the next element if the character is non-alphanumeric*/
                
                if(RAlphanumeric ==0)
                rightPtr--;
                
                if(LAlphanumeric ==0)
                leftPtr++;

            }
        }
        return true;
    }
private:

    /*
    this helper function returns the lower case character if the input char is alphanumeric
    if its non-alphanumeric it will return 0
    */
    char getAlphanumeric(char c)
    {
        //if the character is number from 0-9 or if it's lower case char return it as it is
        if( (static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57)||
            (static_cast<int>(c) >= 97 && static_cast<int>(c) <= 122) )
            return c;
        //if character is upper case return the lower case
        else if(static_cast<int>(c) >= 65 && static_cast<int>(c) <= 90)
            //32 is the offset between alphabet lower case and upper case characters
            return c + 32;
        else
            return 0;
    }
};