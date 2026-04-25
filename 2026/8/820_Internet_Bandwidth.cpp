// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=761
// Sobre este tema: https://cp-algorithms.com/graph/edmonds_karp.html

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, contador = 1;
    cin >> n;
    while(n){

        int s, t, c;
        cin >> s >> t >> c;
        s--, t--;
        vector<vector<int>> arista(n, vector<int>(n, 0));
        vector<vector<int>> grafo(n);
        for(int i=0; i<c; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            if(arista[a-1][b-1] == 0){
                grafo[a-1].push_back(b-1);
                grafo[b-1].push_back(a-1);
            }
            arista[a-1][b-1] = arista[b-1][a-1] += w;
        }

        vector<int> ant(n, -1);
        long long flow = 0;

        queue<pair<int, int>> q;
        bool nofin = true;
        while(nofin){
            ant[s] = -2;
            q.push({s, INT_MAX});
            int mini = -1;

            while(!q.empty()){
                int nact = q.front().first;
                int w = q.front().second;
                if(nact == t) {mini = w; break;}
                q.pop();
                for(int nn : grafo[nact]){
                    if(ant[nn] == -1 && arista[nact][nn] > 0){
                        ant[nn] = nact;
                        q.push({nn, min(arista[nact][nn], w)});
                    }
                }
            }

            if(q.empty()) nofin = false;
            if(mini != -1){
                int nact = ant[t], nnext = t;
                while(nact != -2){
                    arista[nact][nnext] -= mini;
                    //arista[nnext][nact] += mini;
                    nnext = nact;
                    nact = ant[nact];
                }
                flow += mini;
            }

            fill(ant.begin(), ant.end(), -1);
            while(!q.empty()) q.pop();
        }

        cout << "Network " << contador << endl;
        cout << "The bandwidth is " << flow << ".\n\n";

        contador++;
        cin >> n;
    }

    return 0;
}