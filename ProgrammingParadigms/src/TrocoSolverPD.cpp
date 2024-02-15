#include <TrocoSolver.h>

void TrocoSolverPD::solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins) {

    // fills a dummy answer with 2 coins of each denomination    
    //coins.resize(denom.size(),2); 
    
    std::vector<unsigned int> quant;
    std::vector<unsigned int> ultima;

    coins.resize(denom.size(),0);
    quant.resize(value+1);
    ultima.resize(value+1);

    quant[0] = 0;
    ultima[0] = 0;

    for(int cents = 1; cents <= value; cents++){
        int quantProv = cents;
        int ultProv = 0;

        for(int j = 0; j < denom.size(); j++){
            if(denom[j]>cents) continue;
            if(quant[cents-denom[j]] + 1 < quantProv){
                quantProv = quant[cents - denom[j]] + 1;
                ultProv = j;
            }
        }
        quant[cents] = quantProv;
        ultima[cents] = ultProv;
    }
    
        int j = value;
        while(j > 0){
            coins[ultima[j]]++;
            j = j - denom[ultima[j]];
        }

}//solve
