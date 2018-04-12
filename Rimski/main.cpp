#include <iostream>
#include <string>

using namespace std;

string rimskiNum[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int arapskiNum[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

int arapski(string rimski);
string rimski(int arapski);

int main()
{
    //1. Unijeti dva rimska broja
    //2. Pretvoriti ih u arapske brojeve
    //3. pretvoriti zbir u rimski broj
    string prviBroj, drugiBroj;
    int zbir;
    cin >> prviBroj >> drugiBroj;
    zbir = arapski(prviBroj) + arapski(drugiBroj);
    cout << rimski(zbir);
    return 0;
}

int arapski(string rimski){
    int counter = 0;
    int solution = 0;
    for(int i = 0;i<13;i++){
        while(rimski.substr(counter,rimskiNum[i].length())==rimskiNum[i]){
            solution+=arapskiNum[i];
            counter+=rimskiNum[i].length();
        }
    }
    return solution;
}

string rimski(int arapski){
    string solution = "";
    for(int i = 0;i<13;i++){
        while(arapski>=arapskiNum[i]){
            arapski-=arapskiNum[i];
            solution += rimskiNum[i];
        }
    }
    return solution;
}
