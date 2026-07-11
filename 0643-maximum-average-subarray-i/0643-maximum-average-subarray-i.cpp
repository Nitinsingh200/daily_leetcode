class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low =0;
         int high = k-1;
         int n = nums.size();
         int res = INT_MIN;

         int avg =0;

         for( int i= low; i<=high; i++){
            avg = avg+nums[i];


         }
          while(high<n){
             res = max(res,avg);
            low++;
            high++;
            if( high ==n){
                break;

            }
            avg = avg- nums[low-1];
            avg = avg+nums[high];

          }
return (double)res / k;

    }
};