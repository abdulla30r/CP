class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end of both arrays and fill nums1 from the back
        int i = m - 1; // Last element in the initial nums1
        int j = n - 1; // Last element in nums2
        int k = m + n - 1; // Last position in nums1
        
        // Merge nums2 into nums1 starting from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};