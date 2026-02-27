#include <bits/stdc++.h>
using namespace std;

long long inv;

string merges(string& s, int a, int b){
    string sol;
    if(b-a == 1){
        sol.push_back(s[a]);
        return sol;
    }
    int mid = (a+b)/2;
    string sa = merges(s, a, mid);
    string sb = merges(s, mid, b);
    int i=0, j=0;
    while(i < sa.size() && j < sb.size()){
        if(sa[i] <= sb[j]){
            sol.push_back(sa[i]);
            i++;
        } else{
            sol.push_back(sb[j]);
            inv += sa.size() - i;
            j++;
        }
    }
    while(i < sa.size()){
        sol.push_back(sa[i]);
        i++;
    }
    while(j < sb.size()){
        sol.push_back(sb[j]);
        j++;
    }

    return sol;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    inv = 0;
    merges(s, 0, s.size());

    if(inv%3) cout << "Alice\n";
    else cout << "Bob\n";   

    return 0;
}