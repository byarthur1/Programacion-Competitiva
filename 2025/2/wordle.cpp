#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, g;
    cin >> n;
    vector<string> N(n);
    for(int i=0; i<n; ++i) cin >> N[i];
    cin >> g;
    vector<string> G(g);
    for(int i=0; i<g; ++i) cin >> G[i];

    for(int j=0; j<g; ++j){

        int sol = 0;

        unordered_multiset<char> letras_g;
        for(int k=0; k<SIZE; ++k){
            if(G[j][k] != '*'){
                letras_g.insert(N[0][k]);
            }
        }
        
        for(int i=0; i<n; ++i){

            unordered_multiset<char> letras_e = letras_g;

            bool cont = false;
            for(int k=0; k<SIZE; ++k){
                if(G[j][k] == '*'){
                    if(N[0][k] != N[i][k]){
                        cont = true;
                        break;
                    }
                    continue;
                }
                if(G[j][k] == '!'){
                    if(N[i][k] == N[0][k] || letras_e.count(N[i][k]) == 0){
                        cont = true;
                        break;
                    }
                    letras_e.extract(N[i][k]);
                    continue;
                }
                //Caso G[j][k] == 'X'
                if(N[i][k] == N[0][k] || letras_e.count(N[i][k]) > 0){
                    cont = true;
                    break;
                }
            }
            if(cont) continue;
            sol++;
        }

        cout << sol << '\n';
        
    }

    return 0;
}