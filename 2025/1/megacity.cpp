#include <bits/stdc++.h>
using namespace std;

bool probamos(double m, int n, int s, vector<int> & x, vector<int> & y, vector<int> & k){

    long long sol = s;

    for(int i=0; i<n; ++i){
        if(x[i]*x[i] + y[i]*y[i] <= m*m) sol += k[i];
    }

    return sol < 1000000;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> x(n), y(n), k(n);
    for(int i=0; i<n; ++i){
        cin >> x[i] >> y[i] >> k[i];
    }

    double l = 0, r = sqrt(2*10000*10000) + 1;

    while(l + 1e-8 < r){

        double mid = (l + r)/2;
        if( probamos(mid, n, s, x, y, k) ) l = mid;
        else r = mid;

    }

    if(r >= sqrt(2*10000*10000) + 1) cout << -1 << '\n';
    else cout << fixed << setprecision(7) << l << '\n';

    return 0;
}