#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
const int myarrsize=10000;
int myarr[myarrsize];

int main(){
    int startarr=10;
    std::iota(myarr, myarr+myarrsize, startarr);
    //
    int *end=myarr+myarrsize;
    std::ostream_iterator<int> output(std::cout<<" ");
    std::copy(myarr,end,output);
}
