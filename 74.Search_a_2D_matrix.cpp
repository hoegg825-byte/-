class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n*m-1;
        while (l <= r){
            int mid = (l+r)/2;
            int cur = matrix[mid/m][mid%m];
            if (cur == target) return true;
            else if (cur > target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
