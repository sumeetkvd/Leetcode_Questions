class Solution {
public:
    int greatestCommonDivisor(int x, int y){
        if(x < y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        
        while(y != 0){
            int org_y = y;
            y = x % y;
            x = org_y;
        }
        
        return x;
    }
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size();
        int gcd = greatestCommonDivisor(l1, l2);
        string sgcd = str1.substr(0, gcd);
        for(int i = 0; i < l1/gcd; i++){
            if(str1.substr(i*gcd, gcd) != sgcd)
                return "";
        }
        for(int i = 0; i < l2/gcd; i++){
           
            if(str2.substr(i*gcd, gcd) != sgcd)
                return "";
        }
        
        return sgcd;
    }
};
