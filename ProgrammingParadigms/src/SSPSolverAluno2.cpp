#include <SubsetSumSolver.h>
#include <tgmath.h>
#include <iostream>
#include <bits/stdc++.h>

 bool Sum(std::vector<long> X, int n, long k, std::vector<char> &out){
    if(n == 0){ 
        if(k == X[0]){
            out[n] = true;
            return true;
        }
        if(k == 0)
            return true;
        
        return false;
    }
        
    if(k == 0){ 
        return true;
    }
    bool a = false;
    bool b = false; 

    if (X[n] <= k){
        a =  Sum(X,n-1,k-X[n],out);
    }
    if(a == false)
        b = Sum(X,n-1, k,out);
    out[n] = a;
    return a || b; 

}
 

/// Aluno2: segunda solucao do aluno = Meet-in-the-Middle OU Branch & Bound
 bool SSPSolverAluno2::solve(const std::vector< long> &input,
                            long value, std::vector< char> &output) {
    output.resize(input.size(),false);

    return Sum(input,input.size()-1, value, output);
    
}


