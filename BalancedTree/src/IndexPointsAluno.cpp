
#include <IndexPointsAluno.h>
#include <iostream>

/// returns the number of elements in the index
long IndexPointsAluno::size() {
  return _map.numsize; 
}

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { 
  insert(key, idx); 
}



void IndexPointsAluno::find(std::vector<long> &res, double first, double last){
    
    
  // it is float, so it is not possible to compare with ==
  // the only thing that makes sense is too look for a range from
  // a min value to a max value. 
  // stl::multimap implements this using iterators 
  // you do not need to use iterators, but you need to fill the answer in O(k + logn)
  // where k is the number of elements in the range from first to last
  // in other words: NAO VALE FAZER INORDER COMPLETO E SELECIONAR O RANGE
  // PRECISA UM INORDER ESPERTO QUE ACHA O FIRST em O(log n) E CONTINUA ATE O LAST

  createRes(res, first, last, _map.raiz);

     
}//find



IndexPointsAluno::IndexPointsAluno(){
  _map.nulo = new node;
  _map.nulo->color = BLACK;
  _map.nulo->esq = nullptr;
  _map.nulo->dir = nullptr;
  _map.raiz = _map.nulo;
  _map.nulo->dir = _map.raiz;
  _map.raiz->pai = _map.nulo;
  _map.raiz->color = BLACK;
  _map.numsize = 0;
}

void IndexPointsAluno::createRes(std::vector<long> &res, double first, double last, node * x){
  if(x != _map.nulo){
    if(x->key > first){
      IndexPointsAluno::createRes(res,first,last,x->esq);
    }
    if(x->key > first and x->key < last){
      res.push_back(x->index);
    }
    if(x->key < last){
      IndexPointsAluno::createRes(res, first, last, x->dir);
    }
  }
}


void IndexPointsAluno::insert(double key, long index){
  node *z = new node;
  node * y = _map.nulo;
  node * x = _map.raiz;
  z->key = key;
  z->index = index;
  while( x != _map.nulo){
    y = x;
    if(key < x->key)
      x = x->esq;
    else x = x->dir;
  }
  z->pai = y;
  if(y == _map.nulo){
    _map.raiz = z;
    z->color = BLACK;
  }
  else if(key < y->key)
    y->esq = z;
  else y->dir = z;
  z->esq = _map.nulo;
  z->dir = _map.nulo;
  if(z != _map.raiz)
    z->color = RED;
  _map.numsize += 1;
  InsertFix(z);
}

void IndexPointsAluno::InsertFix(node *z){  
  while(z->pai->color == RED){
    if(z->pai == z->pai->pai->esq){
      node * y = z->pai->pai->dir;
      if(y->color == RED){
        z->pai->color = BLACK;
        y->color = BLACK;
        z->pai->pai->color = RED;
        z = z->pai->pai;
      }
      else{ 
        if(z == z->pai->dir){
          z = z->pai;
          leftRotate(z);
          }
        z->pai->color = BLACK;
        z->pai->pai->color = RED;
        rightRotate(z->pai->pai);
      }
    }
    else{
      node * y = z->pai->pai->esq;
      if(y->color == RED){
        z->pai->color = BLACK;
        y->color = BLACK;
        z->pai->pai->color = RED;
        z = z->pai->pai;
      }
      else {
        if(z == z->pai->esq){
        z = z->pai;
        rightRotate(z);
        }
        z->pai->color = BLACK;
        z->pai->pai->color = RED;
        leftRotate(z->pai->pai);
      }
    }
  }
  _map.raiz->color = BLACK;
}

void IndexPointsAluno::leftRotate(node *x){
  node * y = x->dir;
  x->dir = y->esq;
  if (y->esq != _map.nulo)
    y->esq->pai = x;
  y->pai = x->pai;
  //se der errado trocar o _map.nulo ali de baixo para nullptr
  if (x->pai == _map.nulo)
    _map.raiz = y;
  else if (x == x->pai->esq)
    x->pai->esq = y;
  else
    x->pai->dir = y;
  y->esq = x;
  x->pai = y;
}

void IndexPointsAluno::rightRotate(node *x){
    node * y = x->esq;
    x->esq = y->dir;
    if (y->dir != _map.nulo)
      y->dir->pai = x;
    y->pai = x->pai;
    if (x->pai == _map.nulo)
      _map.raiz = y;
    else if (x == x->pai->dir)
      x->pai->dir = y;
    else
      x->pai->esq = y;
    y->dir = x;
    x->pai = y;
  }

