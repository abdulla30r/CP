class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];

            if (myMap.count(remaining)) {
                auto it = myMap.find(remaining);
                arr.push_back(it->second);
                arr.push_back(i);
                break;
            } else {
                myMap.insert({nums[i], i});
            }
        }
        return arr;
    }
};