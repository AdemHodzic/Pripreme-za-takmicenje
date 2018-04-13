#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int prosti_brojevi[2100];

bool is_prost(int number){
    if(number%2==0)
        return false;
    for(int i = 3;i*i<=number;i+=2){
        if(number%i==0)
            return false;
    }
    return true;
}



int main()
{
    //1. Unos N broja za velicinu nizova
    //2. Kreiranje niza za ki brojeve za prvog igraca
    //3. Kreiranje niza za mi brojeve za prvog igraca
    //4. Ponavljanje 2. i 3. koraka za drugog igraca
    //5. Populacija niza prostih brojeva opd 2 do 18000
    //6. Kreiranje int varijabla za bodove prvog i drugog igraca
    //7. Evaluacija bodova
    //8. Printanje rijesenja
    //9. Close-anje fstream-ova
    int index=0;
    for(int i = 2;i<18000;i++){
        if(is_prost(i)){
            prosti_brojevi[index]=i;
            index++;
        }
    }
    ifstream input("ulaz.in");
    ofstream output("izlaz.out");

    int noe;
    input >> noe;
    int prviArr[noe], prviArrProst[noe], drugiArr[noe], drugiArrProst[noe];
    int prviBodovi = 0,drugiBodovi=0;

    for(int i = 0;i<noe;i++){
        input >> prviArr[i] >> prviArrProst[i];
    }

    for(int i = 0;i<noe;i++){
        input >> drugiArr[i] >> drugiArrProst[i];
    }

    for(int i = 0;i<noe;i++){
        int index = prviArr[i]-1;
        int pokusaj = prviArrProst[i];
        if(prosti_brojevi[index]==pokusaj)
            prviBodovi++;
    }

    for(int i = 0;i<noe;i++){
        int index = drugiArr[i]-1;
        int pokusaj = drugiArrProst[i];
        if(prosti_brojevi[index]==pokusaj)
            drugiBodovi++;
    }

    string pobjednik;
    if(prviBodovi > drugiBodovi)
        pobjednik = "Prvi Igrac";
    else if(prviBodovi < drugiBodovi)
        pobjednik = "Drugi Dgrac";
    else
        pobjednik = "nerijeseno";
    output << pobjednik;

    input.close();
    output.close();

    return 0;
}
