class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n-1, left = 0, right = n-1, num = 1;
        vector<vector<int>> ans(n, vector<int> (n));
        while (top <= bottom && left <= right){
            for (int i=left; i<=right; i++) {ans[top][i] = num; num++;}
            top++;
            for (int i=top; i<=bottom; i++) {ans[i][right] = num; num++;}
            right--;
            if (top <= bottom){
                for (int i=right; i>=left; i--) {ans[bottom][i] = num; num++;}
                bottom--;
            }
            if (left <= right){
                for (int i=bottom; i>=top; i--) {ans[i][left] = num; num++;}
                left++;
            }
        }
        return ans;
    }
};
