#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX/10

int l, n;
vector<int> c;
int dp[1001][1001];

int rec(int a, int b, int idx){
    if(idx >= n) return INF;
    if(idx > -1 && c[idx] >= b) return INF;
    if(dp[a][b] != -1) return dp[a][b];
    
    int it = idx;
    if(idx == -1) it = lower_bound(c.begin(), c.end(), a) - c.begin();
    if(it >= n) return 0;
    if(c[it] == a){
        it++;
        if(it >= n) return 0;
    }
    if(c[it] >= b) return dp[a][b] = 0; 
    int c1 = b - a + rec(a, c[it], -1) + rec(c[it], b, -1);
    int c2 = rec(a, b, it + 1);
    return dp[a][b] = min(c1, c2);
    
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

        cout << "The minimum cutting is " << rec(0, l, -1) << ".\n";

        cin >> l;
    }

    return 0;
}