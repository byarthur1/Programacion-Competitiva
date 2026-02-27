#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define int long long

long long inv;
long long N;

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
            inv += ((sa.size() - i)*N)%MOD;
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    cin >> N;
    merges(s, 0, s.size());

    cout << inv << endl;


    return 0;
}