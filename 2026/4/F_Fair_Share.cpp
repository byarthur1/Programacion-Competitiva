// https://codeforces.com/gym/672441/problem/F
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i){
        cin >> a[i] >> b[i];
    }

    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; ++i){
        sum1 += a[i];
        sum2 += b[i];
    }

    for(int i=0; i<n; ++i){
        int paga = sum2 - sum1 + a[i];
        if(paga <= b[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "impossible\n";

    return 0;
}