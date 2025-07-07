class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort (events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>>pq;   //min-Heap

        int day = events[0][0];
        int i =0;
        int count =0;
        int n = events.size();
        
        while(!pq.empty() || i< n){
            while(i<n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                count++;
            }
            day++;

            while(!pq.empty() && pq.top() < day){     // skiping the elements
            
                pq.pop();
            }
        } 

        return count;


    }
};