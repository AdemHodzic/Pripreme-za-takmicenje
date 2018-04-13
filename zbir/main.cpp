#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("zbir.in");
    ofstream output("zbir.out");

    int number;
    while(input >> number){
    int counter=0, i;
    if(number%2==0)
        i=2;
    else
        i=1;

    for(int k = i;k<number;k+=2){
        ++counter;
    }

    output << counter << endl;
    }
    input.close();
    output.close();

    return 0;
}
