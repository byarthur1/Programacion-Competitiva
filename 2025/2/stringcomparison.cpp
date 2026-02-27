#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s, t;
    cin >> n >> s >> t;

    long long sol = 0;
    long long iguales_acumulados = 0;

    for(int i=0; i<n; ++i){
        if(s[i] > t[i]){
            iguales_acumulados = 0;
            continue;
        }
        if(s[i] < t[i]){
            if(iguales_acumulados > 0){
                sol += iguales_acumulados*(n-i);
                iguales_acumulados = 0;
            }
            sol += n-i;
            continue;
        }
        iguales_acumulados++;
    }

    cout << sol << "\n";

    return 0;
}