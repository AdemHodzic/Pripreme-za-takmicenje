#include <iostream>

using namespace std;

/**
 *  Preferencijalno glasaanje je sistem u kojem građani, osim mogućnosti glasanja za određenu
    izbornu listu, mogu i zaokružiti određenog kandidata na toj listi. Ovaj sistem se koristi u Bosni
    i Hercegovini prilikom parlamentarnih izbora kao i izbore za Europski parlament. Za potrebe
    ovog zadatka, razmatramo pojednostavljenu verziju jednog aspekta sistema.
    Izborna lista se sastoji od n kandidata označenih redom brojevima od 1 do n, a svaki od
    kandidata je na izborima dobio određen broj glasova. Ukupan broj glasova liste je jednak sumi
    glasova svih pojedinih kandidata. Kažemo da je kandidat preferiran ako je dobio najmanje 10%
    od ukupnog broja glasova liste.
    Pretpostavimo da tačno m kandidata s liste ulaze u parlament, oni se jedan po jedan određuju
    dok se ne popuni m mjesta prema sljedećim pravilima:
    • U parlament ulaze najprije preferirani kandidati i to redoslijedom od onih s više glasova
    prema onima s manje. Ukoliko dva ili više preferiranih kandidata ima jednak broj glasova, u
    parlament najprije ulazi onaj od njih koji je označen najmanjim brojem.
    • Kada nema više preferiranih kandidata, u parlament ulaze ostali kandidati s liste
    redoslijedom od onih označenih manjim brojem prema onima označenih većim brojem.
    Zadana je izborna lista zajedno s brojem glasova za pojedine kandidate te ukupnim brojem
    parlamentarnih mjesta koje je lista osvojila. Odredite koji kandidati ulaze u parlament.
    Ulazni podaci
    U prvom redu nalaze se prirodni brojevi n i m (n ≤ 20, m ≤ n) — broj kandidata na listi te broj
    parlamentarnih mjesta koje je lista osvojila. U i-tom od sljedećih n redova nalazi se cijeli broj
    g (0 ≤ gi ≤ 106
    ) — broj glasova koje je osvojio kandidat i.
    Izlazni podaci
    Ispišite niz od tačno n znakova bez razmaka — i-ti znak treba biti “1” ukoliko je kandidat i
    izabran u parlament odnosno “0” ako nije.
 **/

bool hasStepOne(int arr[],int post, int sizeArr);
int findMaximum(int arr[], int sizeArr);

int main()
{
    //1. Unos broj mjesta i broja kandidata
    //2. Unos broja glasova, init finalnog arraya
    //3. racunanje sume i psot
    //4. Pronadjemo najveci broj glasova i ako je veci od postotka
    //izbacimo ga iz glasova i stavimo njegova index finalnog array nma jedan
    //5. Ako je ostalo glasova svaki sljedeci u arrayu glasova ulazi
    int bk,bm,suma=0,post=0;
    cin>>bk>>bm;
    int glasovi[bk], finalArr[bk];
    for(int i = 0;i<bk;i++){
        cin>>glasovi[i];
        finalArr[i] = 0;
        suma += glasovi[i];
    }
    post=suma/10;
    while(hasStepOne(glasovi,post, bk) && bm!=0){
        int index = findMaximum(glasovi, bk);
        finalArr[index] = 1;
        glasovi[index] = -1;
        bm--;
        cout<<"broj mjersta " << bm << endl;
    }
    cout<<"Ste one finished " << endl;
    for(int i = 0;i<bk;i++){
        cout<<glasovi[i];
    }
    cout<<endl;
    if(bm>0){
        int counter = 0;
        while(bm>0){
            if(glasovi[counter]>=0){
                finalArr[counter] = 1;
                bm--;
                for(int i = 0;i<bk;i++){
                    cout<<glasovi[i];
                }
                cout<<endl<<"broj mjersta" << bm << endl;
            }
            counter++;
        }
    }
    cout<<endl;
    for(int i=0;i<bk;i++){
        cout<<finalArr[i];
    }
    return 0;
}

bool hasStepOne(int arr[],int post, int sizeArr){
    bool returnValue = false;
    for(int i = 0; i < sizeArr; i++){
        if(arr[i]>=post){
            returnValue = true;
            break;
        }
    }
    return returnValue;
}

int findMaximum(int arr[], int sizeArr){
    int index = 0;
    int maximum = arr[0];
    for(int i = 1;i<sizeArr;i++){
        if(arr[i]>maximum){
            maximum = arr[i];
            index = i;
        }
    }
    return index;
}


