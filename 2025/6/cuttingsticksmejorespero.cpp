#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX/10

int l, n;
vector<int> c;
int dp[1001][1001];

int rec(int a, int b, int idx_a, int idx_b){

    if(idx_a > idx_b) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    
    int sol = INF;
    for(int i=idx_a; i<=idx_b; ++i){
        sol = min(sol, b - a + rec(a, c[i], idx_a, i-1) + rec(c[i], b, i+1, idx_b));
    }
    return dp[a][b] = sol;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int aux;
    cin >> l;

    while(l){
        cin >> n;
        c.clear();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; ++i){
            cin >> aux;
            c.push_back(aux);
        }

        cout << "The minimum cutting is " << rec(0, l, 0, n-1) << ".\n";

        cin >> l;
    }

    return 0;
}