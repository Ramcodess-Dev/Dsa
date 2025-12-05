class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return 0;
        return (int)nums.size() - 1;
    }
};
