class Solution {
public:
    unordered_map<int,vector<int>>m;
    stack<int>s;
    bool dfs(int src,vector<int> &vis,vector<int> &recpath){
        vis[src]=1;
        recpath[src]=1;
        for(int i:m[src]){
            if(!vis[i]){
                if(dfs(i,vis,recpath)){
                    return true;
                }
               
            }
            else{
                if(recpath[i]){
                    return true;
                }
            }
        }
        recpath[src]=0;
        s.push(src);
        return false;
       
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>recpath(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]!=1){
                if(dfs(i,vis,recpath)){
                    return false;
                }
            }
        }
        return true;
      
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>vec;
        if(canFinish(numCourses,prerequisites)){
              while(!s.empty()){
                vec.push_back(s.top());
                s.pop();
              }
        }
        return vec;

        
    }
};
    