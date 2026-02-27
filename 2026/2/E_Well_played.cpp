// https://codeforces.com/gym/669876/problem/E
// Wrong Answer
#include <bits/stdc++.h>
#define int long long
using namespace std;

int expr(int a, int e){
    int r = 1;
    while(e){
        if(e & 1) r = (r*a);
        e >>= 1;
        a = (a*a);
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> hp(n), dmg(n);
    for(int i=0; i<n; ++i) cin >> hp[i] >> dmg[i];

    vector<pair<int, int>> dif, dam;
    for(int i=0; i<n; ++i){
        dif.push_back({hp[i]*expr(2,a) - dmg[i], i});
        dam.push_back({hp[i]-dmg[i],i});
    }
    sort(dif.rbegin(), dif.rend());
    sort(dam.rbegin(), dam.rend());

    vector<bool> visitado(n, false);
    int idxmaxi = dif.begin()->second;
    int res = 0;
    if(a > 0 && b > 0 && dif.begin()->first > 0){
        res = hp[idxmaxi]*expr(2,a);
        visitado[idxmaxi] = true;
        b--;
    }
    
    for(pair<int, int> p : dam){
        if(p.first <= 0) break;
        if(visitado[p.second]) continue;
        if(b == 0) break;
        res += hp[p.second];
        visitado[p.second] = true;
        b--;
    }

    for(int i=0; i<n; ++i){
        if(visitado[i]) continue;
        res += dmg[i];
    }

    cout << res << endl;

    return 0;
}