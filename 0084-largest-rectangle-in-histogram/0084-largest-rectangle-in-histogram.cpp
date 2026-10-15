class Solution {
public:
    
    void nexts(vector<int>& heights,int n,vector<int>&nextsmall){
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&heights[s.top()]>heights[i]){
                nextsmall[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }

    }
   
    void pres(vector<int>& heights,int n,vector<int>&presmall){
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>heights[i]){
                presmall[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }

    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nextsmall(n,n);
        vector<int>presmall(n,-1);
        
        nexts(heights,n,nextsmall);
        pres(heights,n,presmall);
        vector<int>ans;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,(nextsmall[i]-presmall[i]-1)*heights[i]);
        }
        return mx;
    }
};