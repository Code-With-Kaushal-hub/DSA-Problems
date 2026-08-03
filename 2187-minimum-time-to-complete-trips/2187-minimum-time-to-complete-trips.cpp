class Solution {
public:
   bool fun(vector<int>& time, int totalTrips,long long j){
        long long count=0;
        
        for(int i=0;i<time.size();i++){
            if(j>=time[i]){
               
                 count=count+j/time[i];
            }
            if(count>=totalTrips){
                return true;
            }

        }
        
        
        return false;
   }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1;
       
        int mi=*min_element(time.begin(),time.end());
        long long high=(long long)totalTrips*mi;
        while(low<high){
            long long mid=low+(high-low)/2;
            if(fun(time,totalTrips,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};