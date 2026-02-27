#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char>(m));
    string s;
    for(int i=0; i<n; i++){
        getline(cin, s);
        for(int j=0; j<m; j++){
            cin.get(v[i][j]);
        }
    }
    int sol = 0;
    if(k == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == '.'){
                    sol++;
                }
            }
        }
        cout << sol << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        int it1 = 1, it2 = k;
        int c = 0;
        for(int j=0; j<k && j<m; j++){
            if(v[i][j] == '.'){
                c++;
            }
        }
        if(c == k){
            sol++;
        }
        while(it2 < m){
            if(v[i][it1-1] == '.'){
                c--;
            }
            if(v[i][it2] == '.'){
                c++;
            }
            if(c == k){
                sol++;
            }
            it1++, it2++;
        }
    }

    for(int j=0; j<m; j++){
        int it1 = 1, it2 = k;
        int c = 0;
        for(int i=0; i<k && i<n; i++){
            if(v[i][j] == '.'){
                c++;
            }
        }
        if(c == k){
            sol++;
        }
        while(it2 < n){
            if(v[it1-1][j] == '.'){
                c--;
            }
            if(v[it2][j] == '.'){
                c++;
            }
            if(c == k){
                sol++;
            }
            it1++, it2++;
        }
    }

    cout << sol << endl;

    return 0;
}