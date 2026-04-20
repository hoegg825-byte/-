class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> ans;
        for (int i=1; i<intervals.size(); i++){
            int curl = intervals[i][0], curr = intervals[i][1];
            if (curl > r){
                ans.push_back({l, r});
                l = curl;
                r = curr;
            }
            else if (curr > r) r = curr;
        }
        ans.push_back({l, r});
        return ans;
    }
};
