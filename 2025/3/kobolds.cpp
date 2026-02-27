#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    b = a;
    sort(b.begin(), b.end());

    int sol = 0, mx = 0, cmx = 0;

    for(int i=0; i<n; ++i){
 
        if(mx == 0 && a[i] == b[i]){
            sol++;
            continue;
        } 
        
        if(a[i] > mx){
            mx = a[i];
            cmx = 0;
            continue;
        }
 
        if(mx == b[i]){
            if(a[i] == b[i]) continue;
            if(cmx == 0){
                mx = 0;
                sol++;
                continue;
            }
            cmx--;
            continue;
        }
 
        
        if(a[i] == mx) cmx++;
 
    }

    cout << sol << '\n';

    return 0;
}