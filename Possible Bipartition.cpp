
class Solution {
public:
    vector<vector<int>> graph;
    map<int, int> color;
    
    bool dfs(int node, int c){
        if(color.find(node) != color.end()){
            return color[node] == c;
        }
        
        color[node] = c;
        
        for(int nei : graph[node]){
            if(!dfs(nei, 1-c)){
                return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N+1);
        
        for(vector<int>& edge : dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int node = 1; node <= N; ++node){
            if(color.find(node) == color.end() && 
              !dfs(node, 0) 
              ){
                return false;
            }
        }
        
        return true;
    }
};
