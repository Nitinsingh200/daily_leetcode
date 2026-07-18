class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
         sort(intervals.begin(), intervals.end());
                 int remove = 0;
int prevend = intervals[0][1];

        for( int i=1; i<n; i++){
             int currstart = intervals[i][0];
              int currend = intervals[i][1];


              if( currstart < prevend){
                remove++;


                prevend = min(prevend, currend);


              }
              else{
                prevend =  currend;
             }
        }

        return remove;
    }
};