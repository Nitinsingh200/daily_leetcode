class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0;

        int nIStart = newInterval[0];
        int nIEnd = newInterval[1];

        while (i < n &&  nIStart > intervals[i][1] ) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= nIEnd) {
            nIStart = min(intervals[i][0], nIStart);
            nIEnd = max(intervals[i][1], nIEnd);
            i++;
        }
        res.push_back({nIStart, nIEnd});

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};