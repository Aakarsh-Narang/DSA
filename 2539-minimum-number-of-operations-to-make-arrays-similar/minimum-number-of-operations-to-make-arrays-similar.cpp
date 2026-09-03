class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        vector<int> odd1, odd2, even1, even2;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0) even1.push_back(nums[i]);
            else odd1.push_back(nums[i]);

            if(target[i] % 2 == 0) even2.push_back(target[i]);
            else odd2.push_back(target[i]);
        }

        for(int i = 0; i < even1.size(); i++){
            if(even1[i] > even2[i]) ans += even1[i] - even2[i];
        }

        for(int i = 0; i < odd1.size(); i++){
            if(odd1[i] > odd2[i]) ans += odd1[i] - odd2[i];
        }

        return ans/2;
    }
};

// [8,12,6] -> [4, 6, 3]
// [2,14,10] -> [1, 7, 5]
// [6, -2, -4]