#include <bits/stdc++.h>
using namespace std;

bool interseccion_nula(int a, int b, int c, int d){
    //False si la intersección es nula, True en caso contrario
    return (c < b && c >= a || d <= b && d > a || c < a && d > b);
}

bool se_cumple(vector<int>& d, vector<int>& a, vector<int>& b, int n, int a_idx, int b_idx){

    vector<int> a1(n), a2(n), b1(n), b2(n), c1(n), c2(n);

    int i=a_idx;
    a1[i] = 0;
    for(int l=1; l<n; ++l){
        a2[i] = a1[i] + a[i];
        ++i;
        if(i==n){
            i=0;
            a1[i] = a2[n-1] + d[n-1];
        } else{
            a1[i] = a2[i-1] + d[i-1];
        }
    }
    a2[i] = a1[i] + a[i];

    i=b_idx;
    b1[i] = 0;
    for(int l=1; l<n; ++l){
        b2[i] = b1[i] + b[i];
        ++i;
        if(i==n){
            i=0;
            b1[i] = b2[n-1] + d[n-1];
        } else{
            b1[i] = b2[i-1] + d[i-1];
        }
    }
    b2[i] = b1[i] + b[i];

    for(int l=0; l<n; ++l){
        if(interseccion_nula(a1[l], a2[l], b1[l], b2[l])) return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> d(n), a(n), b(n), c(n);
    for(int i=0; i<n; ++i) cin >> d[i];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n; ++i) cin >> c[i];

    vector<vector<int>> r_ab(n), r_ac(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i == j) continue;
            if(se_cumple(d, a, b, n, i, j)){
                r_ab[i].push_back(j);
            }
            if(se_cumple(d, a, c, n, i, j)){
                r_ac[i].push_back(j);
            }
        }
    }
    list<pair<int, int>> r_bc;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i == j) continue;
            if(se_cumple(d, b, c, n, i, j)){
                r_bc.push_back({i, j});
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(pair<int, int> p : r_bc){
            if(binary_search(r_ab[i].begin(), r_ab[i].end(), p.first) && binary_search(r_ac[i].begin(), r_ac[i].end(), p.second)){
                cout << i+1 << ' ' << p.first+1 << ' ' << p.second+1 << '\n';
                return 0;
            }
        }
    }

    cout << "impossible\n";
    return 0;
}

/*bool se_cumple_todo(vector<int>& d, vector<int>& a, vector<int>& b, vector<int>& c, int n, int a_idx, int b_idx, int c_idx){
    vector<int> a1(n), a2(n), b1(n), b2(n), c1(n), c2(n);

    int i=a_idx;
    a1[i] = 0;
    for(int l=1; l<n; ++l){
        a2[i] = a1[i] + a[i];
        ++i;
        if(i==n){
            i=0;
            a1[i] = a2[n-1] + d[n-1];
        } else{
            a1[i] = a2[i-1] + d[i-1];
        }
    }
    a2[i] = a1[i] + a[i];

    i=b_idx;
    b1[i] = 0;
    for(int l=1; l<n; ++l){
        b2[i] = b1[i] + b[i];
        ++i;
        if(i==n){
            i=0;
            b1[i] = b2[n-1] + d[n-1];
        } else{
            b1[i] = b2[i-1] + d[i-1];
        }
    }
    b2[i] = b1[i] + b[i];

    i=c_idx;
    c1[i] = 0;
    for(int l=1; l<n; ++l){
        c2[i] = c1[i] + c[i];
        ++i;
        if(i==n){
            i=0;
            c1[i] = c2[n-1] + d[n-1];
        } else{
            c1[i] = c2[i-1] + d[i-1];
        }
    }
    c2[i] = c1[i] + c[i];

    for(int l=0; l<n; ++l){
        if(interseccion_nula(a1[l], a2[l], b1[l], b2[l]) || 
           interseccion_nula(a1[l], a2[l], c1[l], c2[l]) || 
           interseccion_nula(b1[l], b2[l], c1[l], c2[l])) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> d(n), a(n), b(n), c(n);
    for(int i=0; i<n; ++i) cin >> d[i];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n; ++i) cin >> c[i];

    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k){
        if(se_cumple_todo(d, a, b, c, n, i, j, k)){
            cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}
    */