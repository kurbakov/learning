#include <iostream>
#include <vector>

struct Matrix{
    int col;
    int row;
    std::vector<int> data;

    // Matrix constructor
    Matrix(int c, int r, std::vector<int> d){

        if(c*r != int(d.size())){
            throw std::invalid_argument("wrong arguments");
        }

        col = c;
        row = r;
        data = d;
    }
};

void print_matrix(Matrix &A){

    for(int i=0; i<A.row; i++){
        for(int j=0; j<A.col; j++){
            std::cout << A.data[i*A.col+j] << " ";
        }
        std::cout << std::endl;
    }

}

// Strassen’s algorithm for matrix multiplication
// p.75 (PDF p. 96)
Matrix SQUARE_MATRIX_MULTIPLY(Matrix &A, Matrix &B){
    if(A.col != B.row)
        throw std::invalid_argument("wrong arguments");

    int res_row = A.row;
    int res_col = B.col;

    int n = A.col;

    std::vector<int> res_data(res_col*res_row);

    for(int i=0;i<res_row; i++){
        for (int j = 0; j < res_col; j++) {
            int c_i_j = 0;

            for (int k = 0; k < n; k++) {
                int a_i_k = A.data[i*A.row + k];
                int b_k_j = B.data[k*B.row + j];
                c_i_j = c_i_j + a_i_k*b_k_j;
            }

            res_data[i*res_row + j] = c_i_j;
        }
    }

    Matrix res(res_col,res_row,res_data);
    return res;
}

int main()
{
    Matrix m1(2,2,{1,2,3,4});
    Matrix m2(2,2,{1,2,3,4});

    Matrix m = SQUARE_MATRIX_MULTIPLY(m1,m2);
    print_matrix(m);
    return 0;
}

