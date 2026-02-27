#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 1001;
    vector <bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primos;
    for(int i=0; i<n; ++i) if(is_prime[i]) primos.push_back(i);

    int N, k;
    cin >> N >> k;

    int sol = 0;
    for(int i=2; i<=N; i++){
        if(!is_prime[i]) continue;
        for(int j=0; j<primos.size()-1; j++){
            if(i == primos[j] + primos[j+1] + 1){
                sol++;
                break;
            }
        }
    }

    if(sol >= k) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}