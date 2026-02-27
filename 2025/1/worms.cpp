#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> pile(n);
    for(int i = 0; i < n; ++i){
        cin >> pile[i];
        if(i > 0) pile[i] += pile[i-1];
    }
    cin >> m;
    
    for(int i=0; i<m; ++i){
        int juicy;
        cin >> juicy;
        cout << lower_bound(pile.begin(), pile.end(), juicy) - pile.begin() + 1 << "\n";
    }

    return 0;
}