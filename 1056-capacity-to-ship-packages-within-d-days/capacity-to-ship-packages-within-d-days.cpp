class Solution {
public:

    bool canShip( vector<int> &weights, int days, int capacity){
        int dayCount =1;
        int currLoad = 0;

        for( int w : weights){
            if( currLoad + w > capacity){  // then we have to start the new day

            dayCount++;
            currLoad =0;
                
            }

            currLoad += w;
        }

        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low =  *max_element(weights.begin(), weights.end());
        int high=  accumulate(weights.begin(), weights.end(), 0);



        while(low < high){
            int mid = low +(high - low ) / 2;

            if(canShip(weights,  days , mid)){
                high = mid;

            }
            else{
                low = mid +1;
            }
        }
        return low;




        
    }
};