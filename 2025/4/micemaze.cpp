#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        e--;

        vector<list<pair<int, int>>> v(n);
        for(int i=0; i<m; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            v[b-1].push_back({a-1, w});
        }

        vector<long long> dist(n);
        priority_queue<pair<int, int>> q;
        vector<bool> vt(n);

        //Dijkstra
        for(int i=0; i<n; ++i) dist[i] = LONG_LONG_MAX;
        dist[e] = 0;
        for(int i=0; i<n; ++i) vt[i] = false;
        q.push({0, e});
        while(!q.empty()){
            int a = q.top().second;
            q.pop();
            if(vt[a]) continue;
            vt[a] = true;
            for(auto p : v[a]){
                int b = p.first, w = p.second;
                if (dist[a]+w < dist[b]) {
                    dist[b] = dist[a]+w;
                    q.push({-dist[b],b});
                }
            }
        }
        int sol = 0;
        for(int i=0; i<n; ++i){
            if(dist[i] <= t) sol++;
        }

        cout << sol << endl;
        if(T>0) cout << endl;

    }

    return 0;
}