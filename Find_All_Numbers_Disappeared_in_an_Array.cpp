class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       int n = nums.size();
        vector<int> result;

        // Sort the array
        std::sort(nums.begin(), nums.end());

        int expected_num = 1;
        for (int i = 0; i < n; ++i) {
            // Skip duplicate numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // While we haven't reached nums[i], add missing numbers
            while (expected_num < nums[i]) {
                result.push_back(expected_num);
                expected_num++;
            }

            // Match found, increment expected_num
            if (nums[i] == expected_num) {
                expected_num++;
            }
        }

        // Add any remaining missing numbers up to n
        while (expected_num <= n) {
            result.push_back(expected_num);
            expected_num++;
        }

        return result;
    }
};
