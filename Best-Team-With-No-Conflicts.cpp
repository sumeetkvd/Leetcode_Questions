class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<int> players(n);
        iota(players.begin(), players.end(), 0);
        
        //sort 
        sort(players.begin(), players.end(), 
            [&](int& p1, int& p2){
                return (ages[p1] == ages[p2]) ? (scores[p1] < scores[p2]) : (ages[p1] < ages[p2]);
            });
        
        vector<int> dp(n);
        int pi, pj;
       
        for(int i = 0; i < n; ++i){
            pi = players[i];
            dp[i] = scores[pi];
            for(int j = 0; j < i; ++j){
                pj = players[j];
                if(scores[pj] <= scores[pi]){
                    dp[i] = max(dp[i], dp[j]+scores[pi]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
