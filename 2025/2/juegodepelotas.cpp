#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }

    list<pair<int, int>> l;
    int c = 0, ii = -1;
    for(int i=0; i<n; ++i){
        if(v[i] == x){
            if(c == 0) ii = i;
            c++;
            continue;
        }
        if(c > 1){
            l.push_back({ii, ii + c - 1});
            c = 0;
        }
        if(c > 0) c = 0;
    }

    if(c > 1){
        l.push_back({ii, ii + c - 1});
        c = 0;
    }

    int maxi = 0;
    for(pair<int, int> p : l){
        int i = p.first, j = p.second;
        int sum = j - i + 1;
        i--, j++;
        while(i >= 0 && j < n){
            if(v[i] != v[j]) break;

            int ko = v[i];
            int suum = 0;
            while(i >= 0 && v[i] == ko){
                suum++;
                i--;
            }
            while(j < n && v[j] == ko){
                suum++;
                j++;
            }
            if(suum > 2) sum += suum;
            else break;
        }

        if(maxi < sum) maxi = sum;
    }

    cout << maxi << endl;

    return 0;
}