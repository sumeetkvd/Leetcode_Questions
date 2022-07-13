Remove Linked List Element: -


The solution in CPP: -


class Solution {
public:
    int countPrimes(int n) {
        if(n==1 or n==0) return 0;
        vector<int>arr(n+1,0);
        for(int i=2;i*i<=n;i++){
            if(arr[i]==0){
                for(int j=i;j*i<=n;j++){
                    arr[i*j]=1;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(arr[i]==0){
                ans++;
            }
        }
        return ans;
    }
};



