class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n =points.size();
        sort(points.begin(), points.end());


        int arrow =1;
         int e= points[0][1];
         for( int i=1; i<n; i++){
            int  start= points[i][0];
            int end = points[i][1];


            if(e >= start){
                e = min(e,end);

            }
            else{
                arrow++;
                e = end;

            }
         }
        return arrow;

    }
};