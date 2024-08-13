class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        /*used for applying Two Pointers algorithm*/
        int leftPtr, rightPtr;
        /*sorting the input array to easily avoid using repeated numbers*/
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            /*if the element is repeated, skip to the next iteration*/
            if(i>0 && nums[i] == nums[i-1] )
                continue;
            
            /*use the Two Pointers algorithm to find the two numbers that, when added to nums[i], equal zero.*/
            int target = nums[i];
            leftPtr= i+1;
            rightPtr=nums.size()-1;

            while(leftPtr < rightPtr)
            {
                int sum = target + nums[leftPtr] + nums[rightPtr];
                
                /*if the sum is greater than 0 that means we need to decrease it so, shift the right pointer to the left to get a lower value*/
                if(sum >0)
                {
                    rightPtr--;
                }
                /*if the sum is less than 0 that means we need to increase it so, shift the left pointer to the right to a higher value*/
                else if(sum < 0)
                {
                    leftPtr++;
                }
                /* if the target has been founded then, the current left and right elements are not needed so, update one and the other will be updated by the other conditions*/
                else
                {
                    result.push_back({nums[leftPtr], nums[rightPtr], target});
                    leftPtr++;
                    /*skip repeated numbers*/
                    while(nums[leftPtr] == nums[leftPtr-1] && leftPtr < rightPtr)
                    leftPtr++;
                }
            }
        }
        return result;

    }
};

