class Solution {
public:
    bool validPalindrome(string s) {
        int leftPtr = 0,rightPtr = s.size() -1;

        //this variable is used to count how many times we have skipped a character
        int skipCounter = 0;
        //variable to hold state of right and left pointers before the character skip to return to it when the first skip fails to get the Palindrome
        int leftPtrBackup = 0,rightPtrBackup = 0;
        //these two variables are used to hold the lower case character (for left and right pointers) if its alphanumeric else it will hold 0
        char RAlphanumeric =0;       
        char LAlphanumeric =0;
        
        //traverse the input string using left and write pointers
        while(leftPtr < rightPtr)
        {
            RAlphanumeric = getAlphanumeric(s[rightPtr]);
            LAlphanumeric = getAlphanumeric(s[leftPtr]);

            //compare the lower case left and right characters
            if(RAlphanumeric != 0 && LAlphanumeric != 0)
            {
                if(RAlphanumeric != LAlphanumeric)
                {
                    //try to skip one character from the left 
                    if(skipCounter == 0)
                    {
                        skipCounter++;
                        //store left and right pointers to restore if skipping from the left failed to get the Valid Palindrome
                        leftPtrBackup = leftPtr;
                        rightPtrBackup = rightPtr;
                        leftPtr++;
                    }
                    //try to skip one character from the right
                    else if(skipCounter == 1)
                    {
                        //return to the state before skipping left char
                        leftPtr = leftPtrBackup;
                        rightPtr = rightPtrBackup-1;
                        skipCounter++;
                    }
                    //skipping one character from left or right didn't result in Palindrome so the resut is false
                    else
                    return false;
                }
                else
                {
                rightPtr--;
                leftPtr++;
                }
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
        if( (c >= 48 && c <= 57)||
            (c >= 97 && c <= 122) )
            return c;
        //if character is upper case return the lower case
        else if(c >= 65 && c <= 90)
            //32 is the offset between alphabet lower case and upper case characters
            return c + 32;
        else
            return 0;
    }
};