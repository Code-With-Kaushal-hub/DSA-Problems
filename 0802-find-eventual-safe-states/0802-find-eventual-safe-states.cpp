class Solution {
public:
   
   bool dfs(int src, vector<int>&vis,vector<int>&rec,vector<vector<int>>& graph){
        vis[src]=1;
        rec[src]=1;
        for(int i:graph[src]){
            if(!vis[i]){
                if(dfs(i,vis,rec,graph)){return true;}
            }
            else{
                if(rec[i]){return true;}
            }
        }
        rec[src]=0;
    
        return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
         vector<int>rec(graph.size(),0);
         vector<int>ans;
        for(int i=0;i<graph.size();i++){
            if(!dfs(i,vis,rec,graph)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};