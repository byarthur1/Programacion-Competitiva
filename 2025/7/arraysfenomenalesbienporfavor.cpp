#include <bits/stdc++.h>
using namespace std;

int N, p;
vector<int> d;
vector<pair<int, int>> aux;
long long dmult, dsum;

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

void precalcularcosas(vector<long long>& ft, vector<long long>& ft2, int n){
    ft[0] = ft[1] = 1;
    ft2[0] = ft2[1] = 1;
    long long mult = 1;
    for(int i = 2; i <= n; ++i){
        mult = (mult*i)%p;
        ft[i] = mult;
        ft2[i] = exponenciacionyeso(mult, p-2)%p;
    }
}

long long calcular_cuenta(vector<long long>& ft, vector<long long>& ft2, long long eln, int unos){

    long long mult = 1;
    for(auto x : aux){
        mult = (mult*ft2[x.second])%p;
    }
    mult = (mult*ft2[unos])%p;

    return (ft[eln] * mult)%p;

}

void solucion(vector<int>& f, vector<long long>& ft, vector<long long>& ft2){

    if(dmult > 2*N) return;

    if(d.size() > 1){
        int tam = d.size();
        int multiplicacion = dmult;
        vector<pair<int, int>> xd = aux;
        int numUnos = dmult - dsum;
        long long eln = d.size() + numUnos;
        if(eln > N) return;
        f[eln] = (f[eln] + calcular_cuenta(ft, ft2, eln, numUnos))%p;
    }

    for(int i=d.back(); i<N+1; ++i){
        d.push_back(i);
        dmult = dmult * i;
        dsum = dsum + i;
        bool supongamos = true;
        if(aux.back().first == i){
            aux.back().second++;
            supongamos = false;
        } else{
            aux.push_back({i, 1});
        }
        solucion(f, ft, ft2);
        d.pop_back();
        dmult = dmult / i;
        dsum = dsum - i;
        if(supongamos){
            aux.pop_back();
        } else{
            aux.back().second--;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> p;
    vector<int> f(N+1, 0);
    vector<long long> ft(N+1);
    vector<long long> ft2(N+1);
    precalcularcosas(ft, ft2, N);
    for(int i=2; i<N+1; ++i){
        d.push_back(i);
        dmult = dsum = i;
        aux.push_back({i, 1});
        solucion(f, ft, ft2);
        d.pop_back();
    }

    for(int i=2; i<=N; ++i){
        if(i > 2) cout << ' ';
        cout << f[i];
    }
    cout << endl;

    return 0;
}