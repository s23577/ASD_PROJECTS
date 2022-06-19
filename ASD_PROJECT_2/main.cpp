#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <map>
#include <sstream>

using namespace std;
int const characterAmount = 54;
int const amountOfCharsInPatternSIZE = 54;

//przywracanie wlasnosci kopca
void MIN_HEAPIFY(int array[][2], int size, int k) {
    int l = 2 * k + 1;
//    cout << "moje l= " << l << " wart w tab:" << array[l][0] << endl << endl;
    int r = 2 * k + 2;
//    cout << "moje r= " << r << " wart w tab:" << array[l][0] << endl << endl;
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

//zbuduj kopiec typu minimum
void buildMINHeap(int array[][2], int size) {
    int i = (size / 2) - 1;
    int j = i;
    for (j; j >= 0; j--) {
        MIN_HEAPIFY(array, size, j);
    }
}

//pobierz litere o najmniejszej czestotliwosci
int extractMinLetter(int array[][2]) {
    int minLetter = array[0][0];
    return minLetter;
}

//pobierz ilosc powtórzen litety o najmniejszej czestotliwosci
int extractMinLetterRepeat(int array[][2]) {
    int minLetterRepeat = array[0][1];
    return minLetterRepeat;
}

//zmien tablicę, tz. przerzuc ostatni element na pierwszy
void alterArray(int array[][2], int size) {
    array[0][0] = array[size][0];
    array[0][1] = array[size][1];
}

//dodaj wezel Z do tablicy wezlow
void addToArrayNode_Z(int array[][2], int size, int sum, int node_key) {
    array[size][0] = node_key;
    array[size][1] = sum;
}

//struktura wezla
struct TNode {
    int frequency;
    TNode *left;
    TNode *right;
    int key;
    string code = "";
};

//stworzenie mapy i zliczanie powtorzen literek
std::map<string, string> codesMap;

std::map<string, std::string> printCodes(TNode *node, string value) {
    string code;
    code.append(value);
    code.append(node->code);
    cout << "from method: " << code << endl;

    if (node->left) {
        printCodes(node->left, code);
        cout << "\t\tfrom left: " << code << endl;
    }
    if (node->right) {
        printCodes(node->right, code);
        cout << "\t\tfrom right: " << code << endl;
    }
    if (!node->left && !node->right) {
        string tempKey = std::to_string(node->key);
        codesMap.insert(std::pair<string, string>(tempKey, code));
    }
    return codesMap;
}


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
    cout << "CHARACTERS SIZE= " << characters.size() << endl;
    //string do skompresowania
//    string characters = "Barbara ma rabarbar";

    //___CREATE PATTERN ARRAY___ tablica odniesienia
    string charPattern = "Barbm ";
    int charPatternSize = charPattern.size();
    cout << "CHAR PATTERN SIZE=" << charPatternSize << endl;
    int charsArrayWithAmount[charPatternSize][2];
    cout << "CHARS ARRAY WITH AMOUNT AMOUNT SIZE= "
         << sizeof(charsArrayWithAmount) / sizeof(charsArrayWithAmount[0][0]) - 1 << endl;
    for (int i = 0; i < charPattern.size(); i++) {
        charsArrayWithAmount[i][0] = charPattern[i];
        charsArrayWithAmount[i][1] = 0;
    }
    cout << "size: " << charPattern.size() << endl;

    //___CHECKING PATTERN ARRAY___ wydrukuj tablice odniesienia
    for (int i = 0; i < charPattern.size(); i++) {
        cout << "cAWA" << i << "= " << charsArrayWithAmount[i][0] << " repeats= " << charsArrayWithAmount[i][1] << endl;
    }
    cout << "characters.size()= " << characters.size() << endl;

    //___COUNTING LETTERS FROM TEXT FILE AND SAVE IT TO PATTERN ARRAY___ zlicz literki ze stringa do skompresowania do tablicy odniesienia
    for (int i = 0; i < charPattern.size(); i++) {
//        cout << "i= " << i << "charAWA[i][0] = " << charsArrayWithAmount[i][0] << endl;
        for (int j = 0; j < characters.size(); j++) {
//            cout << "characters[j] = " << (int)charPattern[j] << endl;
            if (charsArrayWithAmount[i][0] == characters[j]) {
                charsArrayWithAmount[i][1] = charsArrayWithAmount[i][1] + 1;
            }
        }
    }
    //___CHECKING PATTERN ARRAY___ wydrukuj uzupelniona tablice odniesienia
    for (int i = 0; i < charPattern.size(); i++) {
        cout << "AFTER cAWA" << i << "= " << charsArrayWithAmount[i][0] << " repeats= " << charsArrayWithAmount[i][1]
             << endl;
    }

    //HUFFMANN ALGORYTHM
    cout << "PRZED KOPCOWANIEM:" << endl;
//    int size = sizeof(charsArrayWithAmount) / sizeof(charsArrayWithAmount[0]) - 1; //to DELETE
    int size = charPatternSize - 1;
    cout << "size before: " << size << endl;
    for (int i = 0; i <= size; i++) {
        cout << "wiersz: " << i << " : ";
        for (int j = 0; j < 2; j++) {
            cout << charsArrayWithAmount[i][j] << ", ";
        }
        cout << endl;
    }
    //KOPCOWANIE przed rozpoczeciem algorytmu huffmana
    buildMINHeap(charsArrayWithAmount, size);

    cout << endl << "PO KOPCOWANIU:" << endl;
    cout << "size after: " << size << endl;
    for (int i = 0; i <= size; i++) {
        cout << "wiersz: " << i << " : ";
        for (int j = 0; j < 2; j++) {
            cout << charsArrayWithAmount[i][j] << ", ";
        }
        cout << endl;
    }

    //----HUFFMAN ALGORYTM----
    int tempSize = size;
    //tablica node (węzłów)
    TNode nodesTab[100];
    //pomocniczy key do node'a posredniego, aby mialy swoje unikatowe klucze
    int const node_Key = 300;
    //pomocnicze wskazniki
    TNode *tempNodeL;
    TNode *tempNodeR;
    for (int repeat = 0; repeat < size; repeat++) {
        int sum = 0;

        //----extract L----
        int min_L_Letter = extractMinLetter(charsArrayWithAmount);
        int min_L_Repeats = extractMinLetterRepeat(charsArrayWithAmount);
        //sprawdzenie czy L jest węzłem
        TNode *element_L = new TNode();
        if (min_L_Letter < node_Key) {
            element_L->left = nullptr;
            element_L->right = nullptr;
            element_L->frequency = min_L_Repeats;
            element_L->key = min_L_Letter;
            element_L->code = "0";
        } else {
            //odnalezienie istniejącego węzła w tablicy wezlow
            for (TNode node: nodesTab) {
                if (node.key == min_L_Letter) {
                    node.code = "0";
                    tempNodeL = &node;
                }
            }
        }

        //make array ready to heap again
        alterArray(charsArrayWithAmount, tempSize);
        tempSize--;
        buildMINHeap(charsArrayWithAmount, tempSize);

        //----extract R----
        int min_R_Letter = extractMinLetter(charsArrayWithAmount);
        int min_R_Repeats = extractMinLetterRepeat(charsArrayWithAmount);
        TNode *element_R = new TNode();
        if (min_R_Letter < node_Key) {
            element_R->left = nullptr;
            element_R->right = nullptr;
            element_R->frequency = min_R_Repeats;
            element_R->key = min_R_Letter;
            element_R->code = "1";
        } else {
            //odnalezienie istniejącego węzła
            for (TNode &node: nodesTab) {
                if (node.key == min_R_Letter) {
                    node.code = "1";
                    tempNodeR = &node;
                }
            }
        }

        //make array ready to heap again
        alterArray(charsArrayWithAmount, tempSize);
        tempSize--;
        buildMINHeap(charsArrayWithAmount, tempSize);

        //create node_Z = add L and R
        TNode *node_Z = new TNode;
        //nadanie unikatowego klucza posredniemu wezlowi
        node_Z->key = node_Key + repeat;
        sum = min_R_Repeats + min_L_Repeats;
        node_Z->frequency = sum;
        //jesli dziecko lewe to wezel to zapisz je jako dziecko do nowego wezla
        if (min_L_Letter < node_Key) {
            node_Z->left = element_L;
        } else {
            node_Z->left = tempNodeL;
            cout << "temp node x address" << tempNodeL << endl;
        }
        //jesli dziecko prawe to wezel to zapisz je jako dziecko do nowego wezla
        if (min_R_Letter < node_Key) {
            node_Z->right = element_R;
        } else {
            node_Z->right = tempNodeR;
            cout << "temp node y address" << tempNodeR << endl;
        }
        //add node_Z to binary - HUFFMAN TREE ARRAY
        nodesTab[repeat] = *node_Z;
        tempSize++;
        addToArrayNode_Z(charsArrayWithAmount, tempSize, sum, node_Key + repeat);
        cout << repeat << " PRZED KOPCOWANIEM PO DODANIU WEZLA Z, tempSize after: " << tempSize << endl;
        for (int i = 0; i <= tempSize; i++) {
            cout << "wiersz: " << i << " : ";
            for (int j = 0; j < 2; j++) {
                cout << charsArrayWithAmount[i][j] << ", ";
            }
            cout << endl;
        }
        buildMINHeap(charsArrayWithAmount, tempSize);
        cout << repeat << " PRZED KOPCOWANIEM PO DODANIU WEZLA Z, tempSize after: " << tempSize << endl;
        for (int i = 0; i <= tempSize; i++) {
            cout << "wiersz: " << i << " : ";
            for (int j = 0; j < 2; j++) {
                cout << charsArrayWithAmount[i][j] << ", ";
            }
            cout << endl;
        }
    }
    //drukowanie tablicy ze strukturami (nodeami)
    for (int repeat = 0; repeat < size; repeat++) {
        cout << "NODE_Z :" << " " << repeat << "address" << &nodesTab[repeat] << " key=" << nodesTab[repeat].key
             << ", : << frequency="
             << nodesTab[repeat].frequency << ", left child=" << nodesTab[repeat].left << " "
             << nodesTab[repeat].left->key << ", right child= "
             << nodesTab[repeat].right << endl;
    }
    cout << "-------------- MAPA -------------" << endl;
    //DRUKOWANIE MAPY DO SPRAWDZENIA
    std::map<string, std::string> codes = printCodes(&nodesTab[size - 1], "");
    {
        map<string, std::string>::iterator it;
        for (it = codes.begin(); it != codes.end(); it++) {
            std::cout << (char) stoi(it->first)
                      << ":"
                      << it->second
                      << std::endl;
        }
    }
    //tworzenie nowego stringa z 0 i 1
    string binaryString;
    for (int i = 0; i <= characters.size(); i++){
        map<string, std::string>::iterator it;
        for (it = codes.begin(); it != codes.end(); it++) {
            if(characters[i] == stoi(it->first)){
                binaryString.append(it->second);
            }
        }
    }
    cout << "\n\nOUT: " << binaryString << endl;

    //tworzenie tablicy booleans
    bool tmp[binaryString.size()]; // tmp has actual values in it, this is just used to show what are tmp and size
    for(int i = 0; i< binaryString.size(); i++){
        tmp[i] = binaryString[i] == '1';
//        istringstream(binaryString[i]) >> tmp[i];
        cout << tmp[i];
    }
    //cout << tmp[0];


    //zapis do pliku słownika
//    ofstream outfile("result.txt");
//    {
//        map<string, std::string>::iterator it;
//        for (it = codes.begin(); it != codes.end(); it++) {
//            string tempS = it->first;
//            outfile << tempS;
//            outfile << ": ";
//            outfile << it->second;
//            outfile << std::endl;
//        }
//    }
//    outfile.close();
    FILE* f = fopen("result.txt", "wba");
    for (int i=0; i<binaryString.size(); i+=8) {
        char q = 0;
        for (int j=7; j>=0; j--)
        q |= tmp[7-j+i]<<j ;
        fwrite(&q, 1, 1, f);
        //fwrite("\n", sizeof(char), 1, f); // insert new line
    }
    fclose(f);

    return 0;
}
