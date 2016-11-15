// The file of some tests with operator overloading
// for more info visit: http://www.learncpp.com/#Chapter0

#include "iostream"
#include "vector"

class Data{
private:
    int data;

public:
    Data(int i){ this->data = i; }
    Data(){ this->data = 0; }

    void print(){ std::cout << data << std::endl; }

    /* Arithmetic operators */
    friend Data operator+(const Data&, const Data&);
    friend Data operator-(const Data&, const Data&);
    friend Data operator/(const Data&, const Data&);
    friend Data operator%(const Data&, const Data&);
    friend Data operator*(const Data&, const Data&);

    /* incremental and decremental */
    Data& operator++();
    Data& operator--();

    /* comparison operators */
    friend bool operator >  (const Data&, const Data&);
    friend bool operator <= (const Data&, const Data&);
    friend bool operator <  (const Data&, const Data&);
    friend bool operator >= (const Data&, const Data&);
    friend bool operator == (const Data&, const Data&);
    friend bool operator != (const Data&, const Data&);

    /* I/O operators */
    friend std::ostream& operator<< (std::ostream&, const Data&);
    friend std::istream& operator>> (std::istream&, Data&);

    /* assignment operator */
    Data& operator= (const Data&);

    /* unary operator */
    Data operator+() const;
    Data operator-() const;
    bool operator!() const;
};

Data operator+(const Data& d1, const Data& d2) {
    Data res(d1.data+d2.data);
    return res;
}

Data operator-(const Data& d1, const Data& d2) {
    Data res(d1.data-d2.data);
    return res;
}

Data operator/(const Data& d1, const Data& d2) {
    Data res(d1.data/d2.data);
    return res;
}

Data operator%(const Data& d1, const Data& d2) {
    Data res(d1.data%d2.data);
    return res;
}

Data operator*(const Data& d1, const Data& d2) {
    Data res(d1.data*d2.data);
    return res;
}

Data& Data::operator++() {
    data = data+1;
    return *this;
}

Data& Data::operator--() {
    data = data-1;
    return *this;
}

bool operator>(const Data& d1, const Data& d2) {
    return d1.data > d2.data;
}

bool operator<(const Data& d1, const Data& d2) {
    return d1.data < d2.data;
}

bool operator>=(const Data& d1, const Data& d2) {
    return d1.data >= d2.data;
}

bool operator<=(const Data& d1, const Data& d2) {
    return d1.data <= d2.data;
}

bool operator==(const Data& d1, const Data& d2) {
    return d1.data == d2.data;
}

bool operator!=(const Data& d1, const Data& d2) {
    return d1.data != d2.data;
}

std::ostream& operator<< (std::ostream& out, const Data& d) {
    out << "The value of the variable data is: " << d.data << std::endl;
    return out;
}

std::istream& operator>> (std::istream &in, Data &d){
    in >> d.data;
    return in;
}

Data& Data::operator=(const Data &d) {
    data = d.data;
    return *this;
}

Data Data::operator+() const {
    return Data(+data);
}

Data Data::operator-() const {
    return Data(-data);
}

bool Data::operator!() const {
    return data == 0;
}

/* ================================================== */

class Vector{
private:
    std::vector<int> vec;

public:
    Vector(int);

    int& operator()(const int);
    int& operator[](const int);
};

Vector::Vector(int k) {
    for(int i=0; i<k; i++)
        vec.push_back(i);
}

int& Vector::operator()(const int index) {
    return vec[index];
}

int& Vector::operator[](const int index) {
    return vec[index];
}

int main() {
    Data first(5);
    Data second(2);

    Data res_plus = first+second;
    res_plus.print();

    Data res_min = first-second;
    res_min.print();

    Data res_dev = first/second;
    res_dev.print();

    Data res_mod = first%second;
    res_mod.print();

    Data res_milt = first*second;
    res_milt.print();

    ++first;
    first.print();

    --first;
    first.print();

    std::cout<< first;

    Data d(100);
    Data copy_d;
    copy_d = d;
    std::cout<< copy_d;

    Data data;
    std::cout << !data << std::endl;
    data=first;
    std::cout << !data << std::endl;

    Vector v(10);

    std::cout << v(1) << std::endl;
    v(1) = 10;
    std::cout << v(1) << std::endl;

    return 0;
}

