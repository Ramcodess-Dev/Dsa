class Solution {
public:
    int minSubarray(vector<int>& a, int k) {
        int n = (int)a.size();
        long long tot = accumulate(a.begin(), a.end(), 0ll);
        unordered_map<int, int> cnt;
        cnt[0] = -1;
        long long sum = 0;
        int tar = tot % k;
        int ans = n;
        if (tar == 0) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            int cur = sum % k;
            int req = (k + cur - tar) % k;
            if (cnt.find(req) != cnt.end()) {
                ans = min(ans, i - cnt[req]);
            }
            cnt[cur] = i;
        }
        return ans == n ? -1 : ans;
    }
};