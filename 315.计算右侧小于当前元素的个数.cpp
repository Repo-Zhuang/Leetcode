/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        vector<pair<int,int>> copy;
        for (int i = 0; i < n; i++){
            copy.push_back({nums[i],i});
        }

        vector<pair<int,int> > temp = copy;
        vector<int> count(nums.size(),0);

        Merge_sort(copy, 0, n-1 ,temp, count);
 
        return count;

    }

    void Merge_sort(vector<pair<int,int>>& copy, int low, int high,  vector<pair<int,int>>& temp, vector<int>& count){

        if (low >= high) return;

        int mid = low +((high - low) >> 1);
        Merge_sort(copy, low , mid, temp, count);
        Merge_sort(copy, mid + 1, high, temp,count);
        Merge(copy, low , mid, high, temp,count);
    }
    void Merge(vector<pair<int,int>>& copy, int low, int mid, int high, vector<pair<int,int>>& temp, vector<int>& count){
         for (int i = low; i <= high; i++) {
            temp[i] = copy[i];
        }
        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++)
        {
            if (i == mid + 1)
            copy[p] = temp[j++];

            else if (j == high + 1) {
                copy[p] = temp[i++];
                count[copy[p].second] += j - mid - 1;
                
            }
            else if (temp[i].first > temp[j].first){
                copy[p] = temp[j++];

            }
            else {
                copy[p] = temp[i++];
                count[copy[p].second] += j - mid - 1;
                
            }
        }      
    }

};
// @lc code=end

