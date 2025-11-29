class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;

        vector<int> counts;
        for (auto &p : freq) counts.push_back(p.second);

        sort(counts.begin(), counts.end(), greater<int>());

        int removed = 0, sets = 0;
        int half = arr.size() / 2;

        for (int c : counts) {
            removed += c;
            sets++;
            if (removed >= half) break;
        }

        return sets;
    }
};
