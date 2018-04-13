#include <iostream>

using namespace std;

bool contains(int niz[], int broj, int size){
    for(int i = 0;i<size;i++){
        if(niz[i]==broj)
            return true;
    }
    return false;
}

int main()
{
    //1. Unijeti broj clanova nizeð
    //2. Unijeti clanove niza
    //3. Napraviti unikatni niz
    //4. Za svaki clan povecati counter u nizu
    int broj;
    cin >> broj;
    int niz[broj];
    int counter = 0;
    for(int i = 0;i<broj;i++){
        cin >> niz[i];
        int vel = i+1;
        if(!(contains( niz, niz[i], vel)))
            counter++;
    }
    int unique[counter];
    int temp = 0;
    for(int i = 0;i<counter;i++){
        if(!(contains(unique,niz[i],counter))){
            unique[temp] = niz[i];
            temp++;
        }
    }
    int brojaci[counter];
    for(int i = 0;i<counter;i++){
        for(int j = 0;j<broj;j++){
            if(niz[j]==unique[i])
                brojaci[i]++;
        }
    }
    for(int i = 0;i<counter;i++){
        cout<<unique[i]<<" "<<brojaci[i]<<endl;
    }

    return 0;
}
