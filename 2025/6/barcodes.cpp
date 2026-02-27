#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, m;
int dp[51][51];
// primera posicion = x que toca
// segunda posicion = cuantas "barras" llevamos

int rec(int x, int cb){
    // x = posicion que vamos a ver si añadir o no
    // cb = cuantas "barras" llevamos

    if(x >= n){
        if(cb == k) return 1;
        return 0;
    } 

    if(dp[x][cb] != -1) return dp[x][cb];

    int sol = 0;
    for(int i=1; i<=m && x+i <= n; ++i){
        sol += rec(x+i, cb+1);
    }
    return dp[x][cb] = sol;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> k >> m){
        memset(dp, -1, sizeof(dp));

        cout << rec(0, 0) << endl;
    }
    

    return 0;
}