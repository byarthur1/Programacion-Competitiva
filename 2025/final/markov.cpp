#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, p, l, aux1, aux2, a, b;
    cin >> n >> m >> p >> l;
    vector<vector<int>> g(n+1);
    for(int i=0; i<m; ++i){
        cin >> aux1 >> aux2;
        g[aux1].push_back(aux2);
        g[aux2].push_back(aux1);
    }

    map<pair<int, int>, vector<int>> mapa;

    for(int i=0; i<p; ++i){
        vector<int> horarios;
        for(int j=0; j<l; ++j){
            cin >> aux1;
            horarios.push_back(aux1);
        }
        for(int j=0; j<horarios.size(); ++j){
            mapa[{horarios[j], horarios[(j+1)%horarios.size()]}].push_back(j);
            mapa[{horarios[(j+1)%horarios.size()], horarios[j]}].push_back(j);
        }
    }

    cin >> a >> b;

    vector<long long> dist(n+1);
    priority_queue<pair<int, int>> q;
    vector<bool> vt(n+1);

    for(int i=0; i<n+1; ++i) dist[i] = LONG_LONG_MAX;
    dist[a] = 0;
    for(int i=0; i<n+1; ++i) vt[i] = false;
    q.push({0, a});
    while(!q.empty()){
        int a = q.top().second;
        int momento = (-1)*(q.top().first);
        q.pop();
        if(vt[a]) continue;
        vt[a] = true;
        for(auto p : g[a]){
            int sumar = 0;
            int b = p, w = 1;
            if(mapa.count({a, b})){
                bool no_es_posible = true;
                while(no_es_posible && sumar<l){
                    no_es_posible = false;
                    for(auto x : mapa[{a, b}]){
                        if((momento+sumar)%l == x){
                            no_es_posible = true;
                            break;
                        }
                    }
                    if(no_es_posible) sumar++;
                }
                if(sumar == l) continue;
            }
            if (dist[a]+w+sumar < dist[b]) {
                dist[b] = dist[a]+w+sumar;
                q.push({-dist[b],b});
            }
        }
    }

    if(dist[b] == LONG_LONG_MAX) cout << "IMPOSSIBLE\n";
    else cout << dist[b] << endl;

    return 0;
}