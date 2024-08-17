class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        int count =0;
        int maxCount=0;
        /*insert the input in the set*/
        for(auto i:nums)
            numsSet.insert(i);
        
        /*traverse the set we have created to get the start element of a consecutive sequence*/
        for(auto i= numsSet.begin(); i != numsSet.end(); i++)
        {
            /*consecutive sequence starts with a number so that number-1 doesn't exist in the input*/
            if(numsSet.find((*i)-1) == numsSet.end())
            {
                /*this variable is used to trace the numbers after the sequence start number*/
                int offset=0;
                /*start searching for the coming numbers in the sequence*/
                while(numsSet.find(*i +offset) != numsSet.end())
                { 
                    offset++;
                    count++;
                    if(count > maxCount)
                        maxCount = count;
                }
                /*reset the counter to start checking another sequence*/
                count=0;
            }
        }
        return maxCount;
    }
};