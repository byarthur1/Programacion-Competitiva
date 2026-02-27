#include <bits/stdc++.h>
using namespace std;

int N, p;

void precalcularcosas(vector<long long>& ft, int n){
    ft[0] = ft[1] = 1;
    long long mult = 1;
    for(int i = 2; i <= n; ++i){
        mult = (mult*i)%p;
        ft[i] = mult;
    }
}

long long exponenciacionyeso(long long a, long long e){
    long long r = 1;
    while (e)
    {
        if (e & 1)
            r = (r * a) % p;
        e >>= 1;
        a = (a * a) % p;
    }
    return r;
}

long long calcular_cuenta(vector<long long>& ft, long long eln, vector<int> div){

    long long mult = 1;
    for(auto x : div){
        mult = (mult*ft[x])%p;
    }

    mult = exponenciacionyeso(mult, p-2);

    return (ft[eln] * mult)%p;

}

void solucionar(vector<long long>& f, vector<long long>& ft, int n){
    
    vector <int> max_prime (n+1);
    for(int i=0; i<n+1; ++i) max_prime[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (max_prime [i] == i) {
            for (int j = i + i; j <= n; j += i)
            max_prime[j] = i;
        }
    }
    

    for(int i=2; i<n+1; ++i){
        vector <pair <int, int>> fact;
        int n = i;
        int sum = 0;
        while(n != 1){
            int p = max_prime[n];
            sum  += p;
            n /= p;
            if(fact.empty () || fact.back ().first != p)
                fact.emplace_back (p, 1);
            else fact.back ().second ++;
        }

        if(fact.size() < 1) continue;
        if(fact.size() > 1 || fact.back().second > 1){
            int unos = i - sum;
            long long eln = unos;
            vector<int> div;
            div.push_back(unos);
            for(auto p : fact){
                div.push_back(p.second);
                eln += p.second;
            }
            if(eln > N) continue;
            long long cuenta = calcular_cuenta(ft, eln, div);
            f[eln] = (f[eln] + cuenta) % p;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> p;
    vector<long long> f(N+1, 0);
    long long NN = 1000000;
    vector<long long> ft(NN + 1);
    precalcularcosas(ft, NN);

    solucionar(f, ft, NN);

    for(int i = 2; i <= N; ++i){
        if(i > 2) cout << ' ';
        cout << f[i];
    }
    //cout << endl;

    return 0;
}