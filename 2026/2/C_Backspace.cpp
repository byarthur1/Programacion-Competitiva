// https://codeforces.com/gym/669876/problem/C
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int q; cin >> q;
    while(q--){

        string s, t;
        cin >> s >> t;
        int i = 0, j = 0;

        while(i < s.size()){
            if(j < t.size() && s[i] == t[j]) i++, j++;
            else{
                i += 2;
            }
        }

        bool ya = false;
        if(i == s.size() && j == t.size()){
            ya = true;
        }
        if(!ya){
            i = 1, j = 0;
            while(i < s.size()){
                if(j < t.size() && s[i] == t[j]) i++, j++;
                else{
                    i += 2;
                }
            }   
            if(i == s.size() && j == t.size()){
                ya = true;
            }
        }
        if(ya) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}