// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem493.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
    int tmp[55000];//暂时容纳排序后的数
public:
    int reversePairs(vector<int>& nums) {
        return qsort(nums,0,nums.size()-1);
    }
    int qsort(vector<int>& nums,int l,int r){
        if(l>=r)return 0;//不存在或者只有一个没必要返回值了
        int ret=0;//统计值
        int k=(l+r)>>1;//归并的中间点
        ret+=qsort(nums,l,k);//左递归求左边
        ret+=qsort(nums,k+1,r);//右递归求右边
        int left=l,right=k+1;
//递归到最底层那么就是左数组一个数右数组一个数，一个数就相当于已经排过序了，直接统计后再排序因为要合并了左右当作新的左或者右数组
        while(left<=k&&right<=r){//二倍，因为可能越界所以/2.0
            if(nums[left]/2.0>nums[right]){ret+=r-right+1;left++;}
            else right++;//降序好处理
        }
         left=l,right=k+1;
         int i=0;//遍历
        while(left<=k&&right<=r){//合并
            if(nums[left]>nums[right]){tmp[i++]=nums[left++];}
            else tmp[i++]=nums[right++];
        }
        while(left<=k)tmp[i++]=nums[left++];//合并其余的
        while(right<=r)tmp[i++]=nums[right++];
        for(int i=l;i<=r;i++){//回归原来的数组使降序
            nums[i]=tmp[i-l];
        }
        return ret;
    }
    
};


// @lc code=end

