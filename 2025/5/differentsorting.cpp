#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 2000000;
    vector <int> max_prime (n+1);
    for(int i=0; i<n+1; ++i) max_prime[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (max_prime [i] == i) {
            for (int j = i + i; j <= n; j += i)
            max_prime[j] = i;
        }
    }
    
    vector<pair<int, int>> a(2000001);
    a[0] = {0, 0};
    a[1] = {1, 1};
    for(int i=2; i<2000001; ++i){
        vector <pair <int, int>> fact;
        int n = i;
        while(n != 1){
            int p = max_prime[n];
            n /= p;
            if(fact.empty () || fact.back ().first != p)
                fact.emplace_back (p, 1);
            else fact.back ().second ++;
        }

        a[i].first = 0;
        a[i].second = i;
        for(auto p : fact){
            a[i].first += p.second;
        }
    }

    sort(a.begin(), a.end());

    cin >> n;
    int k=1;
    while(n){

        cout << "Case " << k++ << ": " << a[n].second << '\n';
        cin >> n;
    }

    return 0;
}