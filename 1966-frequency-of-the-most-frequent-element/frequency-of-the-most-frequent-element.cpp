class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
      
    sort(nums.begin(), nums.end()); // Step 1: sort the array
    int n = nums.size();
    long long totalOps = 0;        // sum of operations needed
    int left = 0;                  // start of the window
    int maxFreq = 0;               // maximum frequency found

    for (int right = 0; right < n; right++) {
        // Step 2: add the current number to totalOps
        totalOps += nums[right];

        // Step 3: check if we need more than k operations
        // total increments needed = nums[right]*(window_size) - sum(window)
        while ((long long)(nums[right]) * (right - left + 1) - totalOps > k) {
            // Step 4: shrink window from left
            totalOps -= nums[left];
            left++;
        }

        // Step 5: update max frequency
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;
    cout << maxFrequency(nums, k) << endl; // Output: 3
    return 0;
}

    
};