class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        vector<pair<int,int>> proj;

        for(int i = 0; i < n; i++) {
            proj.push_back({capital[i], profits[i]});
        }

        sort(proj.begin(), proj.end());

        priority_queue<int> pq;

        int idx = 0;

        while(k--) {

            while(idx < n && proj[idx].first <= w) {
                pq.push(proj[idx].second);
                idx++;
            }

            if(pq.empty())
                return w;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};