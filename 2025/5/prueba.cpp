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

    for(int i = 0; i<=100; ++i) cout << ", " << i << ": " << max_prime[i];
    cout << endl;
    cin >> n;

    vector <pair <int, int>> fact;
    while(n != 1){
        int p = max_prime[n];
        n /= p;
        if(fact.empty() || fact.back().first != p)
            fact.emplace_back (p, 1);
        else fact.back ().second ++;
    }

    for(auto p : fact) cout << ' ' << p.first << ' ' << p.second;


    return 0;
}