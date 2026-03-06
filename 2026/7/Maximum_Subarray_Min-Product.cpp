// https://leetcode.com/problems/maximum-subarray-min-product/description/

#include <bits/stdc++.h>
using namespace std;

int maxSumMinProduct(vector<int>& nums) {
        
    int n = nums.size();
    vector<long long> sumi(n), sumd(n);
    vector<int> l(n), r(n);
    stack<int> st;
    for(int i=0; i<n; ++i){
        while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
        if(!st.empty()) l[i] = st.top();
        else l[i] = -1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; --i){
        while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
        if(!st.empty()) r[i] = st.top();
        else r[i] = -1;
        st.push(i);
    }

    long long sumatotal = 0;
    for(int i=0; i<n; ++i){
        sumi[i] = sumatotal;
        sumatotal += nums[i];
    }
    sumatotal = 0;
    for(int i=n-1; i>=0; --i){
        sumd[i] = sumatotal;
        sumatotal += nums[i];
    }
    long long maxi = 0;
    for(int i=0; i<n; ++i){
        int a = l[i] == -1 ? 0 : l[i]+1, 
            b = r[i] == -1 ? n-1 : r[i]-1;
        long long suma = sumatotal - sumi[a] - sumd[b];
        maxi = max(maxi, suma*nums[i]);
    }

    return maxi%1000000007;
}
    
int main(){

    vector<int> v = {1,2,3,2};
    maxSumMinProduct(v);
}