// https://codeforces.com/gym/675184/problem/A
// Time limit exceeded
#include <bits/stdc++.h>
using namespace std;

vector<int> fact_primos(vector<int>& primos, int x){
    vector<int> res;
    for(int i=0; i<primos.size() && primos[i] <= x*x; ++i){
        if(x%primos[i] == 0) res.push_back(primos[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n = 31630;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }

    vector<int> primos;
    for(int i=2; i<n; ++i){
        if(is_prime[i]) primos.push_back(i);
    }

    int t; cin >> t;

    while(t--){

        int a, b; 
        cin >> a >> b;

        int mini = INT_MAX;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0,{a,b}});

        while(!pq.empty()){
            
            int pasos = (-1)*pq.front().first, ax = pq.front().second.first, bx = pq.front().second.second;
            pq.pop();
            if(pasos >= mini) continue;
            if(ax == 1 || bx == 1) {mini = min(mini, pasos); continue; }
            int mcd = gcd(ax, bx);
            if(mcd > 1){
                vector<int> factoresprimos = fact_primos(primos, mcd);
                for(int x : factoresprimos){
                    pq.push({-(pasos+1), {ax/x, bx/x}});
                }
            }
            pq.push({-(pasos+1), {ax-1, bx-1}});
            pq.push({-(pasos+1), {ax+1, bx+1}});

        }

        cout << mini << endl;


    }

    return 0; /a
}