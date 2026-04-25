// https://codeforces.com/gym/686279/problem/A

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    int m;

    cin >> s;
    cin >> m;

    int n = s.size();
    int B = signed(ceil(sqrt(n)));

    vector<int> a(((n + B - 1) / B + 3), 0);

    for(int i=1; i<n; ++i){
        if(s[i-1] == s[i] && (i-1)/B == i/B) a[i/B]++;
    }

    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r;
        int res = 0;
        int techo1 = (l/B + 1)*B;
        int techo2 = (l/B + 1), techo3 = ((r)/B);
        int techo4 = r/B;
        techo4 = techo4 * B;
        if(techo4 < techo1) techo4 = INT_MAX;
        for(int i=l+1; i < min(techo1, r); ++i){
            if(s[i-1] == s[i]) res++;
        }
        for(int i = techo2; i < techo3; ++i){
            res += a[i];
            if(s[i*B-1] == s[i*B]) res++;
        }
        for(int i = techo4; i < r; ++i){
            if(s[i-1] == s[i]) res++;
        }

        cout << res << endl;
    }

    return 0;
}