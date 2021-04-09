/*
Meno a priezvisko: Oliver Semko

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie03.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>
//#include <iomanip> //ODSTARNIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}
*/

void insertionSort(int *data, const size_t length) {
    for(size_t i=1; i < length; i++){
        int curr = data[i];
        size_t j =i;
        while(j>0 && data[j-1] < curr)
        {
            data[j]=data[j-1];
            j--;
        }
        data[j] = curr;
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
        {"Andrej", nullptr} -> {"Andrej", nullptr}
        {nullptr} -> {nullptr}

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char *data[]) {

    size_t f = 0;
    while (data[f])
        f++;
    const char* c;

    for(size_t i=0; i < f; i++){
        for(size_t i=1; i < f; i++){
            string curr = data[i];
            size_t j = i;
            while(j > 0 && curr > data[j-1])
            {
                c = data[j-1];
                data[j-1] = data[j];
                data[j] = c;
                j--;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3, vystup: 3->2->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/

Node* findPred(List* list, Node* n)
{
    if (list == nullptr)
		return nullptr;
    if (list->first == nullptr || list->first->next == nullptr)
		return nullptr;

    Node* tmp = list->first;

    while (tmp->next != nullptr)
	{
        if (tmp->next == n){
            return tmp;
        }
        tmp = tmp->next;
    }

    return nullptr;
}

void insertNodeBefore(List* list, Node* _insert, Node* _target)
{
    if (list == nullptr)
		return;
    if (list->first == nullptr || _insert == nullptr || _target == nullptr)
    	return;
    if (_target == list->first){
        _insert->next = list->first;
        list->first = _insert;
        return;
    }
    Node* predchodca = findPred(list, _target);

    if (predchodca != nullptr){
        predchodca->next = _insert;
        _insert->next = _target;
    }
}

void insertionSort(List * list) {
    if (list == nullptr)
    	return;
    if (list->first == nullptr)
    	return;
    if (list->first->next == nullptr)
    	return;

    Node* firstUnsorted = list->first->next;
    Node* lastSorted = list->first;
    Node* tmp = nullptr;

    while (firstUnsorted)
	{
        tmp = list->first;

        while (tmp != firstUnsorted)
		{
            if (tmp->data < firstUnsorted->data){
                lastSorted->next = firstUnsorted->next;
                insertNodeBefore(list, firstUnsorted, tmp);
                break;
            }
            tmp = tmp->next;
        }

        if (tmp == firstUnsorted){
            lastSorted = firstUnsorted;
            firstUnsorted = firstUnsorted->next;
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' sa nemeni.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli)
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli)

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10}
        output pred vykonanim funkcie: {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20}
        output po vykonani funkcie:    {20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20}
*/

void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high)
{
    size_t prvy = low;
    size_t druhy = middle;
    size_t out = low;

    while(prvy < middle && druhy < high)
    {
        if(input[prvy] >= input[druhy]){
            output[out] = input[prvy];
            prvy++;
        }
        else{
            output[out] = input[druhy];
            druhy++;
        }
        out++;
    }
    while(prvy < middle)
    {
        output[out] = input[prvy];
        prvy++;
        out++;
    }
    while(druhy < high)
    {
        output[out] = input[druhy];
        druhy++;
        out++;
    }
}

void Rekurzia(int* pole1, int* pole2, const size_t low, const size_t high)
{
    if (low + 1 >= high)
        return;
    size_t middle = (high + low) / 2;
    Rekurzia(pole2, pole1, low, middle);
    Rekurzia(pole2, pole1, middle, high);
    merge(pole1, pole2, low, middle, high);
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}

    POZNAMKA:
        Pri implementacii top-down bude vhodne vytvorit a zavolat rekurzivnu funkciu.
*/
void mergeSort(int *data, const size_t length) {
    int* pom = new int[length];
    memcpy(pom, data, length * sizeof(int));
    Rekurzia(data, pom, 0, length);
    delete[] pom;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury


/*void println(const char * label, const int *data, const size_t length) {
    cout << label << ": ";
    for(size_t i = 0; i < length; ++i) {
        cout << setw(3) << data[i] << " ";
    }
    cout << endl;
}


void printlnS(const char * label, const char **data, const size_t length) {
    cout << label << ": ";
    for(size_t i = 0; i < length; ++i) {
        cout << setw(3) << data[i] << " ";
    }
    cout << endl;
}*/

void prependNode(List* list, int value)
{
    if (list == nullptr)
 		return;
    Node* s = new Node;

    s->data = value;
    s->next = list->first;
    list->first = s;
}

void printList(List* list)
{
    if (list == nullptr)
 		return;

    Node* tmp = list->first;

    while (tmp != nullptr)
	{
        cout << tmp->data << " --> ";
        tmp = tmp->next;
    }

    printf("NULL\n");
}

void deleteList(List* list)
{
    if (list == nullptr)
    	return;

    Node* tmp = list->first;
    Node* toDelete = nullptr;
    while (tmp != nullptr)
    {
        toDelete = tmp;
        tmp = tmp->next;
        free(toDelete);
    }

    list->first = nullptr;
}

int main() {

    //1. int data[] = {5, 7, 12, 1, 3};int len = sizeof(data)/sizeof(data[0]);insertionSort(data, len);println("data", data, len);
    //5. int input[] = {1, 2, 3};int len = sizeof(input)/sizeof(input[0]);mergeSort(input, len);println("output", input, len);
    /*4. int input[] = {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10};
    int output[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
    int len = sizeof(output)/sizeof(output[0]);
    int low = 4;
    int middle = 8;
    int high = 12;
    merge(output, input, low, middle, high);
    println("output: ", output, len);*/
    //2. const char *data[] = {"Dano", "Beata", "Anca", "Cecil", "Erik", "Gadzo", "Filomena", nullptr};insertionSort(data);int length = sizeof(data)/sizeof(data[0]);printlnS("output ", data, length);

    /*3. int i = 0;
    srand((unsigned int)time(nullptr));

    cout << "InsertionSort: Zretazeny zoznam\n-----------------------------\n";
    List list;
    list.first = nullptr;

    for (i; i < 10; i++)
        prependNode(&list, rand() % 100);
    cout << "Neusporiadany zoznam:\t";
    printList(&list);
    insertionSort(&list);
    cout << "Usporiadany zoznam:\t";
    printList(&list);

    deleteList(&list);*/

    return 0;
}
