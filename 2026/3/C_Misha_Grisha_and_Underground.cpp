// https://codeforces.com/gym/671806/problem/C
#include <bits/stdc++.h>
using namespace std;

void rellenar_intervalos(vector<vector<int>>& grafo, vector<vector<int>>& inter, int& c, int i){

    inter[i][0] = c++;
    for(int hijo : grafo[i]) rellenar_intervalos(grafo, inter, c, hijo);
    inter[i][1] = c++;

}

void rellenar_dist_raiz(vector<vector<int>>& grafo, vector<int>& dist, int a, int distact){

    dist[a] = distact;
    for(int hijo : grafo[a]) rellenar_dist_raiz(grafo, dist, hijo, distact+1);

}

bool contenido(vector<vector<int>>& intervalos, int a, int b){ // true si b intervalo esta contenido en a intervalo
    return intervalos[a][0] <= intervalos[b][0] && intervalos[a][1] >= intervalos[b][1];
}

int loca(vector<vector<int>>& gt, vector<vector<int>>& intervalosgrafo, int a, int b){
    if(contenido(intervalosgrafo, a, b)) return a;
    if(contenido(intervalosgrafo, b, a)) return b;
    int desp = gt.size()-1;
    while(desp){

        int sucact = gt[desp][b];
        if(contenido(intervalosgrafo, sucact, a)){
            desp--;
        } else{
            b = sucact;
        }

    }

    if(!contenido(intervalosgrafo, gt[0][b], a)){
        b = gt[0][b];
    }

    return gt[0][b];

}

int calcular_distancia(vector<vector<int>>& gt, vector<vector<int>>& intervalosgrafo, vector<int>& dist, int a, int b){

    int padre = loca(gt, intervalosgrafo, a, b);
    int distancia = dist[a] + dist[b] - 2*dist[padre];
    return distancia;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q; // Recoger entradas

    vector<vector<int>> gt; //tabla para ver lo del least common ancestor, gt[0] sera el grafo original (1)
    vector<int> g(n); // = gt[0]
    vector<vector<int>> grafonormal(n); //el grafo pero al reves (2)
    vector<vector<int>> intervalosgrafo(n, vector<int>(2)); // tabla de intervalos
    vector<int> distraiz(n);    //Distancias a la raiz

    g[0] = 0;
    for(int i=0; i<n-1; ++i){  
        cin >> g[i+1]; // Regocemos el grafo (1)
        g[i+1]--;
        grafonormal[g[i+1]].push_back(i+1); // Recogemos el grafo (2)
    }
    gt.push_back(g);

    bool todoscero = true;
    do{     // Rellenamos la tabla gt
        todoscero = true;
        vector<int> ng(n);
        for(int i=0; i<n; ++i){
            ng[i] = gt[gt.size()-1][gt[gt.size()-1][i]];
            if(ng[i]) todoscero = false;
        }
        gt.push_back(ng);   
    } while(!todoscero);

    int cuenta = 0;
    rellenar_intervalos(grafonormal, intervalosgrafo, cuenta, 0); // Rellenamos la tabla de intervalos
    rellenar_dist_raiz(grafonormal, distraiz, 0, 0); // Rellenamos el vector de distancias

    for(int k=0; k<q; ++k){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        int r1 = loca(gt, intervalosgrafo, a, b);
        int r2 = loca(gt, intervalosgrafo, b, c);
        int r3 = loca(gt, intervalosgrafo, a, c);
        int inter = 0;
        if(r1 == r2 && r2 == r3) inter = r1;
        else inter = r1 == r2 ? r3 : (r1 == r3 ? r2 : r1);
        int d1 = calcular_distancia(gt, intervalosgrafo, distraiz, a, inter);
        int d2 = calcular_distancia(gt, intervalosgrafo, distraiz, b, inter);
        int d3 = calcular_distancia(gt, intervalosgrafo, distraiz, c, inter);
        cout << max(max(d1,d2),d3) + 1 << endl;

    }

    return 0;
}