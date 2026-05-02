class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, tail = n+m-1;
        while (i>=0 && j>=0){
            if (nums1[i] < nums2[j]){
                nums1[tail] = nums2[j];
                tail--;
                j--;
            }
            else {
                nums1[tail] = nums1[i];
                tail--;
                i--;
            }
        }
        while (i>=0){
            nums1[tail] = nums1[i];
            tail--;
            i--;
        }
        while (j>=0){
            nums1[tail] = nums2[j];
            tail--;
            j--;
        }
    }
};
