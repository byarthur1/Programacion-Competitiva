// https://codeforces.com/gym/666098/problem/C
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; ++i) cin >> s[i];

    map<pair<int, int>, long long> mdi, md, mii, mi;

    for(int i=0; i<n; ++i){

        int sum = 0;
        for(char c : s[i]) sum += c - '0';
        mdi[{s[i].size(),sum}] = mdi[{s[i].size(),sum}] + 1;
        mii[{s[i].size(),sum}] = mii[{s[i].size(),sum}] + 1;

        int k = 1;
        int tami = s[i].size() - 1, tamd = 1;
        int sumi = sum - (s[i][0] - '0'), sumd = s[i][0] - '0';

        for(k; tami > tamd; ++k){
            md[{tami - tamd, sumi - sumd}] = md[{tami - tamd, sumi - sumd}] + 1;
            tami--, tamd++;
            sumi -= s[i][k] - '0', sumd += s[i][k] - '0';
        }
        if(tami == tamd) tamd--, tamd++;
        for(k; tamd < s[i].size(); ++k){
            mi[{tamd - tami, sumd - sumi}] = mi[{tamd - tami, sumd - sumi}] + 1;
            tami--, tamd++;
            sumi -= s[i][k] - '0', sumd += s[i][k] - '0';
        }

    }

    long long res = 0;

    for(auto it = mi.begin(); it != mi.end(); it++){
        res += mdi[it->first]*(it->second);
    }
    for(auto it = mii.begin(); it != mii.end(); it++){
        res += mdi[it->first]*(it->second);
        res += md[it->first]*(it->second);
    }

    cout << res << endl;

    return 0;
}