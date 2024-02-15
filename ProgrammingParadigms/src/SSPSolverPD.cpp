#include <SubsetSumSolver.h>
#include <iostream>


 bool SSPSolverPD::solve(const std::vector< long> &input,
                long value, std::vector< char> &output) {

    output.resize(input.size());
    std::vector<std::vector<bool>> B;

    B.resize(input.size() +1);

    for(int i = 0; i <= input.size(); i++){
        B[i].resize(value+1,false);
    }

    for(int k = 1; k<= input.size(); k++){
        for(int i = 1; i<= value; i++){
            B[k][i] = false;
        }
    }

    for(int i = 0; i <= input.size(); i++){
        B[i][0] = true;
    }

    for(int k = 1; k<= input.size(); k++){
        for(int i = 1; i<= value; i++){
            if(i < input[k-1])
                B[k][i] = B[k-1][i];
            else{
            if(B[k-1][i])
                B[k][i] = B[k-1][i];
            if (B[k-1][i-input[k-1]])
                B[k][i] = B[k-1][i -input[k-1]];
            }                
        }
    }


    int l = input.size();
    long i = value;

    if(B[input.size()][value]){
        while(i>0){
            while(B[l][i]){
                l = l - 1;
            }
            output[l] = true;
            i = i - input[l];
        }
    }

    return B[input.size()][value];
    
}
