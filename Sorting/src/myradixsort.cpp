
#include <mysortfunctions.h>


void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;
    radix(v,stats);
    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";
}

void radix(std::vector<int> &v, SortStats &stats){
    stats.recursive_calls +=1;
    stats.depth_recursion_stack +=1;

    int max = v.size();
    int d = 0;


    while(max > 0 ){
        max = max >> 4;
        d++;
    }
    
    typedef std::queue<int> fila;
    std::vector<fila> vec;
    vec.resize(16);
    
    int mask = 15;

    for(int i = 0; i<d; i++){
        int k = 0;
        if(i != 0) mask = mask << 4;
        for(int j=0; j< v.size(); j++){
            int digito = (v[j] & mask);
            digito = digito >> 4*i;
            vec[digito].push(v[j]);
        }
        for(int j = 0; j< 16; j++){
            while(!vec[j].empty()){
                v[k++] = vec[j].front();
                vec[j].pop();
            }
        }
    }
}
