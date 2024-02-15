#include <TspSolver.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

std::vector<std::vector<float>> mapa;

int dis(int i, int j){
    return (int)round( sqrt( (mapa[i][0]-mapa[j][0])*(mapa[i][0]-mapa[j][0]) + (mapa[i][1]-mapa[j][1])*(mapa[i][1]-mapa[j][1]) ) );
}

void preOrdem(std::vector<std::vector<int>> G, std::vector<int> &v,int n){
    
    if(G[n].size() == 0){
        v.push_back(n);
        return;
    }

    v.push_back(n);
    for(int i = 0; i < G[n].size(); i++){
        
        preOrdem(G,v,G[n][i]);
        
    }

}

void TspSolver::solve(TspReader &tr,std::vector<int> &percourse) {
        // here it is filling the vector with  1,2,3,...n
        // you should fill it with a permutation that represents the TSP solution

    City c;

    int n = tr.getNumCities();

    mapa.resize(tr.getNumCities()+1);

    for (int i = 1; i <= tr.getNumCities(); i++){
        mapa[i].resize(2);
    }

    int i = 1;
    while (tr.getCities(c)){
        float x = c.getx();
        float y = c.gety();
        mapa[i][0] = x;
        mapa[i][1] = y;
        i++;
    }

    std::priority_queue<Caminho,std::vector<Caminho>, MenorDisti> heap;
    std::vector<std::vector<int>> Gmin;
    Gmin.resize(n+1);
    std::vector<bool> ad;

    ad.resize(n + 1, false);
    
    int o = 1;

    for(int d = 1; d <= n; d++){
        if(d != o){
            Caminho c(dis(o,d),o,d);
            heap.push(c);
        }
    }
    
    ad[1] = true;

    while(!heap.empty()){

        if(ad[o] == false){
            ad[o] = true;
            for(int d = 1; d <= n; d++){
                if(d != o){
                    Caminho c(dis(o,d),o,d);
                    heap.push(c);
                }
            }
        }

        if(ad[heap.top().destino] == false && ad[heap.top().origem] == true ){
            Gmin[heap.top().origem].push_back(heap.top().destino);
            o = heap.top().destino;
        }

        heap.pop();
    }

    preOrdem(Gmin,percourse,1);


     
}//solve
