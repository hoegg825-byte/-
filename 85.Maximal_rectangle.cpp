class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m+2, 0);
        for (vector<char> &vt:matrix){
            for (int i=0; i<m; i++){
                if (vt[i] == '0') heights[i+1] = 0;
                else heights[i+1]++;
            }
            ans = max(largestRectangleArea(heights), ans);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        for (int i=0; i<heights.size(); i++){
            while (!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top()-1;
                ans = max(ans, width*height);
            }
            st.push(i);
        }
        return ans;
    }
};
