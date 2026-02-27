// https://codeforces.com/gym/669876/problem/F
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;
    set<char> sett;
    for(char c : s) sett.insert(c);
    int tiposdist = sett.size();

    int mini = INT_MAX, i=0, j=0;
    map<char, int> ms;
    ms[s[i]] = 1;
    int tipos = 1;
    if(tipos == tiposdist) mini = min(mini, j-i+1);
    while(j<s.size()){
        if(tipos < tiposdist){
            j++;
            if(j == s.size()){
                if(tipos == tiposdist) mini = min(mini, j-i+1);
                continue;
            }
            ms[s[j]]++;
            if(ms[s[j]] == 1) tipos++;
        } else{
            ms[s[i]]--;
            if(ms[s[i]] == 0) tipos--;
            i++;
        }
        if(tipos == tiposdist) mini = min(mini, j-i+1);
    }
    cout << mini << endl;

    return 0;
}