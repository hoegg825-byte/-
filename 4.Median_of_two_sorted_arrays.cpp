class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        nums1.push_back(1e9);
        nums2.push_back(1e9);
        int l = 0, r = 0, cnt = 0;
        int cur;
        while (cnt < (m+n+1)/2){
            if (nums1[l] < nums2[r]){cur = nums1[l]; l++;}
            else{cur = nums2[r]; r++;}
            cnt++;
        }
        if ((m+n)%2==0) return (cur+min(nums1[l], nums2[r]))/2.0;
        else return cur;
    }
};
