class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r = height.size()-1, res = 0;
        while (l<r){
            int w = r-l;
            int h = min(height[l], height[r]);
            res = max(res, w*h);
            if (height[l] < height[r]){
                int cur = height[l];
                while (l<r && height[l] <= cur) l++;
            }
            else {
                int cur = height[r];
                while (r>l && height[r] <= cur) r--;
            }
        }
        return res;
    }
};
