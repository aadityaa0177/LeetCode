class Solution {
public:
// aditya
    int drange(int x) {
        int small = INT_MAX, lar = INT_MIN;
        while (x) {
            small = min(small, x%10);
            lar = max(lar, x%10);
            x /= 10;
        }
        return lar - small;
    }
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int lar = INT_MIN;
        for (int j = 0; j < n; j++) {
            v[j] = drange(nums[j]);
            lar = max(lar, v[j]);
        }
        long long sums = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == lar) sums += nums[j];
        }
        return sums;
    }
};