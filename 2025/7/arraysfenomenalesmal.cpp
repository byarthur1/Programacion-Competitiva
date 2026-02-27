#include <bits/stdc++.h>
using namespace std;
 
int n, p;
vector<int> v;
 
bool esfenomenal(){
    long long m = 1, s = 0;
    for(int i=0; i<v.size(); ++i){
        m *= v[i];
        s += v[i];
    }
    return m == s;
}
 
void rec(vector<int>& f){
 
    if(v.size()>=2){
        if(esfenomenal()){
            f[v.size()] = (f[v.size()] + 1) % p;
            for(int i=0; i<v.size(); ++i) cout << v[i] << ' ';
            cout << endl;
        }
        if(v.size() >= n){
            return;
        }
    }
 
    for(int i=1; i<=n; ++i){
        v.push_back(i);
        rec(f);
        v.pop_back();
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> p;
    vector<int> f(n+1, 0);
    rec(f);
 
    for(int i=2; i<=n; ++i){
        if(i > 2) cout << " ";
        cout << f[i];
    }
 
    return 0;
}