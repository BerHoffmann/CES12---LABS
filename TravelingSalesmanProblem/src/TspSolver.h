#ifndef TSP_SOLVER
#define TSP_SOLVER


#include <TspReader.h>
#include <vector>

class TspSolver {
public:
    // you should fill percourse with a permutation that represents the TSP solution
    void solve(TspReader &tr,std::vector<int> &percourse);

};

class Caminho{
public:
    int distancia,origem,destino;
    Caminho(int dist,int ori, int des){
        distancia = dist;
        origem = ori;
        destino = des;
    }
};

class MenorDisti {
public:
    bool operator()(Caminho & c1, Caminho & c2) {
        if(c2.distancia < c1.distancia) return true;
        if(c2.distancia == c1.distancia){
            if(c2.origem < c1.origem) return true;
        }
        if(c2.distancia == c1.distancia && c2.origem == c1.origem){
            if(c2.destino < c1.destino) return true;
        }
        return false;
    }
};



#endif
