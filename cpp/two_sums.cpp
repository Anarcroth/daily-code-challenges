class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        std::sort(std::begin(nums), std::end(nums));
        std::vector<int> evens;
        std::vector<int> odds;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                evens.push_back(nums[i]);
            } else {
                odds.push_back(nums[i]);
            }
        }
        std::vector<int>::iterator itr1;
        std::vector<int>::iterator itr2;
        if (target % 2 == 0) {
            if (!evens.empty()) {
                for (int i = 0; i < evens.size() - 1; i++) {
                    if (evens[i] + evens[i + 1] == target) {
                        itr1 = std::find(nums.begin(), nums.end(), evens[i]);
                        itr2 = std::find(nums.begin(), nums.end(), evens[i + 1]);
                        return {std::distance(nums.begin(), itr1), std::distance(nums.begin(), itr2)};
                    }
                    if (evens[i] + evens[i + 1] > target) {
                        break;
                    }
                }
            }
            if (!odds.empty()) {
                for (int i = 0; i < odds.size() - 1; i++) {
                    if (odds[i] + odds[i + 1] == target) {
                        itr1 = std::find(nums.begin(), nums.end(), odds[i]);
                        itr2 = std::find(nums.begin(), nums.end(), odds[i + 1]);
                        return {std::distance(nums.begin(), itr1), std::distance(nums.begin(), itr2)};
                    }
                    if (odds[i] + odds[i + 1] > target) {
                        break;
                    }
                }
            }
        } else {
            for (int i = 0; i < evens.size(); i++) {
                for (int j = 0; j < odds.size(); j++) {
                    if (evens[i] + odds[j] == target) {
                        itr1 = std::find(nums.begin(), nums.end(), evens[i]);
                        itr2 = std::find(nums.begin(), nums.end(), odds[j]);
                        return {std::distance(nums.begin(), itr1), std::distance(nums.begin(), itr2)};
                    }
                    if (evens[i] + odds[j] > target ||
                        odds[j] > target ||
                        evens[i] > target) {
                        break;
                    }
                }
            }
        }
    }
};
