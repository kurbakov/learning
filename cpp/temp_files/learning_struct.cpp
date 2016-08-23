#include "iostream"
//=====================================================================
// define new data types

struct Matrix {
    int n_col;
    int n_row;
    int data[128];
};

struct Vector {
    int size;
    int data[128];
    bool trans;
};

//=====================================================================
// create matrix/vector

Matrix* matrix(int n_col, int n_row, int data[]) {
    Matrix *res = new Matrix;
    res->n_col = n_col;
    res->n_row = n_row;
    for (int i = 0; i < n_col * n_row; i++) {
        res->data[i] = data[i];
    }

    return res;
}

Vector* vector(int size, int data[]){
    Vector* vec = new Vector;
    vec->size = size;
    for(int i=0; i<size; i++){
        vec->data[i]=data[i];
    }
    vec->trans = false;

    return vec;
}

//=====================================================================
// assign new values to matrix/vector

void assign(int i, int value, Vector* v){
    v->data[i] = value;
}

void assign(int col, int row, int value, Matrix* m){
    m->data[row+col+col] = value;
}

//=====================================================================
// print matrix/vector

void print(Vector* v){
    if(v->trans == true){
        for(int i=0; i<v->size; i++){
            std::cout<< v->data[i] << " ";
        }
        std::cout << std::endl;
    }
    else{
        for(int i=0; i<v->size; i++){
            std::cout<< v->data[i] << std::endl;
        }
    }
}

void print(Matrix* m){
    for (int row=0; row<m->n_row; row++){
        for (int col=0; col<m->n_col; col++){
            std::cout << m->data[row*m->n_row+col]<< " ";

        }
        std::cout<<std::endl;
    }
}

//=====================================================================
// sum 2 matrix/vector with the same size

Matrix* sum(Matrix* a, Matrix* b) {
    if(a->n_col != b->n_col | a->n_row != b->n_row){
        return nullptr;
    }
    Matrix *res = new Matrix;
    res->n_col = a->n_col;
    res->n_row = a->n_row;
    for (int i = 0; i < a->n_row * a->n_col; i++){
        res->data[i] = a->data[i]+b->data[i];
    }
    return res;
}

Vector* sum(Vector* a, Vector* b){
    Vector* v = new Vector;
    v->size=a->size;
    v->trans=a->trans;

    for (int i=0; i<a->size; i++){
        v->data[i] = a->data[i]+b->data[i];
    }
    return v;
}

//=====================================================================
// transponse matrix/vector

void Mt(Vector *v){
    if(v->trans == false)
        v->trans = true;
    else{
        v->trans = false;
    }
}

void swap(int* x, int* y){
    int t;
    t = *y;
    *y = *x;
    *x = t;
}

void t(Matrix* m){
    for (int row = 0; row<m->n_row; row++){
        for (int col = 0; col<m->n_col; col++){
            swap(&m->data[0], &m->data[0]);
        }
    }
}

//=====================================================================

int main(){

    int data[] = {0,1,2,3};


    Matrix* m1 = matrix(2,2,data);
    Matrix* m2 = matrix(2,2,data);

    Matrix* m = sum(m1, m2);

    print(m);

    delete m;

    return 0;
}
