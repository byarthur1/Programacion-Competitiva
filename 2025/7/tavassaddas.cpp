#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    
    long long sol = pow(2, s.size()) - 1;
    for(int i = s.size() - 1, j = 0; i>=0; --i, ++j){
        if(s[i] == '7') sol += pow(2, j);
    }

    cout << sol << endl;

    return 0;
}