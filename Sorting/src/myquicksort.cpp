
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, 
// or create a generic quicksort that can work with different functions to select the pivot.

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int depth = QuickSort2(v,0,v.size()-1, stats);


    stats.depth_recursion_stack = depth;
    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";
}// function myquicksort_2recursion_medianOf3

int QuickSort2(std::vector<int> &v, int min,int max, SortStats &stats){
    stats.recursive_calls += 1;
    int depth;
    if(min<max){
        int p = partition(v,min,max);
        int a = QuickSort2(v,min,p-1,stats);
        int b = QuickSort2(v,p+1,max,stats);

        if(a>=b)
            depth = a + 1;
        else{
            depth = b + 1;
        }
        return depth;
    }
    return 1;
}

int partition(std::vector<int> &v, int esq, int dir){
    int median = median3(v[esq], v[(esq + dir)/2] , v[dir]);
    int auxi = v[esq];
    v[esq] = median;
    if (median == v[dir])
        v[dir] = auxi;
    else if (median == v[(esq + dir)/2])
        v[(esq + dir)/2] = auxi;
    int pivo = v[esq];
    int l = esq +1;
    int r = dir;
    while(true){
        while(l<dir && v[l] < pivo)
            l++;
        while(r>esq && v[r] >= pivo)
            r--;
        if(l>=r) break;
        int aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[esq] = v[r];
    v[r] = pivo;
    return r; 
}

int median3(int first, int half, int last){
    if ((first <= half) && (half <= last)) return half;  // a b c
    if ((first <= last) && (last <= half)) return last;  // a c b
    if ((half <= first) && (first <= last)) return first;  // b a c
    if ((half <= last) && (last <= first)) return last;  // b c a
    if ((last <= first) && (first <= last)) return first;
    return half;
}

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;

    QuickSort1(v, 0,v.size()-1,stats);
    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";
} // function myquicksort_1recursion_medianOf3

void QuickSort1(std::vector<int> &v, int min, int max, SortStats &stats ){
    stats.recursive_calls+=1;
    stats.custom1+=1;

    if( stats.custom1> stats.depth_recursion_stack)
    stats.depth_recursion_stack = stats.custom1;

    while(min < max){
        int p = partition(v,min,max);
        if(p-min < max-p){
            QuickSort1(v, min,p-1,stats);
            min = p+1;
        }
        else{
            QuickSort1(v, p+1,max,stats);
            max = p-1;
        }
    }

    stats.custom1-=1;
}

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version

void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;

    QuickSortFixed(v, 0, v.size()-1,stats);
    // std::cout<<"profundidade "<<stats.depth_recursion_stack<<"\n";
    // std::cout<<"chamadas "<<stats.recursive_calls<<"\n";

} // myquicksort_fixedPivot

void QuickSortFixed(std::vector<int> &v, int min, int max, SortStats &stats ){
    stats.recursive_calls += 1;
    stats.custom1 += 1;

    if( stats.custom1> stats.depth_recursion_stack)
        stats.depth_recursion_stack = stats.custom1;

    while(min < max){
        int p = partitionFixed(v,min,max);
        if(p-min < max-p){
            QuickSort1(v, min,p-1,stats);
            min = p+1;
        }
        else{
            QuickSort1(v, p+1,max,stats);
            max = p-1;
        }
    }

    stats.custom1-=1;
}

int partitionFixed(std::vector<int> &v,int esq,int dir){
    int pivo = v[esq];
    int l = esq +1;
    int r = dir;
    while(true){
        while(l<dir && v[l] < pivo)
            l++;
        while(r>esq && v[r] >= pivo)
            r--;
        if(l>=r) break;
        int aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[esq] = v[r];
    v[r] = pivo;
    return r; 
}

