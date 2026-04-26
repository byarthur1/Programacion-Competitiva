// https://codeforces.com/gym/675184/problem/B

#include <bits/stdc++.h>
using namespace std;

int n;

void chosen(vector<bool>& v, string& s, int i, bool modo){
    v[i] = modo;
    s[i] = s[i] == '0' ? '1' : '0';
    s[(i-1+n)%n] = s[(i-1+n)%n] == '0' ? '1' : '0';
    s[(i+1)%n] = s[(i+1)%n] == '0' ? '1' : '0';
}

pair<vector<bool>, bool> res(string s, bool el1, bool el2){
    vector<bool> nuevo(n, false);
    if(el1) chosen(nuevo, s, 0, true);
    if(el2) chosen(nuevo, s, 1, true);
    for(int i=2; i<n; ++i){
        if(s[i-1] == '0') chosen(nuevo, s, i, true);
    }
    for(int i=0; i<n; ++i){
        if(s[i] == '0') return {{0}, false};
    }
    return {nuevo, true};
}

pair<vector<bool>, bool> cuales_tocar(string s){

    auto p = res(s, false, false);
    if(!p.second) p = res(s, false, true);
    if(!p.second) p = res(s, true, false);
    if(!p.second) p = res(s, true, true);
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;

    while(t--){
        cin >> n;
        string s; cin >> s;

        auto p = cuales_tocar(s);
        if(!p.second){
            cout << "0\n";
        } else{
            
            vector<bool> por_tocar = p.first;
            list<int> tocados;
            int num_por_tocar = 0;
            queue<int> q;

            for(int i=0; i<n; ++i){
                if(por_tocar[i]){
                    num_por_tocar++;
                    if(s[i] == '0') q.push(i);
                }
            }

            int idx = 0;

            while(num_por_tocar > 0){
                if(!q.empty()){
                    int act = q.front(); q.pop();

                    if(por_tocar[act] && s[act] == '0'){
                        chosen(por_tocar, s, act, false);
                        tocados.push_back(act+1);
                        num_por_tocar--;
                        if(por_tocar[(act-1+n)%n] && s[(act-1+n)%n] == '0') q.push((act-1+n)%n);
                        if(por_tocar[(act+1)%n] && s[(act+1)%n] == '0') q.push((act+1)%n);
                    }
                } else{
                    int pos1 = -1, pos2 = -1;
                    for(int i=0; i<n; ++i){
                        int nidx = (idx+i)%n;
                        if(s[nidx] == '0'){
                            if(por_tocar[(nidx-1+n)%n] || por_tocar[(nidx+1)%n]){
                                pos1 = nidx;
                                idx = nidx;
                                break;
                            }
                            if(pos2 == -1) pos2 = idx;
                        }
                    }
                    int sac = (pos1 != -1) ? pos1 : pos2;
                    chosen(por_tocar, s, sac, true);
                    tocados.push_back(sac+1);
                    num_por_tocar++;

                    if(por_tocar[(sac-1+n)%n] && s[(sac-1+n)%n] == '0') q.push((sac-1+n)%n);
                    if(por_tocar[(sac+1)%n] && s[(sac+1)%n] == '0') q.push((sac+1)%n);
                }
            }

            cout << tocados.size() << "\n";
            bool notprimero = false;
            for(auto x : tocados){
                if(notprimero) cout << ' ';
                else notprimero = true;
                cout << x;
            }
            cout << "\n";
        }

    }

    return 0;
}
