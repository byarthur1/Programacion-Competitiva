// https://codeforces.com/gym/669876/problem/G
#include <bits/stdc++.h>
using namespace std;

void contar(vector<string>& s, int i, int & st){
    for(char c : s[i]){
        if(((st >> (c - 'a')) & 1)){
            st &= ~(1 << (c - 'a'));
        } else{
            st |= (1 << (c - 'a'));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; ++i) cin >> s[i];

    map<int, int> m;
    for(int i=0; i<n; ++i){
        int st = 0;
        contar(s, i, st);
        m[st] = m[st] + 1;
    }

    long long res = 0;
    for(int i=0; i<n; ++i){
        int st = 0;
        contar(s, i, st);
        list<char> lista;
        for(int k=0; k < 26; ++k) if((st >> k) & 1) lista.push_back(k + 'a');
        res += m[st];
        for(char c : lista){
            st &= ~(1 << (c - 'a'));
            res += 2*m[st];
            st |= (1 << (c - 'a'));
        }
    }

    cout << (res-n)/2 << endl;

    return 0;
}