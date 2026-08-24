class Solution {
public:

    void rev(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // 1. Reverse complete array
        rev(nums, 0, n - 1);

        // 2. Reverse first k elements
        rev(nums, 0, k - 1);

        // 3. Reverse remaining elements
        rev(nums, k, n - 1);
    }
};