#include <TrocoSolver.h>

void TrocoSolverGreedy::solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins) {

    // fills a dummy answer with 3 coins of each denomination    
    //coins.resize(denom.size(),3);

    coins.resize(denom.size(),0);
    int troco = 0;
    if(value == 0) return;
    int i = denom.size() - 1;

    while((troco < value) && (i >= 0)){
        
        while(troco < value){
            coins[i]++;
            troco += denom[i];
        }

        if(troco == value) return;

        coins[i]--;
        troco -= denom[i];
        i--;
    }
    
}//solve

// dica: iterar um vetor de tras pra frente
//https://stackoverflow.com/questions/3610933/iterating-c-vector-from-the-end-to-the-begin
//http://www.cplusplus.com/reference/vector/vector/rbegin/
