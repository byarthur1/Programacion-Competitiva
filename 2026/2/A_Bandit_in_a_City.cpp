// https://codeforces.com/gym/669876/problem/A
#include <bits/stdc++.h>
#define int long long
using namespace std;

tuple<int, int, int> rec(vector<vector<int>>& p, vector<int>& a, int n){
    if(p[n].empty()) return {1, a[n], a[n]};
    int hojas = 0, suma = 0, maxi = 0;
    for(int x : p[n]){
        tuple<int, int, int> devo = rec(p,a,x);
        hojas += get<0>(devo);
        suma +=  get<1>(devo);
        maxi = max(maxi, get<2>(devo));
    }

    int faltan = maxi*(hojas) - suma;
    if(a[n] <= faltan){
        return {hojas, a[n] + suma, maxi};
    }

    int repartir = a[n] - faltan;
    if(repartir%hojas == 0) repartir--;
    maxi += repartir/hojas + 1;

    return {hojas, a[n] + suma, maxi};
}

signed main(){

    int n;
    cin >> n;

    vector<vector<int>> p(n);
    for(int i=0; i<n-1; ++i){
        int x; cin >> x;
        p[x-1].push_back(i+1);
    }
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    cout << get<2>(rec(p,a,0)) << endl;

    return 0;
}