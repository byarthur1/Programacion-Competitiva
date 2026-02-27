#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while(n){
        vector<int> v(n);
        for(int i=0; i<n; ++i){
            int aux;
            cin >> aux;
            v[i] = aux - 1;
        }
        
        long long sol = 0;
        vector<bool> b(n);
        for(int i=0; i<n; ++i) b[i] = false;
        for(int i=0; i<n; ++i){
            if(v[i] == i) continue;
            if(b[i]) continue;
            int current = i, original = i;
            do{
                current = v[current];
                b[current] = true;
                sol++;
            } while(current != original);
            sol--;
        }

        if(sol%2) cout << "Marcelo\n";
        else cout << "Carlos\n";

        cin >> n;
    }

    return 0;
}