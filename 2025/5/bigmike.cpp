#include <bits/stdc++.h>
using namespace std;

#define int long long

int exponenciacionyeso(int a, int e, int m){
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = (r * a) % m;
        e >>= 1;
        a = (a * a) % m;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int b, p, m;
    while (cin >> b >> p >> m){
        cout << exponenciacionyeso(b, p, m) << '\n';
    }

    return 0;
}