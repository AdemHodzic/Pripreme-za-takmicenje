#include <iostream>
#include <fstream>

using namespace std;

bool is_prost(int n){
    if(n%2==0)
        return false;
    for(int i = 3;i*i<=n;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}

int arrSize(int broj){
    int counter = 0;
    for(int i = 2;i<broj;i++){
        if(is_prost(i))
            counter++;
    }
    return counter;
}



int main()
{
    ifstream input("ulaz.in");
    ofstream output("izlaz.out");

    int arraySize;
    input >> arraySize;
    int velicina = arrSize(arraySize);
    int prosti_brojevi[velicina];
    int index = 0;
    int broj = 2;
    while(index!=velicina-1){
        if(is_prost(broj)){
            prosti_brojevi[index]=broj;
            index++;
        }
        broj++;
    }
    int finalCounter=0;
    for(int i = 1;i<velicina;i++){
        int index=i-1;
        if(prosti_brojevi[i]-prosti_brojevi[index]==2)
            finalCounter++;
    }

    output << finalCounter;
    input.close();
    output.close();
    return 0;
}
