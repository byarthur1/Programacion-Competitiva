// https://codeforces.com/gym/666098/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string t;
    cin >> t;

    deque<char> a, b;

    bool nofin = true;
    for(int i=0, j=t.size()-1; nofin && i<t.size() - 1 && j>0; ++i, --j){
        a.push_back(t[i]);
        b.push_front(t[j]);
        if(i>=j && a == b){
            nofin = false;
        }
    }
    if(nofin) cout << "NO\n";
    else{
        cout << "YES\n";
        for(char c : a) cout << c;
        cout << '\n';
    }

    return 0;
}