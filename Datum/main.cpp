#include <iostream>

using namespace std;

// Ovdje ide array sa brojem dana u svakome mjesecu
int dani[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void next(int dan, int mjesec, int godina);
void prev(int dan, int mjesec, int godina);
bool is_correct(int dan, int mjesec, int godina);

int main()
{
    //1. Unosimo broj datuma
    //2. Unosimo datume
    //3. Pozivamo funkciju next(dan,mjesec,godina)
    //4. Pozivamo funkciju prev(dan,mjesec,godina)

    int brojDatuma;
    cin >> brojDatuma;
    int datumi[brojDatuma][3];
    for(int i = 0;i<brojDatuma;i++){
        for(int j = 0;j<3;j++){
            cin>>datumi[i][j];
        }
    }
    for(int i = 0;i<brojDatuma;i++){
        if(datumi[i][2]%4==0){
            if(datumi[i][2]%100==0)
                if(datumi[i][2]%400==0)
                    dani[i]=29;
            else
                dani[i]=29;
        }else
            dani[1]=28;
        if(is_correct(datumi[i][0],datumi[i][1],datumi[i][2])){
            cout<<"Datum je "<<datumi[i][0]<<"."<<datumi[i][1]<<"."<<datumi[i][2]<<".";
            next(datumi[i][0],datumi[i][1],datumi[i][2]);
            prev(datumi[i][0],datumi[i][1],datumi[i][2]);
            cout<<endl;
        }else{
            cout<<"Datum: "<<datumi[i][0]<<"."<<datumi[i][1]<<"."<<datumi[i][2]<<" je neispravan.";
        }
    }
    return 0;
}

bool is_correct(int dan, int mjesec, int godina){
    if(dan <= dani[--mjesec])
        return true;
    return false;
}


void next(int dan, int mjesec, int godina){
    //1. provjeravamo da li je dan na kraju mjesec
    //TIP: mozemo varijablu mjesec korisiti kao index za dani samo sto pisemo --mjesec
    //2. Ako nije na kraju ispisujemo datum sa ++dan inace dan=1 ++mjesec
    if(dan==31 && mjesec==12)
        ++godina;
    if(dan==dani[--mjesec]){
        dan=1;
        mjesec+=2;
    }else
        dan++;
    cout<<"Sljedeci datum je "<<dan<<"."<<++mjesec<<"."<<godina<<".";
}

void prev(int dan, int mjesec, int godina){
    //1. provjeravamo da li je dan na pocetku mjeseca
    //2. ako jest ispisujemo dan = dani[--mjesec] --mjesec
    if(dan==1 && mjesec==1)
        --godina;
    if(dan==1){
        --mjesec;
        dan = dani[--mjesec];
    }else
        dan--;
    cout<<"Prethodni datum je "<<dan<<"."<<++mjesec<<"."<<godina<<".";
}
