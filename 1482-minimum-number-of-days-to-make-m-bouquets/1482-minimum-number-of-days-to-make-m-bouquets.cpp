class Solution {
public:
bool fun(vector<int>& bloomDay, int m,int k,int T) {

    int boke=0;int flower=0;

    for(int i = 0; i < bloomDay.size(); i++) {
        if(bloomDay[i]<=T){
            flower++;
            if(flower==k){
                boke++;
                flower=0;
            }
        }
        else{
            flower=0;
        }
    }
    if(boke>=m){
        return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
    if((long long)m * k > bloomDay.size())
            return -1;
    int ma=*max_element(bloomDay.begin(),bloomDay.end());
    int mi=*min_element(bloomDay.begin(),bloomDay.end());
    int low=mi;
    int high=ma;
    while(low<high){
            int mid=low+(high-low)/2;
            if(fun(bloomDay, m,k,mid)){
                high=mid;}
            else{
                low=mid+1;
            }
        }
    return low;
    }
    
};