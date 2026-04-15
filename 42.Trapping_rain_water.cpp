class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int ans = 0;
        for (int i=0; i<height.size(); i++){
            while (!st.empty() && height[st.top()] < height[i]){
                int mid = st.top();
                st.pop();
                if (st.empty()) continue;
                int h = min(height[i], height[st.top()]) - height[mid];
                int w = i - st.top()-1;
                ans += h*w;
            }
            st.push(i);
        }
        return ans;
    }
};
