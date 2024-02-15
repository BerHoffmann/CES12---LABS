#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>
#include <iostream>

#define BLACK 0
#define RED 1


struct node{
    bool color;
    double key;
    long index;
    node *dir, *esq, *pai;
};


class IndexPointsAluno : public IndexPointsAbstract {


    public:

        struct RedBlack{
            node *raiz;
            node *nulo;
            long numsize;
        };

        IndexPointsAluno();        
        long size() ;
            
        void add (double key, long idx ) ;
        
        //look for a range of values
        void find(std::vector<long> &res, double first, double last) ;

        //node * findPos(float first);
        void insert(double key, long index);
        void leftRotate(node* x);
        void rightRotate(node* x);
        void InsertFix(node* z);
        void createRes(std::vector<long> &res, double first, double last, node*x);

        //void inOrderWalk(node*x);
        //void inOrderWalkInterval(node*first,node*last);
        
        
    private: 
        // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
        RedBlack _map;
        
};//class



#endif
