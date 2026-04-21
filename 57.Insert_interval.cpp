class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left = newInterval[0];
        int right = newInterval[1];
        bool place = false;
        for (const vector<int> &cur: intervals){
            if (left > cur[1]) ans.emplace_back(cur);
            else if (cur[0] > right){
                if (!place){
                    ans.push_back({left, right});
                    place = true;
                }
                ans.emplace_back(cur);
            }
            else {
                left = min(left, cur[0]);
                right = max(right, cur[1]);
            }
        }
        if (!place) ans.push_back({left, right});
        return ans;
    }
};
