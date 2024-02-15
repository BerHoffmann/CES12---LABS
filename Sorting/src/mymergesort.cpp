
#include <mysortfunctions.h>
#include <iostream>

std::vector<int> aux;

void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;

    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int i = 0;
    aux.resize(v.size());

    int depth = MergeSort(v, i, v.size()-1, stats);
    stats.depth_recursion_stack = depth;
    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";
}

int MergeSort(std::vector<int> &v, int i, int f, SortStats &stats){
    int depth;
    stats.recursive_calls +=1;
    if (i < f){
        int m = (i + f) / 2;
        int a = MergeSort(v, i, m, stats);
        int b = MergeSort(v, m+1,f, stats);
        merge(v, i,m,f);

        if(a>=b)
            depth = a + 1;
        else{
            depth = b + 1;
        }
        return depth;
    }
    return 1;
}

void merge(std::vector<int> &v, int i, int m, int f){
    int i1 = i;
    int i2 = i;
    int i3 = m + 1;
    while(i2 <= m && i3 <= f){
        if(v[i2] < v[i3])
            aux[i1++] = v[i2++];
        else
            aux[i1++] = v[i3++];
    }
    while (i2 <= m)
        aux[i1++] = v[i2++];
    while (i3 <= f)
        aux[i1++] = v[i3++];
    for (int j=i; j<=f; j++)
        v[j] = aux[j];
}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats){
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int i = 0;
    it_MergeSort(v, i, v.size()-1,stats);

    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";
}

void it_MergeSort(std::vector<int> &v, int i, int f, SortStats &stats){
    stats.recursive_calls +=1;
    stats.depth_recursion_stack +=1;
    int b = 1;
    while (b < f) {
        int p = i;
        while (p+b <= f) {
            int r = std::min(f, p-1+2*b);
            int m = p+b-1;
            merge(v, p, m, r);
            p += 2*b;
        }
        b *= 2;
    }
}
