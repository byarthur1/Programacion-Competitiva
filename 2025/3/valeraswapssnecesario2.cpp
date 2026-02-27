#include <bits/stdc++.h>
using namespace std;

int encuentra(vector<int>& a, int x){
    if(a[x] < 0) return x;
    return a[x] = encuentra(a, a[x]);
}

void unionn(vector<int>& a, int x, int y){
    int rx = encuentra(a, x);
    int ry = encuentra(a, y);
    if(rx == ry) return;
    if(a[rx] < a[ry]) a[ry] = rx;
    else{
        if(a[rx] == a[ry]) a[ry]--;
        a[rx] = ry;
    } 
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n), v(n);
    for(int i = 0; i<n; ++i){
        a[i] = -1;
    }

    list<list<int>> grafos;
    int aux, aux2;
    cin >> aux;
    while(aux){
        list<int> nueva;
        for(int i=0; i<aux; ++i){
            cin >> aux2;
            aux2--;
            nueva.push_back(aux2);
        }
        grafos.push_back(nueva);
        cin >> aux;
    }

    for(list<int> l : grafos){
        if(l.empty()) continue;
        auto it = l.begin();
        int p = *it;
        it++;
        while(it != l.end()){
            unionn(a, p, *it);
            it++;
        }
    }

    for(int i=0; i<n; ++i) cout << a[i] << ' ';
    cout << endl;

    return 0;
}