class Solution {
public:
    bool isPalindrome(string s) {
        
        //input string without non-alphanumeric
        string original = "";

        //input string without non-alphanumeric but reversed
        string reversed = "";
        
        //traverse the string to get the required characters and add them in original
        for(int i=0; i<s.size(); i++)
        {   
            //if the character is number from 0-9 or if it's lower case char, place it as it is in original string
            if(
            (static_cast<int>(s[i]) >= 48 && static_cast<int>(s[i]) <= 57)||
            (static_cast<int>(s[i]) >= 97 && static_cast<int>(s[i]) <= 122)
            )
            {
                original += s[i];
            }
            //if character is upper case store the lower case in original string
            else if(static_cast<int>(s[i]) >= 65 && static_cast<int>(s[i]) <= 90)
            {
                //32 is the offset between alphabet lower case and upper case characters
                original += s[i] + 32;
            }
        }
        //copy to original to reversed then use reverse() to reverse it
        reversed = original;
        reverse(original.begin(), original.end());
        
        return original == reversed;
        
    }
};