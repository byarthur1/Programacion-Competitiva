// https://codeforces.com/gym/671803/problem/D
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<bool> v(n, false);
        for(int i=0; i<m; ++i){
            int a,b,c; cin >> a >> b >> c;
            v[b-1] = true;
        }
        int padre = -1;
        for(int i=0; i<n && padre == -1; ++i){
            if(!v[i]) padre = i;
        }
        padre++;
        for(int i=1; i<=n; ++i){
            if(i == padre) continue;
            cout << padre << ' ' << i << endl;
        }
    }

    return 0;
}