#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, b, p;
    // n = lugares en la ciudad
    // m = carreteras
    // b = bancos
    // p = comisarias

    while(cin >> n >> m >> b >> p){
        
        vector<list<pair<int, int>>> G(n); // el grafo
        vector<int> B(b); // bancos
        vector<int> P(p); // comisarias
        vector<int> dist_fin(b); // distancia minima a la que estará algún banco de una comisaria

        for(int i=0; i<m; ++i){
            int u, v, t;
            cin >> u >> v >> t;
            G[u].push_back({v, t});
            G[v].push_back({u, t});
        }
        for(int i=0; i<b; ++i) cin >> B[i];
        for(int i=0; i<p; ++i) cin >> P[i];
        for(int i=0; i<b; ++i) dist_fin[i] = INT_MAX;


        vector<int> dist(n);
        priority_queue<pair<int, int>> q;
        vector<bool> vt(n);

        for(int i=0; i<n; ++i) dist[i] = INT_MAX;
        for(int i=0; i<n; ++i) vt[i] = false;
        for(auto x : P){
            dist[x] = 0;
            q.push({0, x});
        }

        while(!q.empty()){
            int a = q.top().second;
            q.pop();
            if(vt[a]) continue;
            vt[a] = true;
            for(auto p : G[a]){
                int b = p.first, w = p.second;
                if (dist[a]+w < dist[b]) {
                    dist[b] = dist[a]+w;
                    q.push({-dist[b],b});
                }
            }
        }

        for(int i=0; i<b; ++i){
            dist_fin[i] = dist[B[i]];
        }

        int maxi = -1;
        vector<int> sol;
        for(int i=0; i<b; ++i){
            if(dist_fin[i] == maxi){
                sol.push_back(B[i]);
                continue;
            }
            if(dist_fin[i] > maxi){
                sol.clear();
                sol.push_back(B[i]);
                maxi = dist_fin[i];
                continue;
            }
        }

        sort(sol.begin(), sol.end());

        cout << sol.size() << ' ';
        if(maxi == INT_MAX) cout << '*';
        else cout << maxi;
        cout << '\n';
        for(int i=0; i<sol.size(); ++i){
            if(i>0) cout << ' ';
            cout << sol[i];
        }
        cout << endl;

    }

    return 0;
}