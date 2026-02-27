#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> max_prime (n+1);
    for(int i=0; i<n+1; ++i) max_prime[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (max_prime [i] == i) {
            for (int j = i + i; j <= n; j += i)
            max_prime[j] = i;
        }
    }
    
    vector<list<int>> a(n+1);
    for(int i=2; i<n+1; ++i){
        vector <pair <int, int>> fact;
        int n = i;
        while(n != 1){
            int p = max_prime[n];
            n /= p;
            if(fact.empty () || fact.back ().first != p)
                fact.emplace_back (p, 1);
            else fact.back ().second ++;
        }

        for(auto p : fact) a[i].push_back(p.first);
    }
    a[1].push_back(1);

    vector<int> primos(n+1);
    for(int i=0; i<n+1; ++i) primos[i] = 0;

    int i;
    char c;
    for(int k=0; k<m; ++k){
        cin >> c >> i;
        
        if(c == '+'){

            if(primos[a[i].front()] == i){
                cout << "Already on\n";
                continue;
            }
            bool conflicto = false;
            for(auto x : a[i]){
                if(primos[x] > 0){
                    conflicto = true;
                    cout << "Conflict with " << primos[x] << '\n';
                    break;
                }
            }
            if(conflicto) continue;

            for(auto x : a[i]){
                primos[x] = i;
            }
            cout << "Success\n";

            continue;
        }
        // c == '-'

        if(primos[a[i].front()] != i){
            cout << "Already off\n";
            continue;
        }
        for(auto x : a[i]){
            primos[x] = 0;
        }
        cout << "Success\n";

    }

    return 0;
}