#include <iostream>
#include <vector>

#define INF 1000

// help function
template <typename T>
void print_vector(std::vector<T> &v){
    for(unsigned int i=0;i<v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


// really shitty approach with INF number
// but it is in the book
// p. 31 (PDF p. 52): INSERTION-SORT(A0
template <typename T>
void merge_sort(std::vector<T> &A, int p, int q, int r){
    int n1 = q-p;
    int n2 = r-q;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for(int i=0; i<n1; i++){
        L[i] = A[p+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = A[q+j];
    }

    // some big number
    L.push_back(INF);
    R.push_back(INF);

    int i=0, j=0;
    for(int k=p; k<r; k++){
        if(L[i] < R[j]) {
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

// p. 34 (PDF p. 55)
template <typename T>
void merge_sort(std::vector<T> &A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge_sort(A,p,q,r);
    }
}

int main()
{
    std::vector<int> a {2,4,5,7,1,2,3,6};
    merge_sort(a,0,8);
    print_vector(a);

    return 0;
}

