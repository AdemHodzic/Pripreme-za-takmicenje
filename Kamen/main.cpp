/**
    Zadatak: KAMEN
    Velikoj većini ljubitelja igara veoma je poznata igra Boulder Dash u kojoj junak trči kroz
    podzemne hodnike sakupljajući dijamante i izbjegavajući kamenje. Vaš zadatak je da napišete
    program koji simulira dio te igre – padanje kamenja.
    Ploča za igru je kvadratna mreža koja se sastoji od R redaka označenih brojevima od 1 do R
    odozgo prema dole te S stupaca označenih brojevima od 1 do S s lijeva na desno. Svaki jedinični
    kvadratić u mreži je ili prazan (označen znakom ‘.’), ili na njemu može biti prepreka (označena
    znakom ‘#’) ili kamen (označen malim slovom ‘o’). Na početku igre ne postoji niti jedan kamen
    na ploči.
    U svakom koraku se u neki stupac ubacuje tačno jedan kamen koji se najprije pojavi u prvom
    retku tog stupca te dalje pada dole kroz ploču prema sljedećim pravilima:
    - Ako je polje neposredno ispod kamena prazno, onda kamen pada na to prazno polje.
    - Ako se na polju neposredno ispod kamena nalazi prepreka ili se kamen nalazi u najdonjem
    redu ploče, onda kamen ostaje na mjestu te je korak gotov.
    - Ako se neposredno ispod kamena nalazi drugi kamen, tada se događa sljedeće:
    o Ako su polja neposredno desno i dolje-desno od kamena koji pada prazna (te unutar
    ploče za igru), tada kamen propada na polje dolje-desno
    o Inače, ako su polja neposredno lijevo i dolje-lijevo od kamena koji pada prazna (te
    unutar ploče za igru), tada kamen propada na polje dolje-lijevo
    o Inače, kamen ostaje na mjestu te je korak gotov.
    Slika 1: Primjer padanja kamena kroz ploču
    Na primjer, ako je trenutno stanje ploče kao na slici gore lijevo te kamen ubacujemo u četvrti
    stupac onda će on padati putanjom naznačenom brojevima na slici desno.
    Napišite program koji će na temelju početnog izgleda ploče te zadanog niza koraka gdje je
    svaki korak ubacivanje kamena u jedan stupac, odrediti konačni izgled ploče nakon što je svo
    kamenje ubačeno.
    Ulazni podaci
    U prvom redu nalaze se dva prirodna broja R i S (1 ≤ R, S ≤ 100), broj redaka i stupaca mreže
    kvadratića. U svakom od sljedećih R redova nalazi se niz od točno S znakova ‘.’ (tačka), ‘#’ –
    izgled ploče na početku igre.
    5. Kantonalno takmičenje iz Informatike
    15
    U sljedećem redu nalazi se prirodni broj K (1 ≤ K ≤ 100), broj kamenja koje ubacujemo u ploču.
    U sljedećem redu nalazi se K prirodnih brojeva između 1 i S (uključivo) odvojenih jednim
    razmakom, redni brojevi stupaca u koje (u zadanom poretku) treba ubaciti kamenje.
    Ulaz će biti takav da će uvijek u ploči biti mjesta za kamen koji se ubacuje. Drugim riječima,
    ako u nekom koraku treba ubaciti kamen u stupac A, tada će u tom trenutku prvi redak stupca
    A biti prazan.
    Izlazni podaci
    Potrebno je ispisati R redova, u svaki red točno S znakova - izgled ploče za igru nakon što je
    svo kamenje ubačeno.
    Ploča treba biti identična onoj s ulaza osim što na pozicijama na kojima se nalazi kamenje treba
    pisati malo slovo ‘o’.
    NAPOMENA
    U 30% test podataka će vrijediti da su svi retci u koje se ubacuje kamenje različiti.

**/

#include <iostream>

using namespace std;

bool is_prepreka(char[][] ploca, int xPos,int yPos, int br, int bk);
bool is_kamen(char[][] ploca, int xPos, int yPos, int br, int bk);

int main()
{
    //1. unos broj redova i kolona i broja kamena --
    //2. unos izgleda ploce  --
    //3. for petlja da poreda svaki kamen
    //4. while polje ispod je prazno poticija kamena y++
    //5. ako je ispod prepreka ili je doslo do kraja continue sa sljedecim kamenom
    //6. ako je ispod kamena drugi kamen i ako je ako je x++ i y++ slobodno stavi tu kamen
    //7. ako je ispiod kamena drugi kamen i ako je x-- i y-- slobodno stavi tu kamen
    //8. printaj krajniji izgled ploce

    int br, bk, kamenje;
    cin >> br >> bk >> kamenje;
    if(br < 1 || bk > 100 || kamenje < 1 || kamenje > 100){
        cout << "Pogresan unos\n";
        return 0;
    }
    char ploca[br][bk];
    int kamenovi[kamenje];
    for(int i = 0;i<br;i++){
        for(int j = 0;j<bk;j++){
            cin >> ploca[i][j];
        }
    }
    for(int i = 0;i<kamenje;i++){
        int temp;
        cin >> temp;
        if(temp <= 0){
            cout << "Pogresan unos " << endl;
            return 0;
        }
        kamenovi[i] = temp;
    }

    for(int i = 0; i < kamenje ; i++){
        bool tempBoolean = true;
        int xPos = 0;
        int yPos = kamenovi[i];
        while(tempBoolean){
            cout << "Send help \n"; // U slucaju infinite loopa
            if(is_kamen(kamenovi, xPos, yPos, br, bk)){
                //Ako je slobodno desno idi desno
                //Ako je slobodno lijevo idi lijevo
                //A ako nije nista slobodno onda tempBoolean = false


            }else if(is_prepreka(kamenovi, xPos, yPos, br, bk)){
                //Zaustavi
                tempBoolean=false;
            }else{
                //Onda je polje ispod prazno pa samo povecajemo yPos
            }
        }
        ploca[xPos][yPos] = 'o';
    }
    return 0;
}

bool is_prepreka(char[][] ploca, int xPos,int yPos, int br, int bk){
    if(yPos == br-1)
        return true;
    if(ploca[xPos][++yPos]=='#')
        return true;
    return false;
}

bool is_kamen(char[][] ploca, int xPos, int yPos, int br, int bk){
}
