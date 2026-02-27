#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define INF 1000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, caso = 1;
    cin >> a >> b;
    while(a || b){
        vector<pair<int, int>> v;
        v.push_back({a-1, b-1});
        cin >> a >> b;
        while(a || b){
            v.push_back({a-1, b-1});
            cin >> a >> b;
        }

        vector<vector<int>> c(MX, vector<int>(MX, INF));
        for(int i=0; i<MX; ++i) c[i][i] = 0;
        for(auto x : v){
            c[x.first][x.second] = 1;
        }
        for(int k=0; k<MX; ++k) for(int i=0; i<MX; ++i) for(int j=0; j<MX; ++j){
            c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        }

        long long sum = 0;
        unordered_set<int> s;
        for(int i=0; i<MX; ++i) for(int j=0; j<MX; ++j){
            if(c[i][j] < INF && i != j){
                sum += c[i][j];
                s.insert(i);
                s.insert(j);
            }
        }
        long long pair_of_nodes = (s.size())*(s.size()-1);
        double sol = ((double)sum)/((double)pair_of_nodes);
        cout << fixed << setprecision(3);
        cout << "Case " << caso << ": average length between pages = " << sol << " clicks\n";

        cin >> a >> b;
        caso++;
    }

    return 0;
}