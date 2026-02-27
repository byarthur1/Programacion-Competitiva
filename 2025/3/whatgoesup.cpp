#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    int aux;
    while(cin >> aux) v.push_back(aux);

    int n = v.size();
    vector<int> a;
    vector<list<int>> indices;

    for(int i=0; i<n; ++i){
        auto it = lower_bound(a.begin(), a.end(), v[i]);
        if(it == a.end()) {
            a.push_back(v[i]);
            list<int> nueva;
            nueva.push_back(i);
            indices.push_back(nueva);
        }
        else {
            *it = v[i];
            indices[it - a.begin()].push_back(i);
        }
    }

    list<int> sol;
    auto it = indices.end();
    if(it != indices.begin()){
        it--;
        sol.push_front((*it).back());
        while(it != indices.begin()){
            it--;
            auto it2 = lower_bound((*it).begin(), (*it).end(), sol.front());
            if(it2 != (*it).begin()){
                it2--;
                sol.push_front(*it2);
            } 
        }
    }

    cout << a.size() << "\n-\n";
    for(int i : sol) cout << v[i] << '\n';

    return 0;
}