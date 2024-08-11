class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        /*these two variables are used to traverse the array from left and right*/
        int leftPtr=0, rightPtr=numbers.size()-1;

        /*traverse the input array from the start and the end of the array*/
        while(leftPtr <= rightPtr)
        {
            int temp = numbers[leftPtr] + numbers[rightPtr];
            if(temp == target)
                return {leftPtr+1, rightPtr+1};
            /*if left element + right element is greater than the target then, we need to get another compination that results in a lower value, so we need to move right pointer to the left to get lower value element and check again*/
            else if(temp > target)
                rightPtr--;
            /*if left element + right element is less than the target then, we need to move left pointer to the right to get higher value element*/
            else
                leftPtr++;
        }
        /*default return needed to avoid compilation error*/
        return {0,0};
        
    }
};