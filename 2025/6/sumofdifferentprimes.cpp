#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primos;
int dp[1121][189][16];

void obtener_primos(int n){

    vector <bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i=0; i<n; ++i) if(is_prime[i]) primos.push_back(i);

}

int rec(int x, int k, int ks, int sum, int idx){
    if(sum == x){
        if(ks == k) return 1;
        return 0;
    }
    if(idx >= primos.size() || sum > x || primos[idx] > x || ks >= k) return 0;
    if(dp[sum][idx][ks] != -1) return dp[sum][idx][ks];
    return dp[sum][idx][ks] = rec(x, k, ks, sum, idx + 1) + rec(x, k, ks + 1, sum + primos[idx], idx + 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    obtener_primos(1121);

    int n, k;
    cin >> n >> k;
    while(n || k){
        memset(dp, -1, sizeof(dp));
        cout << rec(n, k, 0, 0, 0) << endl;
        cin >> n >> k;
    }

    return 0;
}