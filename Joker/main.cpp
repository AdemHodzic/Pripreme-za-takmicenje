#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void solve(char dobitniBroj[], int igrac);

int main()
{
    //1. Unijeti kuglice i izracunati dobitni joker broj
    //2. Unijeti listice i njihove joker brojeve
    //3. pozvati funkciju da isprinta dobitke
    char kuglice[6];
    for(int i = 0;i<6;i++){
        int temp;
        cin >> temp;
        kuglice[i] = (char)(temp%10);
    }
    int prviIgrac, drugiIgrac, treciIgrac;
    cin >> prviIgrac >> drugiIgrac  >> treciIgrac;
    solve(kuglice, prviIgrac);
    solve(kuglice, drugiIgrac);
    solve(kuglice, treciIgrac);
    return 0;
}

void solve(char dobitniBroj[], int igrac){
    //1. inicijalizirati counter i array stringova mogucih rijesenja
    //2. preci preko svakog broja i ako su razliciti break iz petlje
    //3. isprintati rijesenje
    int counter = 0;
    string dobitci[6] =  {"Nedobitan","V. vrsta","IV. vrsta","III. vrsta","II. vrsta","I.vrsta"};
    string trenutni;
    char igracArr[6];
    for(int i = 5;i>=0;i--){
        igracArr[i]= igrac%10;
        igrac/=10;
    }
    int velicina = 5;
    while(true){
        trenutni = dobitci[counter];
        if(velicina == -1 || dobitniBroj[velicina] != igracArr[velicina])
            break;
        else if(velicina =< 4)
            counter++;
        velicina++;
    }
    cout<<dobitci[counter]<<endl;

}
