#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;
int const characterAmount = 54;

int const amountOfCharsInPatternSIZE = 54;


void MIN_HEAPIFY(int array[][2], int size, int k) {
    int l = 2 * k + 1;
//    cout << "moje l= " << l << endl << endl;
    int r = 2 * k + 2;
//    cout << "moje r= " << r << endl << endl;
    int lowest;

    if (l <= size && array[l][1] < array[k][1]) {
        lowest = l;
    } else {
        lowest = k;
    }
    if (r <= size && array[r][1] < array[lowest][1]) {
        lowest = r;
    }
    if (lowest != k) {
        int tempValue = array[k][1];
        int tempLetter = array[k][0];
        array[k][0] = array[lowest][0];
        array[k][1] = array[lowest][1];
        array[lowest][0] = tempLetter;
        array[lowest][1] = tempValue;
        MIN_HEAPIFY(array, size, lowest);
    }
}

void buildMINHeap(int array[][2], int size) {
    int i = (size / 2) - 1;
    int j = i;
    for (j; j >= 0; j--) {
        MIN_HEAPIFY(array, size, j);
    }
}

int extractMinLetter(int array[][2]) {
    int minLetter = array[0][0];
    return minLetter;
}

int extractMinLetterRepeat(int array[][2]) {
    int minLetterRepeat = array[0][1];
    return minLetterRepeat;
}

void alterArray(int array[][2], int size) {
    array[0][0] = array[size][0];
    array[0][1] = array[size][1];
}


struct TNode {
    int frequency;
    TNode *left;
    TNode *right;
    string key;
};

struct BuildHuffmannTree* buildHuffmannTree();


int main() {
    //___OPENING FILE___
    fstream newFile;
    string characters;
    newFile.open("myText.txt", ios::in); //open a file to perform read operation using file object
    if (newFile.is_open()) { //checking whether the file is open
        while (getline(newFile, characters)) { //read data from file object and put it into string.
            cout << characters << "\n"; //print the data of the string
        }
        newFile.close(); //close the file object.
    } else {
        cout << "Unable to open file" << endl;
    }

    //___CREATE PATTERN ARRAY___
    string charPattern = "ABCDEFGHIJKLMNOPRSTQUVWXYZ ,.abcdefghijklmnoprstquvwxyz";
    int arraySize = charPattern.size();
    int charsArrayWithAmount[arraySize][2];
    for (int i = 0; i < charPattern.size(); i++) {
        charsArrayWithAmount[i][0] = charPattern[i];
        charsArrayWithAmount[i][1] = 0;
    }
    cout << "size: " << charPattern.size() << endl;

    //___CHECKING PATTERN ARRAY___
    for (int i = 0; i < charPattern.size(); i++) {
        cout << "cAWA" << i << "= " << charsArrayWithAmount[i][0] << " repeats= " << charsArrayWithAmount[i][1] << endl;
    }
    cout << "characters.size()= " << characters.size() << endl;

    //___COUNTING LETTERS FROM TEXT FILE AND SAVE IT TO PATTERN ARRAY___
    for (int i = 0; i < charPattern.size(); i++) {
//        cout << "i= " << i << "charAWA[i][0] = " << charsArrayWithAmount[i][0] << endl;
        for (int j = 0; j < characters.size(); j++) {
//            cout << "characters[j] = " << (int)charPattern[j] << endl;
            if (charsArrayWithAmount[i][0] == characters[j]) {
                charsArrayWithAmount[i][1] = charsArrayWithAmount[i][1] + 1;
            }
        }
    }

    //___CHECKING PATTERN ARRAY___
    for (int i = 0; i < charPattern.size(); i++) {
        cout << "AFTER cAWA" << i << "= " << charsArrayWithAmount[i][0] << " repeats= " << charsArrayWithAmount[i][1]
             << endl;
    }

    //HUFFMANN ALGORYTHM
    cout << "PRZED KOPCOWANIEM:" << endl;
    int size = sizeof(charsArrayWithAmount) / sizeof(charsArrayWithAmount[0]);
    cout << "size before: " << size << endl;
    for (int i = 0; i < size; i++) {
        cout << "wiersz: " << i << " : ";
        for (int j = 0; j < 2; j++) {
            cout << charsArrayWithAmount[i][j] << ", ";
        }
        cout << endl;
    }
    //KOPCOWANIE
    buildMINHeap(charsArrayWithAmount, size);

    cout << endl << "PO KOPCOWANIU:" << endl;
    cout << "size after: " << size << endl;
    for (int i = 0; i < size; i++) {
        cout << "wiersz: " << i << " : ";
        for (int j = 0; j < 2; j++) {
            cout << charsArrayWithAmount[i][j] << ", ";
        }
        cout << endl;
    }

    //HUFFMAN
    int tempSize = size - 1;
    for (int repeat = 1; repeat <= size; repeat++) {
        //extract X
        int minXLetter = extractMinLetter(charsArrayWithAmount);
        int minXRepeats = extractMinLetterRepeat(charsArrayWithAmount);
        struct TNode element_l;
        element_l.left=NULL;
        element_l.right=NULL;
        element_l.frequency = minXRepeats;
        element_l.key = minXLetter;
        //make array ready to heap again
        alterArray(charsArrayWithAmount, size);
        buildMINHeap(charsArrayWithAmount, tempSize);
        tempSize--;
        //extract Y
        int minYLetter = extractMinLetter(charsArrayWithAmount);
        int minYLetterRepeats = extractMinLetterRepeat(charsArrayWithAmount);
        struct TNode element_r;
        element_r.left=NULL;
        element_r.right=NULL;
        element_r.frequency=minYLetterRepeats;
        element_r.key=minYLetter;
        alterArray(charsArrayWithAmount, tempSize);
        tempSize--;
        //create node_Z = add X and Y
        struct TNode node_Z;
        node_Z.key="";
        node_Z.frequency=minXRepeats+minYLetterRepeats;
        node_Z.left=&element_l;
        node_Z.right=&element_r;
        //add node_Z to binary - HUFFMAN TREE


    }



    return 0;
}
