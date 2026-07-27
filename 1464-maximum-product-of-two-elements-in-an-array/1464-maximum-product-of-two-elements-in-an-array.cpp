class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q;
        for(int i:nums){
            q.push(i);
        }
        int x=q.top()-1;
        q.pop();
        int y=q.top()-1;
        q.pop();
        return x*y;
        
    }
};