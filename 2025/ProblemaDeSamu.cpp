#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin >> a[i];

        vector<int> b = a;
        sort(b.begin(), b.end());
        map<int, int> c;
        for(int i=0; i<n; ++i) c[b[i]] = 0;

        int i=0, j=0;
        int sol = 0;
        while(i<n && j<n){
            if(c[a[i]] > 0){
                c[a[i]]--;
                i++;
                continue;
            }
            if(a[i] == b[j]){
                i++, j++;
                continue;
            }
            c[b[j]]++;
            sol++;
            j++;
        }

        cout << sol << endl;

    }

    return 0;
}