class Solution {
private:
    int solve(vector<int> &nums, int target) {
        int left = 0, right = 0, currSum = 0, n = nums.size(), minLen = 1e9;
        vector<int> leftPrefix(n, 1e9), rightPrefix(n, 1e9);

        while(right < n) {
            currSum += nums[right];
            while(currSum > target) {
                currSum -= nums[left++];
            }
            if(currSum == target) {
                minLen = min(minLen, right - left + 1);
            }
            leftPrefix[right] = minLen;
            right++;
        }

        currSum = 0, left = n - 1, right = n - 1, minLen = 1e9;
        while(left >= 0) {
            currSum += nums[left];

            while(currSum > target) {
                currSum -= nums[right--];
            }

            if(currSum == target) {
                minLen = min(minLen, right - left + 1);
            }
            rightPrefix[left] = minLen;
            left--;
        }


        int result = 1e9;
        for(int idx = 0; idx + 1 < n; idx++) {
            if(leftPrefix[idx] != 1e9 && rightPrefix[idx + 1] != 1e9) {
                result = min(result, leftPrefix[idx] + rightPrefix[idx + 1]);
            }
        }
        result = (result == 1e9) ? -1 : result;
        return result;
    }
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        return solve(arr, target);
    }
};