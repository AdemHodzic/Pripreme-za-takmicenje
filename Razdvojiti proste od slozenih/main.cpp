#include <iostream>
#include <fstream>
using namespace std;

bool is_prost(int number);

int main()
{
    //1. unijeti brojeve
    //2. satviti brojeve u niz
    //3. stavti u drugi nize proste brojeve
    //4. staviti u niz ostale brojeve po redoslijedu

    ifstream input("ulaz.in");
    ofstream output("izlaz.out");

    int velicina;
    input >> velicina;
    int niz[velicina];
    int counter = 0;
    while(input >> niz[counter]){
        counter++;
    }
    int noviNiz[velicina];
    int index = 0;
    for(int i = 0;i<velicina;i++){
        if(is_prost(niz[i])){
            noviNiz[index] = niz[i];
            index++;
        }
    }
    for(int i = 0;i<velicina;i++){
        if(!is_prost(niz[i])){
            noviNiz[index] = niz[i];
            index++;
        }
    }
    for(int i = 0;i<velicina;i++){
        output << noviNiz[i] << endl;
    }

    input.close();
    output.close();
    return 0;
}


bool is_prost(int number){
    if(number%2==0)
        return false;
    for(int i = 3;i*i<=number;i+=2){
        if(number%i==0)
            return false;
    }
    return true;
}
