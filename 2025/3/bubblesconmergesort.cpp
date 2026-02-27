#include <bits/stdc++.h>
using namespace std;

int inversiones;

vector<int> mergesort(vector<int> & v, int l, int r){
    
    if(l == r){
        return {v[l]};
    }

    int m = (l+r)/2;
    vector<int> a = mergesort(v, l, m);
    vector<int> b = mergesort(v, m+1, r);

    vector<int> nuevo;
    auto it1 = a.begin(), it2 = b.begin();
    while(it1 != a.end() && it2 != b.end()){
        if(*it1 < *it2){
            nuevo.push_back(*it1);
            it1++;
            continue;
        }
        nuevo.push_back(*it2);
        inversiones += (a.end() - it1);
        it2++;
    }

    while(it1 != a.end()){
        nuevo.push_back(*it1);
        it1++;
    }

    while(it2 != b.end()){
        nuevo.push_back(*it2);
        it2++;
    }

    return nuevo;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n){
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        inversiones = 0;

        mergesort(v, 0, v.size() - 1);
        if(inversiones%2) cout << "Marcelo\n";
        else cout << "Carlos\n";

        cin >> n;
    }

    return 0;
}