class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(true){
            
            bool isSorted = true;

            for(int i = 0; i < nums.size() - 1;i++){
                if(nums[i] > nums[i+1]){
                    isSorted = false;
                }
            }
            
            if(isSorted) return operations;

            int minSum = INT_MAX;
            int index;

            for(int i = 0; i < nums.size() - 1; i++){
                int currentSum = nums[i] + nums[i+1];
                if(minSum > currentSum){
                    minSum = currentSum;
                    index = i;
                }
            }

            
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
            operations++;
        }
    }
};