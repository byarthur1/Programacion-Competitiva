#include <bits/stdc++.h>
using namespace std;

string s, t;

bool comprobar(int is, int it, int dir){

    if(it >= t.size()) return true;
    if(is >= s.size() || s[is] != t[it]) return false;
    if( dir > 0 ){
        return comprobar(is+1, it+1, 1) || comprobar(is-1, it+1, -1);
    }
    return comprobar(is-1, it+1, -1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q;

    while(q--){

        cin >> s;
        cin >> t;
        bool ey = true;
        for(int i=0; i<s.size() && ey; ++i){
            if(s[i] == t[0] && comprobar(i, 0, 1)){
                ey = false;
            }
        }
        if(ey) cout << "NO\n";
        else cout << "YES\n";

    }

    return 0;
}