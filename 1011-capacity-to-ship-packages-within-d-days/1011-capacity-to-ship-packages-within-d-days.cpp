class Solution {
public:
    bool fun(vector<int>& weights,int i,int days){
        int n_days=1,wthold=0;
        for(int j=0;j<weights.size();j++ ){
            if(wthold+weights[j]<=i){
               wthold+= weights[j];
            }
            else{
                n_days++;
                wthold=weights[j];
            }
        }
        if(n_days<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ma=INT_MIN;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
            ma=max(ma,weights[i]);
        }
        int low=ma;
        int high=sum;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(fun(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};