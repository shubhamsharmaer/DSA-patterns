class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> copy;
        vector<vector<int>> ans;
        bool insert = false;

        int n = intervals.size();

        for(int i = 0; i<n; i++) {
             if(insert == false and intervals[i][0] >= newInterval[0]) {
                copy.push_back({newInterval});
                cout<<copy[i][0]<<copy[i][1];
                insert = true;
            }
            copy.push_back(intervals[i]);
        }

        // if new Interval never added then it means it lies for last
        if(!insert) {
            copy.push_back({newInterval});
        }

        int s1 = copy[0][0];
        int e1 = copy[0][1];

        for(int i = 1; i < copy.size(); i++) {

            int s2 = copy[i][0];
            int e2 = copy[i][1];

            if(e1 >= s2){
                s1 = s1;
                e1 = max(e1, e2);
                continue;
            }
            // if no overlap
            ans.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
            ans.push_back({s1, e1});
            return ans;
    }
};