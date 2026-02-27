// https://codeforces.com/gym/669876/problem/D
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> q(n), r(n);
        for(int i=0; i<n; ++i) cin >> q[i];
        for(int i=0; i<n; ++i) cin >> r[i];

        sort(q.begin(), q.end());
        sort(r.rbegin(), r.rend());

        int res = 0;
        int i = 0, j = 0;

        while(i < n && j < n){
            int nk = (r[j]+1)*q[i] + r[j];
            if(nk > k){
                j++; 
                continue;
            }
            i++, j++;
            res++;
        }
        cout << res << endl;
    }

    return 0;
}