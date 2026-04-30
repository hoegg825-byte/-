class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
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
