#include <iostream>

using namespace std;

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
