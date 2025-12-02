class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1'000'000'007;
        unordered_map<int,long long> freq;

        for (auto &p : points) 
            freq[p[1]]++;               

        vector<long long> seg;
        for (auto &e : freq) {
            long long k = e.second;
            if (k >= 2) 
                seg.push_back(k * (k - 1) / 2 % MOD);   
        }

        long long sum = 0, ans = 0;
        for (long long x : seg) {
            ans = (ans + x * sum) % MOD;   
            sum = (sum + x) % MOD;
        }
        return ans;
    }
};
