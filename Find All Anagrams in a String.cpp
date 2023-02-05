class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> pcount;
        for(char c: p){
            if(pcount.find(c) == pcount.end()){
                pcount[c] = 1;
            }else{
                pcount[c]++;
            }
        }
        
        map<char, int> wcount;
        int start = 0, end = 0, match = 0;
        
        while(end < s.size()){
            char c1 = s[end];
            if(pcount.find(c1) != pcount.end()){
                //update wcount
                if(wcount.find(c1) == wcount.end()){
                    wcount[c1] = 1;
                }else{
                    wcount[c1]++;
                }
                
                if(pcount[c1] == wcount[c1])match++;
            }
            
           
            while(match == pcount.size()){
                
                if(end - start + 1 == p.size()){
                    ans.push_back(start);
                }
                
                
                char c2 = s[start];
                if(pcount.find(c2) != pcount.end()){
                    wcount[c2]--;
                    if(wcount[c2] < pcount[c2])match--;
                }
                start++;
            }
        
            end++;
        }
        
        return ans;
    }
};
