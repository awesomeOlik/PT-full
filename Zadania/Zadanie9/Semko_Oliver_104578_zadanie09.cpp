/*
Meno a priezvisko: Oliver Semko

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie09.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
     V prvych osmich prikladoch mozete pouzit iterativnu alebo rekurzivnu implementaciu. <- SPECIALNE INSTRUKCIE PRE TOTO ZADANIE
     V pripade implementacie rekurziou, moze byt hlavna cast implemetovana v pridanej rekurzivnej funkcii. <- SPECIALNE INSTRUKCIE PRE TOTO ZADANIE
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <exception>
#include <set>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol binarneho vyhladavacieho stromu
struct Node {
    int value;     // hodnota uzla
    Node *smaller; // uzol 'smaller' a jeho nasledovnici maju hodnotu mensiu ako 'value'
    Node *greater; // uzol 'greater' a jeho nasledovnici maju hodnotu vacsiu ako 'value

    explicit Node(int value = 0, Node *smaller = nullptr, Node *greater = nullptr)
            : value(value)
            , smaller(smaller)
            , greater(greater)
    {
    }
};

// Binarny vyhladavaci strom
struct BinarySearchTree {
    Node *root; // koren stromu

    explicit BinarySearchTree(Node *root = nullptr)
            : root(root)
    {
    }
};

// Vynimka oznacujuca, ze uzol so zadanou hodnotou v strome neexistuje
class ValueNotExistsException : public std::exception {
};

void PrintL(list<int>& List);
//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati najmensiu hodnotu v strome.
    V pripade neexistencie tejto hodnoty vyhodi vynimku.

    VSTUPNY PARAMETER:
        [in] tree - strom, v ktorom funkcia hlada minimum

    NAVRATOVA HODNOTA:
        najmensia hodnota v strome

    VYNIMKA:
        ValueNotExistsException - ak je strom prazdny
*/

int min(const Node* node){
    if(node == nullptr)
        return 0;
    const Node * curr = node;
    while(curr->smaller != nullptr)
        curr = curr->smaller;
    return(curr->value);
}

int min(const BinarySearchTree *tree) {
    if(tree->root == nullptr)
        throw ValueNotExistsException();
    return min(tree->root); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati hlbku uzla s hodnotou 'value' v strome 'tree'.
    Hlbka korena je 0.
    Ak hladany uzol v strome nie je, tak funkcia vyhodi vynimku.

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia hlada uzol
        [in] value - hodnota hladaneho uzla

    NAVRATOVA HODNOTA:
        Hlbka uzla s hodnotou 'value'.

    VYNIMKA:
        ValueNotExistsException - ak sa uzol s hodnotou 'value' v strome nenachdza
*/

int depth2(const Node* node, int val, int dpth){
    if(node == nullptr)
        return 0;
    if(node->value == val)
        return dpth;
    int next = depth2(node->smaller, val, dpth+1);
    if(next != 0)
        return next;
    next = depth2(node->greater, val, dpth+1);
    return next;
}

unsigned depth(const BinarySearchTree *tree, int value) {
    int a = depth2(tree->root, value, 0);
    if(tree==nullptr||tree->root==nullptr){
        throw ValueNotExistsException();
    }
    else if(a == 0 && (value != tree->root->value)){
        throw ValueNotExistsException();
    }
    return a;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam hodnot uzlov, ktore musi prejst pri hladani uzla s hodnotou 'value'.
    Prva hodnota vystupneho zoznamu je hodnota korena, druha hodnota zoznamu je lavy alebo pravy nasledovnik korena, atd.
    Poslednou hodnotou vo vystupnom zozname je hodnota uzla, na ktorom sa hladanie zastavilo.
    Ak 'tree' obsahuje uzol s hodnotou 'value', tak poslednou hodnotou vystupeho zoznamu je 'value'.

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia hlada uzol s hodnotou 'value'
        [in] value - hodnota hladaneho uzla

    NAVRATOVA HODNOTA:
        Zoznam hodnot uzlov, ktorych hodnoty musela funkcia pri hladani porovnavat.
        Poradie hodnot vo vystupnom zozname musi zodpovedat poradiu prechadzania uzlov stromu.

    PRIKLADY:
        V prikladoch predpokladajme strom:
                  40
                 /  \
               20    50
              /  \    \
            10   30    60

        1. priklad
            value: 30 -> vystup: (40, 20, 30)
        2. priklad
            value: 45
            vystup: (40, 50)
*/

bool path(Node* node, list<int>&a, int val){
    if(!node)
        return false;
    a.push_back(node->value);
    if(node->value == val)
        return true;
    else{
        if(path(node->smaller, a, val) || path(node->greater, a, val))
            return true;
    }
    a.pop_back();
    return false;
}

list<int> path(const BinarySearchTree *tree, int value) noexcept {
    list<int>retVal;
    list<int>retVal_official;
    if(path(tree->root, retVal, value)){
        list<int>::iterator it;
        for (it = retVal.begin(); it != retVal.end(); ++it)
            retVal_official.push_back(*it);
    }
    //PrintL(retVal_official);
    return retVal_official;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet uzlov stromu.

    VSTUPNY PARAMETER:
        [in] tree - strom, ktoreho pocet uzlov funkcia zistuje

    NAVRATOVA HODNOTA:
        pocet uzlov stromu
*/

int count(Node * node, size_t n){
    if(node == nullptr)
        return 0;
    if(node->smaller!=nullptr){
        n++;
        n=count(node->smaller, n);
    }
    if(node->greater!=nullptr){
        n++;
        n=count(node->greater, n);
    }
    return n;
}

size_t count(const BinarySearchTree *tree) noexcept {
    size_t n = 1;
    return count(tree->root, n);
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam hodnot vsetkych uzlov v strome 'tree'.
    Zoznam musi byt usporiadany od najmensieho prvku po najvacsi.

    Usporiadanie dosiahnite vhodnou postupnostou prechadzania uzlov stromu!

    VSTUPNY PARAMETER:
        [in] tree - strom, ktoreho hodnoty funkcia vrati

    NAVRATOVA HODNOTA:
        hodnoty uzlov, v poradi od najmensej po najvacsiu
*/
list<int> all(const BinarySearchTree *tree) noexcept {
    return list<int>();
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet uzlov stromu 'tree', ktorych hodnota je vacsie ako 'value'

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia pocita pocet uzlov splnajich podmienku
        [in] value - hodnota, podla ktorej sa vyberaju uzly

    NAVRATOVA HODNOTA:
        pocet uzlov s hodnotou vacsou ako 'value'
*/
size_t countGreater(Node* node, int val){
    if(node == nullptr)
        return 0;
    int cS = countGreater(node->smaller, val);
    int cG = countGreater(node->greater, val);
    return (node->value > val ? 1 : 0)+ cS + cG;
}

size_t countGreater(const BinarySearchTree *tree, int value) noexcept {
    return countGreater(tree->root, value);
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani vsetky uzly stromu a dealokuje ich.

    Na dealokaciu pouzite operator 'delete'!

    VSTUPNY PARAMETER:
        [in] tree - strom, ktoreho uzly funkcia odstrani

    VYSTUPNE PODMIENKY:
        vsetky uzly su dealokovane
        'tree->root' je nulovy smernik
*/
void clear(Node* node){
    if(node == nullptr)
        return;
    clear(node->smaller);
    clear(node->greater);
    delete node;
}

void clear(BinarySearchTree *tree) noexcept {
    clear(tree->root);
    tree->root = nullptr;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia hlada hodnotu 'value' vo vektore 'data'.
    Vrati pocet prvkov v 'data', ktore pri hladni porovnala s 'value'.
    Vektor 'data' obsahuje usporiadane hodnoty.
    Casova narocnost algoritmu je O(n log(n)).

    PARAMETRE:
        'data' - hodnoty usporiadane od najmensieho prvku po najvacsi
        'value' - hodnota hladana v 'data'

    NAVRATOVA HODNOTA:
        Pocet prvkov 'data', ktore funkcia pri hladani porovnala s 'value'.
        (bez ohladu na to, ci 'data' obsahuje hodnotu 'value').

    VSTUPNA PODMIENKA:
        Hodnoty v 'data' su usporiadane od najmensieho prvku po najvacsi.

    PRIKLADY:
        data = (100, 102, 104, 106, 108, 110, 112), value = 106 -> vystup: 1
        data = (100, 102, 104, 106, 108, 110, 112), value = 110 -> vystup: 2
        data = (100, 102, 104, 106, 108, 110, 112), value = 108 -> vystup: 3
        data = (100, 102, 104, 106, 108, 110), value = 104 -> vystup: 1 alebo 3
        data = (100, 102, 104, 106, 108, 110), value = 107 -> vystup: 3
        data = (100), value = 100 -> vystup: 1
        data = (200), value = 200 -> vystup: 1
        data = (), value = 100 -> vystup: 0
*/

int contains(int arr[], int s, int g, int val, int i){
    if(g >= s){
        int mid = s + (g - s)/2;
        if(arr[mid] == val){
            i++;
            return i;
        }
        if(arr[mid] > val){
            i++;
            return contains(arr, s, mid - 1, val, i);
        }
        if(arr[mid < val]){
            i++;
            return contains(arr, mid +1 , g, val, i);
        }
    }
    return i;
}

unsigned contains(const vector<int> & data, int value) noexcept {
    int arr[data.size()];
    std::copy(data.begin(), data.end(), arr);
    int n = sizeof(arr)/sizeof(arr[0]);
    return contains(arr, 0, n - 1, value, 0);
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori a vrati histogram slov v 'data' (zisti, kolko krat sa ktore slovo nachadza v 'data')

    PARAMETER:
        'data' - vektor slov

    NAVRATOVA HODNOTA:
        histogram slov (pre kazde slovo z 'data' obsahuje pocet jeho vyskytov)

    VSTUPNE PODMIENKY:
        'data' moze obsahovat lubobolny pocet slov
        'data' moze obsahovat opakujuce sa slova
        slova mozu byt prazdne retazce

    VYSTUPNE PODMIENKY:
        Histogram obsahuje iba slova, ktore sa v 'data' nachadzaju

    PRIKLADY:
        vstup: data = ("pocitac", "lietadlo", luk", "pocitac", "pocitac", "okno", "luk")
        vystup: {"pocitac" -> 3, "lietadlo" -> 1, "luk" -> 2, "okno" -> 1}

        vstup: data = ("pocitac", "")
        vystup: {"pocitac" -> 1, "" -> 1}

        vstup: data = ()
        vystup: {}
*/

map<string, size_t> histogram(const vector<string> & data) noexcept {
    map<string, size_t> retVal;
    for(auto i=data.begin(); i!=data.end(); i++){
        size_t amount = 0;
        for(auto j=data.begin(); j!=data.end(); j++){
            if(*i == *j)
                amount++;
            if(j == data.end()-1)
                retVal.insert({*i, amount});
        }
    }
    /*for(auto a=retVal.begin(); a != retVal.end(); a++)
        cout << a->first << ", " << a->second << endl;*/
    return retVal;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori a vrati index slov v 'data' (pre kazde slovo mnozinu indexov jeho vyskytu).

    PARAMETER:
        data - vektor slov

    NAVRATOVA HODNOTA:
        index slov (pre kazde slovo z 'data' obsahuje indexy, na ktorych sa slovo v 'data' nachadza)

    VSTUPNE PODMIENKY:
        'data' moze obsahovat lubobolny pocet slov
        'data' moze obsahovat opakujuce sa slova
        slova mozu byt prazdne retazce

    VYSTUPNE PODMIENKY:
        Index obsahuje zoznamy vyskytov len pre slova, ktore sa nachadzaju v 'data'

    PRIKLADY:
        vstup: data = ("pocitac", "lietadlo", luk", "pocitac", "pocitac", "okno", "luk")
        vystup: {"pocitac" -> {0, 3, 4}, "lietadlo" -> {1}, "luk" -> {2, 6}, "okno" -> {5}}

        vstup: data = ("pocitac", "")
        vystup: {"pocitac" -> {0}, "" -> {1}}

        vstup: data = ()
        vystup: {}
*/

map<string, set<size_t>> index(const vector<string> & data) noexcept {
    map<string, set<size_t>> retVal;
    set<size_t> s;
    for(auto i=data.begin(); i != data.end(); i++){
        size_t hlp = 0;
        for(auto j=data.begin(); j!=data.end(); j++){
            if(*i == *j){
                hlp++;
                s.insert(hlp);
            }
        }
        retVal.insert({*i, s});
        s.clear();
    }

    return retVal;
}
//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

Node * addNode(Node* curr, const int val){
    if(curr){
        if(val < curr->value)
            curr->smaller = addNode(curr->smaller, val);
        else if(val > curr->value)
            curr->greater = addNode(curr->greater, val);
        return curr;
    }
    else
        return new Node{val, nullptr};
}

void addNode(BinarySearchTree* bst, const int val){
    bst->root = addNode(bst->root, val);
}

BinarySearchTree* cBST(const initializer_list<int>& list){
    BinarySearchTree* bst{new BinarySearchTree{}};
    for(int i : list)
        addNode(bst, i);
    return bst;
}

void PrintL(list<int>& List)
{
    list<int>::iterator it;
    for (it = List.begin(); it != List.end(); ++it)
        cout << " " << *it;
    cout << endl;
}

vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value) noexcept {
    vector<vector<int>> vec;
    vector<int> vec2;
    for(size_t i=0; i<size1; i++){
        vec2.clear();
        for(size_t j=0; j<size2; j++){
            vec2.insert(vec2.begin(), value);
        }
     vec.insert(vec.begin() + i, vec2);
    }

    return vec;
}

int main() {

    //BinarySearchTree * bst{cBST({20, 10, 70, 0, 15, 50, 80, 18, 55})};
    //1. cout << min(bst); //------>EXCEPTION
    //2. cout << depth(bst, 20); //--------->EXCEPTION
    //3. path(bst, 18);        //-------->AK CISLO KT. TAM NENI
    //4. cout << count(bst);
    //5. all(bst);   //--------->FAIL
    //6. cout << countGreater(bst, 50);
    //7. clear(bst);
    //8. vector<int> data = {}; cout << contains(data, 100);
    //9. histogram({"pocitac", ""});
    //10. index({"pocitac", "lietadlo", "luk", "pocitac", "pocitac", "okno", "luk"});

    return 0;
}
