#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    vi lista;

    int n;
    while(cin >> n) lista.push_back(n);

    int num = lista.size();
    vi subsecuencia;
    vector<list<int>> indices;

    for(int i = 0; i < num; ++i) {
        auto index = lower_bound(subsecuencia.begin(), subsecuencia.end(), lista[i]);
        if(index == subsecuencia.end()) {
            subsecuencia.push_back(lista[i]);
            list<int> nueva;
            nueva.push_back(i);
            indices.push_back(nueva);
        }
        else{
            *index = lista[i];
            indices[index - subsecuencia.begin()].push_back(i);
        }
    }
    
    list<int> solucion;
    auto it = indices.end();
    if(it != indices.begin()) {
        it--;
        solucion.push_front((*it).back());
        while(it != indices.begin()) {
            it--;
            auto it2 = lower_bound((*it).begin(), (*it).end(), solucion.front());
            if(it2 != (*it).begin()) {
                it2--;
                solucion.push_front(*it2);
            }
        }
    }

    cout << subsecuencia.size() << "\n-\n";
    for(int i : solucion) cout << lista[i] << "\n";

    return 0;
}