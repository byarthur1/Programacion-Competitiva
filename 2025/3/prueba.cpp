#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<pair<int, int>> l;
    l.push_back(make_pair(1, 2));
    l.push_back(make_pair(3, 5));
    l.push_back(make_pair(1, 1));
    sort(l.begin(), l.end());
    for(pair<int, int> p : l){
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}