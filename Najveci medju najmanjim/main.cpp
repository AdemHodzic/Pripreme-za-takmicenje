#include <iostream>

using namespace std;

int minimum(int arr[], int size);
int maximum(int arr[], int size);

int main()
{
    //1. unijeti velicinu matrice
    //2. Populirati matricu
    //3. U niv arr dodati najmanji broj u svakoj koloni
    //4. Isprinati najveci u pomenutom arrayu
    int br,bk;
    cin >> br >> bk;
    int matrica[br][bk];
    for(int i = 0;i<br;i++){
        for(int j = 0;j<bk;j++){
            cin >> matrica[i][j];
        }
    }
    int najmanji[bk];
    for(int i = 0;i<bk;i++){
        int temp[br];
        for(int j = 0;j<br;j++){
            temp[j] = matrica[i][j];
        }
        najmanji[i] = minimum(temp,br);
    }

    cout<< maximum(najmanji,bk);
    return 0;
}

int minimum(int arr[], int size){
    int mini = arr[0];
    for(int i = 1;i<size;i++){
        if(mini>arr[i])
            mini = arr[i];
    }
    return mini;
}

int maximum(int arr[], int size){
    int mini = arr[0];
    for(int i = 1;i<size;i++){
        if(mini<arr[i])
            mini = arr[i];
    }
    return mini;
}
