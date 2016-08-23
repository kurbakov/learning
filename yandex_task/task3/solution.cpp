/*
I would suggest for to use Kahan summation algorithm.
We have o(1) memory complexity and O(n) time complexity, 
where n is the number of elements that we need to add.

Algorithm described here:
https://en.wikipedia.org/wiki/Kahan_summation_algorithm

I created the small class to compute the summ and compensation.
In main function the algorithm can be called, and in the for loop
call the function kahan_sum().
*/

class KahanSum
{
protected:
    double sum;
    double comp;
    
public:

    KahanSum()
    {
        sum = 0.0;
        comp = 0.0;
    }

    ~KahanSum()
    {
        sum = 0.0;
        comp = 0.0;
    }

    void kahan_sum(double v)
    {
        double y = v - comp;
        double t = sum + y;
        comp = (t - sum) - y;
        sum = t;
    }
    
    double get_sum(){ return sum;}
    double get_comp(){ return comp;}
};


int main(int argc, char* argv[])
{
    KahanSum ks = KahanSum();
    std::vector<double> vt;
    /*
    vt.push_back(some very small number);
    vt.push_back(some very small number);
    vt.push_back(some very small number);
    ... */

    for (std::vector<double>::iterator it = vt.begin() ; it != vt.end(); ++it)
    {
        ks.kahan_sum(*it);
    }
    
    double kahan_sum_res = ks.get_sum();
    double kahan_comp_res = ks.get_comp();
    
    ks.~KahanSum();
    return 0;
}

/*
PS: 
    Algorithms that you provided in the task are described in the following article:
    https://people.eecs.berkeley.edu/~demmel/AccurateSummation.pdf
    (Algorithm 1, page 3; Algorithm 2, page 5)
    For the algorithm comparision see page 11.
    
    I wanted to add, based on the need, more efficient algorithms can be implemented with the lower complexity.
*/

/*
PS2:
    there is also a lot in internet about implementation of the python approach:
    http://code.activestate.com/recipes/393090/
    
    It is easy to write the code from python to CPP, but in the python case we have the 
    time complexity of O(n^2) what significantly worse than the approach in the example and
    the Kahan summation algorithm.
*/
