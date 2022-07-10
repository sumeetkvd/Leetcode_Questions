Wiggle Subsequence: -


The solution in Python: -

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) <= 1: return len(nums)
        prev_difference = nums[1] - nums[0]
        count = 2 if prev_difference != 0 else 1 
        for i in range(2, len(nums)):
            current_difference = nums[i] - nums[i-1]
            if (current_difference > 0 and prev_difference <=0 ) or (current_difference < 0 and prev_difference>=  0):
                count += 1
                prev_difference = current_difference
        return count


The solution in CPP: -

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        vector<pair<int, int>> vp;
        if (nums.size() < 2) return 1;
        vp.push_back({nums[0], 1});
        vp.push_back({-nums[0], 1});
        int maxv = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int dif = nums[i] - nums[i - 1];
            bool inserted = false;

            for (auto& el : vp)
            {
                if ((dif > 0 && el.first < 0) || (dif < 0 && el.first > 0))
                {
                    el.first = dif;
                    el.second++;
                    if (el.second > maxv) maxv = el.second;
                    inserted = true;
                    break;
                }                
                else if (dif == 0) break;
            }
            if (inserted)
            {
               sort(vp.begin(), vp.end(), [](const pair<int,int>& p1, const pair<int,int>& p2) {return p1.second > p2.second;});
            }
            else if (!inserted && dif != 0)
            {
                vp.push_back({nums[0], 1});
            }
        }


        return maxv;      
    }
};

