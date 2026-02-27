#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    long long a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b%a == 0) cout << (b*b)/a << '\n';
        else cout << lcm(a, b) << '\n';
    }

    return 0;
}