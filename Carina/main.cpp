#include <iostream>

using namespace std;

/*
    Pri ulasku u jednu daleku državu prtljagu će vam pregledati tri carinika, svaki u svojoj kućici. U
    kućici A, carinik će vam pregledati ručnu prtljagu. Kada pregled završi, idete dalje u kućicu B
    gdje će vam drugi carinik pregledati kofer. Kada i taj pregled završi, idete dalje u kućicu C gdje
    treći carinik na temelju procjena prvih dvaju carinika određuje koliko morate platiti carinu.
    Za prolazak kroz carinu čeka N ljudi i za svakog smo procijenili koliko će vremena provesti u
    kojoj kućici. Vrijeme prelaska iz jedne u drugu kućicu je zanemarivo (ako nema čekanja), ali
    može se stvoriti gužva ispred bilo koje kućice jer niko ne može u nju ući dok prethodna osoba
    u redu ne završi s pregledom. Kroz svaku kućicu se mora proći pa i onda kada je vrijeme čekanja
    procijenjeno na nula sekundi.
    Tvoj je zadatak, znajući koliko će svaki od N ljudi provesti kod svakog carinika, odrediti ukupno
    vrijeme potrebno da svi prođu carinu (tj. da posljednji čovjek izađe iz posljednje kućice).
    Primjer. U prvom test primjeru niže, na prolazak kroz carinu čekaju tri osobe, a treću kućicu
    možemo zanemariti jer će svi u njoj provesti 0 minuta. Prolazak teče ovako:
    Prvi putnik u redu će provesti 2 minute u kućici A i odmah potom 4 minute u kućici B.
    Iza njega je drugi putnik, koji očito mora čekati 2 minute da uđe u kućicu A. On potom u
    kućici A provodi svoju 1 minutu, nakon čega ne može odmah ući u kućicu B, nego mora čekati
    još 3 minute da prvi putnik izađe iz kućice B i tek tada u njoj provesti svojih 7 minuta, nakon
    čega iz nje izlazi (ukupno 13 minuta od početka).
    Treći putnik u redu će ući u kućicu A čim drugi putnika iz nje izađe (3 minute od početka).
    Nakon što provede svoju 1 minutu u kućici A, morat će (sa drugim putnikom) čekati ispred
    kućice B dok iz nje ne izađe najprije prvi, a potom i drugi putnik (13 minuta od početka).
    Konačno, treći putnik izlazi iz kućice B nakon što u njoj provede 7 minuta (što je ukupno 20
    minuta od početka).

    Ulazni podaci
    U prvom retku nalazi se prirodan broj N (1 ≤ N ≤ 10), broj ljudi u redu.
    U svakom od sljedećih N redaka nalaze se po tri cijela broja a, b i c (0 ≤ a, b, c ≤ 15), vrijeme
    provedeno u kućicama A, B i C (redom), po redcima za osobe od prve do posljednje u redu.

    Izlazni podaci
    U jedini redak ispiši traženo ukupno vrijeme.
*/

int maxInArray(int arr[], int velicina);

int main()
{
    cout<<"Unesite broj putnika:\n";
    int brojPutnika,ukupnoVrijeme=0;
    cin>>brojPutnika;
    int matrica[brojPutnika][3];
    for(int i = 0;i<brojPutnika;i++){
        for(int k = 0;k<3;k++){
            cin>>matrica[i][k];
        }
    }
    ukupnoVrijeme+=matrica[0][0];
    ukupnoVrijeme+=matrica[brojPutnika-1][2];

    for(int i = 0;i<brojPutnika;i++){
        if(i==0){
            int arr[2] = {matrica[i][1], matrica[i+1][0]};
            ukupnoVrijeme+= maxInArray(arr,2);
        }else if(i==brojPutnika-1){
            int arr[2] = {matrica[i][1],matrica[i-1][2]};
            ukupnoVrijeme+=maxInArray(arr,2);
        }else{
            int arr[3] = {matrica[i-1][2],matrica[i][1],matrica[i+1][0]};
            ukupnoVrijeme+=maxInArray(arr,3);
        }
    }
    cout<<ukupnoVrijeme<<endl;
    return 0;
}

int maxInArray(int arr[], int velicina){
    int maximum = arr[0];
    for(int i = 1; i<velicina;i++){
        if(arr[i]>maximum)
            maximum=arr[i];
    }
    return maximum;
}
