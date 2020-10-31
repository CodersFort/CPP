/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>res_hash;
        vector <int> result;
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(res_hash.find(target-nums[i])!=res_hash.end())
            {
                
                result.push_back(res_hash[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            else
                res_hash[nums[i]] = i;
        }     
        return result;  
    }
};

int main(){
    Solution sol;
    vector <int> nums, res;
    int target = 22;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    res = sol.twoSum(nums,target);
    int i;
    for(i=0;i<res.size();i++){
        cout<<res[i]<<", ";
    }
}
