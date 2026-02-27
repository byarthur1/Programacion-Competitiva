#include <bits/stdc++.h>
using namespace std;

int consumo(int v, int w){

    return 500 + floor((v+w)/10) + floor(((v+w)*(v+w))/100000);

}

long long predicado(int x, vector<int> & d, vector<int> & w, int n){

    long long sol = 0;
    for(int i=0; i<n; ++i){
        sol += d[i]*consumo(x, w[i]);
    }
    return sol;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n;

    while(cin >> c >> n){
        vector<int> d(n), w(n);
        for(int i=0; i<n; ++i) cin >> d[i] >> w[i];

        //Busqueda binaria sobre la solucion

        int l = 0, r = 30000;
        while(l + 1 < r){

            int mid = (l+r)/2;
            if(predicado(mid, d, w, n) <= c) l = mid;
            else r = mid;

        }

        cout << l << '\n';

    }

    return 0;
}