
/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/genomic_range_query/
 *
 * */

// my solution with time issues:
#include <iostream>
#include <vector>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q){

    std::vector<int> res;
    std::vector<int> temp;

    for(char& c : S){
        switch(c){
            case 'A': temp.push_back(1); break;
            case 'C': temp.push_back(2); break;
            case 'G': temp.push_back(3); break;
            case 'T': temp.push_back(4); break;
        }
    }

    for(unsigned int i = 0; i<P.size(); i++)
    {
        int min = 5;
        
        for(int j = P[i]; j<= Q[i]; j++){
            if(min>temp[j])
                min = temp;
        }
        res.push_back(min);
    }

    return res;
}

int main(){
    std::string s="CAGCCTA";
    std::vector<int> p;
    p.push_back(2);
    p.push_back(5);
    p.push_back(0);

    std::vector<int> q;
    q.push_back(4);
    q.push_back(5);
    q.push_back(6);

    std::vector<int> res = solution(s,p,q);
    print_vector(res);

    return 0;
}


//=========================================================
// from internet with 100% results

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

    vector<vector<int> > chs(S.size()+1,vector<int>(4,0));
    
    for(int i=0; i<S.size(); i++){
        for(int j=0; j<4; j++)
            chs[i+1][j] = chs[i][j];
        
        switch(S[i]){
            case 'A': chs[i+1][0]=chs[i][0]+1; break;
            case 'C': chs[i+1][1]=chs[i][1]+1; break;
            case 'G': chs[i+1][2]=chs[i][2]+1; break;
            case 'T': chs[i+1][3]=chs[i][3]+1; break;
            default: break;
        }
    }
    vector<int> res;
    for(int i =0; i<P.size(); i++){
           int j;
           for( j=0; j<4; j++){
                if(chs[Q[i]+1][j]-chs[P[i]][j]!=0)
                    break;
           }
           res.push_back(j+1);
    }
    return res;
}
