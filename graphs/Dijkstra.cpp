#include <bits/stdc++.h>
#define INF 9999999
#define MAXN 100000

using namespace std;

typedef pair<int,int> pii;
vector<pii> adjlist[MAXN];
int distancias[MAXN];

void Dijkstra(int s){
    for(int i = 0; i < MAXN; i++){
        distancias[i] = INF;
    }
    distancias[s] = 0;
    priority_queue< pii, vector<pii>, greater<pii> >heap;
    heap.push({0,s});
    while(!heap.empty()){
        int dist, atualvertex;
        dist = heap.top().first;
        atualvertex = heap.top().second;
        heap.pop();
        if(dist > distancias[atualvertex]){
            continue;
        }
        for(int i = 0; i < (int)adjlist[atualvertex].size(); i++){
            int dist2, proxvertex;
            dist2 = adjlist[atualvertex][i].first;
            proxvertex = adjlist[atualvertex][i].second;
            if(distancias[proxvertex] > distancias[atualvertex] + dist2){
                distancias[proxvertex] = distancias[atualvertex] + dist2;
                heap.push({distancias[proxvertex], proxvertex});
            }
        }
    }
}
