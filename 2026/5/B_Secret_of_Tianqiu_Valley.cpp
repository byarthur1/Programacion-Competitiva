// https://codeforces.com/gym/675184/problem/B
// Solucion no completa, esta no contempla no poder apagar antorchas encendidas

#include <bits/stdc++.h>
using namespace std;

string s, si;
list<int> l;
int n, moves;

void move(int i){
    moves++;
    l.push_back(i);
    s[i] = s[i] == '1' ? '0' : '1';
    s[(i+1)%n] = s[(i+1)%n] == '1' ? '0' : '1';
    s[(i-1+n)%n] = s[(i-1+n)%n] == '1' ? '0' : '1';
}

int recorrer(bool b1, bool b2){
    s = si;
    moves = 0;
    l.clear();
    vector<bool> vb(n, false);
    if(b1) move(0);
    if(b2) move(1);
    for(int i=2; i<n; ++i){
        string sss = s;
        if(s[i-1] == '0') {move(i); vb[i] = true; }
    }
    for(int i=n-2; i > 1; --i){
        if(s[i+1] == '0' && vb[i] == false) move(i);
    }
    for(int i=0; i<n; ++i){
    
        string sss = s;
        if(s[i] != '1') return -1;
    }
    string sss = s;
    return moves;
}

int main(){

    int t; cin >> t;

    while(t--){

        cin >> n;
        cin >> si;
        
        int res = recorrer(0,0);
        if(res < 0) res = recorrer(0,1);
        if(res < 0) res = recorrer(1,0);
        if(res < 0) res = recorrer(1,1);

        if(res == -1) cout << 0 << endl;
        else{
            cout << res << endl;
            for(auto it = l.begin(); it != l.end(); it++){
                if(it != l.begin()) cout << ' ';
                cout << *it;
            }
            cout << endl;
        }

    }

    return 0;
}