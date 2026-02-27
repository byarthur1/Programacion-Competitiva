#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n, k;
    string s;
    cin >> t;
    while(t--){

        cin >> n >> k;
        getline(cin, s);

        vector<char> v(n);
        for(int i=0; i<n; i++){
            cin.get(v[i]);
        }
        int it1 = 1, it2 = k;
        int cw = 0;
        for(int i=0; i<k; ++i){
            if(v[i] == 'W'){
                cw++;
            }
        }
        int mini = cw;
        while(it2 < n){
            if(v[it1-1] == 'W'){
                cw--;
            }
            if(v[it2] == 'W'){
                cw++;
            }
            mini = min(mini, cw);
            it1++, it2++;
        }
        cout << mini << endl;

    }

    return 0;
}