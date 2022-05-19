#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>

using namespace std;

//1 HEAP SORT

void MAXHeapify(int tab[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if (l <= n && tab[l] > tab[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= n && tab[r] > tab[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;
        MAXHeapify(tab, n, largest);
    }
}

void buildMAXHeap(int tab[], int n) {
    int heapSize = n;
    int i = (heapSize / 2);
    for (int j = i; j >= 0; j--) {
        MAXHeapify(tab, n, j);
    }
}

void heapSort(int tab[], int n){
    buildMAXHeap(tab, n);
    int heapSize = n;
    for(int x = n; x >= 1; x--){
        swap(tab[0], tab[x]);
        heapSize = heapSize - 1;
        MAXHeapify(tab, heapSize, 0);
    }
}

//2 QUICK SORT
int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;

    for(int j = p; j <= r - 1; j ++){
        if(A[j]<=x){
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}
void quickSort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void printArray(int *tab, int n) {
    for (int i = 0; i <= n; i++) {
        cout << tab[i] << "|";
    }
    cout << endl;
}

//3 MERGE SORT

void merge(int *tab, int l, int s, int r) {
    int lSize = s - l + 1;
    int rSize = r - s;

    int *tabL = new int[lSize];
    int *tabR = new int[rSize];

    for (int x = 0; x < lSize; x++)
        tabL[x] = tab[l + x];
    for (int y = 0; y < rSize; y++)
        tabR[y] = tab[s + 1 + y];

    int indexL = 0;
    int indexR = 0;
    int currIndex;

    //array merging
    for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) {
        if (tabL[indexL] <= tabR[indexR])
            tab[currIndex] = tabL[indexL++];
        else
            tab[currIndex] = tabR[indexR++];
    }

    //lasts elements from Left tab are stored in tab
    while (indexL < lSize)
        tab[currIndex++] = tabL[indexL++];

    //lasts elements from Right tab are stored in tab
    while (indexR < rSize)
        tab[currIndex++] = tabR[indexR++];

    delete[] tabL;
    delete[] tabR;
}

void mergeSort(int *tab, int l, int r) {
    if (r > l) {
        int s = (l + r) / 2;
        mergeSort(tab, l, s);
        mergeSort(tab, s + 1, r);
        merge(tab, l, s, r);
    }
}

//4 BUBBLE SORT

void bubbleSort(int tab[], int n) {
    do {
        for (int i = 0; i < n - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
            }
        }
        n = n - 1;
    } while(n > 1);
}

//TO CHECK PRINT ARRAY

void printARRAY(int tab[], int n) {
    for (int i = 0; i <= n; ++i)
        cout << tab[i] << " ";
    cout << endl;
}

//COPY ARRAY
void copyArray(int arrayToCopy[], int newArray[]){

}

int main() {
    //wczytanie nieposortowanej tablicy
    vector<int> numbers;
    int UNSAforHS[400000];
    //Create an input file stream
    ifstream in("notSortedArray.txt",ios::in);
    int number;
    while (in >> number) {
        numbers.push_back(number);
    }
    for (int i=0; i<numbers.size(); i++) {
        UNSAforHS[i] = numbers[i];
    }
    in.close();
    int n = sizeof(UNSAforHS) / sizeof(UNSAforHS[0]) - 1;

    //kopiowanie UNSAforHS do nowych tablic do konkretnych sortowań
    int UNSAforQS[400000];
    for(int i = 0; i<=n; i++){
        UNSAforQS[i] = UNSAforHS[i];
    }
    int UNSAforMS[400000];
    for(int i=0; i<=n; i++){
        UNSAforMS[i] = UNSAforHS[i];
    }
    int UNSAforBS[400000];
    for(int i=0; i<=n; i++){
        UNSAforBS[i] = UNSAforHS[i];
    }
    //for time measuring
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    //HS_UNSA
    auto HS_UNSA_START = high_resolution_clock::now();
    heapSort(UNSAforHS, n);
    auto HS_UNSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_HS_UNSA = HS_UNSA_STOP - HS_UNSA_START;
    cout << "HS not sorted array: " << ms_double_HS_UNSA.count() << " ms\n";

    //QS_UNSA
    auto QS_UNSA_START = high_resolution_clock::now();
    quickSort(UNSAforQS, 0, n-1);
    auto QS_UNSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_QS_UNSA = QS_UNSA_STOP - QS_UNSA_START;
    cout << "QS not sorted array: " << ms_double_QS_UNSA.count() << " ms\n";

    //MS_UNSA
    auto MS_UNSA_START = high_resolution_clock::now();
    mergeSort(UNSAforMS, 0, n);
    auto MS_UNSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_MS_UNSA = MS_UNSA_STOP - MS_UNSA_START;
    cout << "MS not sorted array: " << ms_double_MS_UNSA.count() << " ms\n";

    //BS_UNSA
    cout << " start " << endl;
    auto BS_UNSA_START = high_resolution_clock::now();
    bubbleSort(UNSAforBS, n);
    auto BS_UNSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_BS_UNSA = BS_UNSA_STOP - BS_UNSA_START;
    cout << "BS not sorted array: " << ms_double_BS_UNSA.count() << " ms\n";

    cout << " end " << endl;

//wczytanie posortowanej rosnąco tablicy
    vector<int> numbers2;
    int ASSAforHS[400000];
    //Create an input file stream
    ifstream in2("ascendingSortedArray.txt",ios::in);
    int number2;
    while (in2 >> number2) {
        numbers2.push_back(number2);
    }
    for (int i=0; i<numbers2.size(); i++) {
        ASSAforHS[i] = numbers2[i];
    }
    in2.close();
//    int n = sizeof(ASSAforHS) / sizeof(ASSAforHS[0]) - 1;

    //kopiowanie ASSAforHS do nowych tablic do konkretnych sortowań
    int ASSAforQS[400000];
    for(int i = 0; i<=n; i++){
        ASSAforQS[i] = ASSAforHS[i];
    }
    int ASSAforMS[400000];
    for(int i=0; i<=n; i++){
        ASSAforMS[i] = ASSAforHS[i];
    }
    int ASSAforBS[400000];
    for(int i=0; i<=n; i++){
        ASSAforBS[i] = ASSAforHS[i];
    }

    //HS_ASSA
    auto HS_ASSA_START = high_resolution_clock::now();
    heapSort(ASSAforHS, n);
    auto HS_ASSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_HS_ASSA = HS_ASSA_STOP - HS_ASSA_START;
    cout << "HS ascending sorted array: " << ms_double_HS_ASSA.count() << " ms\n";

    //QS_ASSA
    auto QS_ASSA_START = high_resolution_clock::now();
    quickSort(ASSAforQS, 0, n-1);
    auto QS_ASSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_QS_ASSA = QS_ASSA_STOP - QS_ASSA_START;
    cout << "QS ascending sorted array: " << ms_double_QS_ASSA.count() << " ms\n";

    //MS_ASSA
    auto MS_ASSA_START = high_resolution_clock::now();
    mergeSort(ASSAforMS, 0, n);
    auto MS_ASSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_MS_ASSA = MS_ASSA_STOP - MS_ASSA_START;
    cout << "MS ascending sorted array: " << ms_double_MS_ASSA.count() << " ms\n";

    //BS_ASSA
    cout << " start " << endl;
    auto BS_ASSA_START = high_resolution_clock::now();
    bubbleSort(ASSAforBS, n);
    auto BS_ASSA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_BS_ASSA = BS_ASSA_STOP - BS_ASSA_START;
    cout << "BS ascending sorted array: " << ms_double_BS_ASSA.count() << " ms\n";
    cout << " end " << endl;

//wczytanie posortowanej malejąco tablicy
    vector<int> numbers3;
    int DESAforHS[400000];
    //Create an input file stream
    ifstream in3("descendingSortedArray.txt",ios::in);
    int number3;
    while (in3 >> number3) {
        numbers3.push_back(number3);
    }
    for (int i=0; i<numbers3.size(); i++) {
        DESAforHS[i] = numbers3[i];
    }
    in3.close();

    //kopiowanie DESAforHS do nowych tablic do konkretnych sortowań
    int DESAforQS[400000];
    for(int i = 0; i<=n; i++){
        DESAforQS[i] = DESAforHS[i];
    }
    int DESAforMS[400000];
    for(int i=0; i<=n; i++){
        DESAforMS[i] = DESAforHS[i];
    }
    int DESAforBS[400000];
    for(int i=0; i<=n; i++){
        DESAforBS[i] = DESAforHS[i];
    }

    //HS_DESA
    auto HS_DESA_START = high_resolution_clock::now();
    heapSort(DESAforHS, n);
    auto HS_DESA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_HS_DESA = HS_DESA_STOP - HS_DESA_START;
    cout << "HS descending sorted array: " << ms_double_HS_DESA.count() << " ms\n";


    //QS_DESA
    auto QS_DESA_START = high_resolution_clock::now();
    quickSort(DESAforQS, 0, n-2);
    auto QS_DESA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_QS_DESA = QS_DESA_STOP - QS_DESA_START;
    cout << "QS descending sorted array: " << ms_double_QS_DESA.count() << " ms\n";

    //MS_DESA
    auto MS_DESA_START = high_resolution_clock::now();
    mergeSort(DESAforMS, 0, n);
    auto MS_DESA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_MS_DESA = MS_DESA_STOP - MS_DESA_START;
    cout << "MS descending sorted array: " << ms_double_MS_DESA.count() << " ms\n";

    //BS_DESA
    cout << " start " << endl;
    auto BS_DESA_START = high_resolution_clock::now();
    bubbleSort(DESAforBS, n);
    auto BS_DESA_STOP = high_resolution_clock::now();

    duration<double, milli> ms_double_BS_DESA = BS_DESA_STOP - BS_DESA_START;
    cout << "BS descending sorted array: " << ms_double_BS_DESA.count() << " ms\n";
    cout << " end " << endl;

    return 0;
}
