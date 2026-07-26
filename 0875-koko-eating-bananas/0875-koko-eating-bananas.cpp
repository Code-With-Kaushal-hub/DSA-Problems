class Solution {
public:
    bool fun(vector<int>& piles, int k, int h) {

    long long hours = 0;

    for(int i = 0; i < piles.size(); i++) {

        hours += (piles[i] + k - 1) / k;

        if(hours > h)
            return false;
    }

    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int low=1;
        int high=mx;
        while(low<high){
            int mid=low+(high-low)/2;
            if(fun(piles, mid, h)){
                high=mid;}
            else{
                low=mid+1;
            }
        }
        return low;
    }
};