#include <TrocoSolver.h>

int min(int a,int b){
    if(a < b)
        return a;
    else return b;
}

void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {

    recursivecalls = 0;
    solveRecursive(denom,value,coins);
}

void TrocoSolverDivConquer::solveRecursive(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins){

    coins.resize(denom.size(),0);
    std::vector<unsigned int>partialCoins = coins;
    if(value == 0) return;

    int q = value;

    for(int i = denom.size()-1; i >= 0 ;i--){

        //std::cout<< "entrou";

        if(denom[i] <= value){

            for(int u = 0; u < partialCoins.size(); u++ ){
                partialCoins[u] = 0;
            }

            solveRecursive(denom,value-denom[i],partialCoins);
            recursivecalls++;

            int n = 0;
            for(int u = 0; u < partialCoins.size(); u++ ){
                n += partialCoins[u];
            }

            int aux = q;
            q = min(q,1 + n);
            
            if(q == 1 + n){

                for(int u = 0; u < partialCoins.size(); u++ ){
                    coins[u] = 0;
                    coins[u] += partialCoins[u];
                }
                coins[i]++;
            }
        }
    }   
}