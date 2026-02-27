#include <bits/stdc++.h>
using namespace std;

int p, n;
vector<int> c;
pair<int, int> dp[10001][101];

pair<int, int> rec(int P, int N){

    if(P <= 0) return {-P, 0};
    if(N < 0) return {INT_MAX, INT_MAX};
    if(dp[P][N] != make_pair(-1, -1)) return dp[P][N];

    pair<int, int> a1 = rec(P-c[N], N-1), a2 = rec(P, N-1);
    a1.second++;

    return dp[P][N] = min(a1, a2);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> p >> n;
        int aux;
        c.clear();
        for(int i=0; i<n; ++i){
            cin >> aux;
            c.push_back(aux);
        }

        for(int i=0; i<=p; ++i) for(int j=0; j<n; ++j) dp[i][j] = {-1, -1};

        auto sol = rec(p, n-1);
        cout << sol.first + p << ' ' << sol.second << '\n';

    }

    return 0;   
}