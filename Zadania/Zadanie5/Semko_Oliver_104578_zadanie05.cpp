/*
Meno a priezvisko: Oliver Semko

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie05.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnovali popis pri ich deklaraciach.
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

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy prvok do heapu.
    Verzia heap-u je Min-heap (hodnota kazdeho uzla je mensia alebo rovna ako hodnoty vsetkych jeho nasledovnikov).
    Pouzite algoritmus sift up.

    PARAMETRE:
        [in, out] data - pole, ktoreho prva cast tvori heap, do ktoreho funkcia prida novy prvok
        [in] addIndex - index prvku v 'data', ktory prida do heap-u (preusporiadanim prvkov)

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole s dlzkou minimalne 'addIndex+1'
        'addIndex' moze mat lubovolnu hodnotu
        Prvky data[0]...data[addIndex-1] (vratane) tvoria heap

    VYSTUPNE PODMIENKY:
        Prvky data[0]...data[addIndex] (vratane) tvoria heap
        Preusporiada prvky data[0]...data[addIndex] tak, aby tvorili heap

    PRIKLADY:
        vstup:  data = {2, 4, 10, 7, 1, 2, 5, 0, 3, -1, 11, 12, 1}, addIndex = 4
        vystup: data = {1, 2, 10, 7, 4, 2, 5, 0, 3, -1, 11, 12, 1}

        vstup:  data = {3, 4, 10, 5, 5, 11, 15, 7, 8, 9, 10, 14,  8, 1, 2}, addIndex = 12
        vystup: data = {3, 4,  8, 5, 5, 10, 15, 7, 8, 9, 10, 14, 11, 1, 2}
*/
void swap(int *c1, int *c2)
{
    int pom = *c1;
    *c1 = *c2;
    *c2 = pom;
}

void siftUp(int data[], const size_t addIndex)
{
    size_t Rodic;
    if(addIndex > 0){
        Rodic = (addIndex - 1)/2;
        if(data[Rodic] > data[addIndex]){
            swap(&data[Rodic], &data[addIndex]);
            siftUp(data, Rodic);
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori heap na poli 'data' preusporiadanim prvkov.
    Verzia heap-u je Min-heap (hodnota kazdeho uzla je mensia alebo rovna ako hodnoty vsetkych jeho nasledovnikov).
    Pouzite algoritmus sift up.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia preusporiada, aby bolo heap-om
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        'data' je heap-om

    PRIKLAD:
        vstup:  data = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6}, length = 11
        vystup: data = {1, 2, 2, 2, 2, 5, 3, 7, 4, 8, 6}
*/
void buildHeapSiftUp(int data[], const size_t length)
{
    for(size_t i = 1; i < length; i++){
        siftUp(data, i);
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia opravi cast heap-u (podstrom ktoreho koren ma index 'topIndex').
    Verzia heap-u je Min-heap (hodnota kazdeho uzla je mensia alebo rovna ako hodnoty vsetkych jeho nasledovnikov).
    Pouzite algoritmus sift down.

    PARAMETRE:
        [in, out] data - pole, v ktorom funkcia opravi cast heapu preusporiadanim prvkov
        [in] topIndex - index korena podstromu (casti heapu), ktory sa ma opravit
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        Podstromy prvku s indexom 'topIndex' splnaju podmienky heap (podstromy, ktorych korene su priamy nasledovnici uzla s indexom 'topIndex').
        'data' ukazuje na platne pole
        'topIndex' moze mat lubovolnu hodnotu
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        Podstrom, ktoreho koren ma index 'topIndex' splna podmienku heap.

    PRIKLADY:
        vstup:  data = {55, 20, 10, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140}, topIndex = 0, length = 15
        vystup: data = {10, 20, 50, 30, 40, 55, 60, 70, 80, 90, 100, 110, 120, 130, 140}

        vstup:  data = {100, 8, 2, 1, 0, 5, 6, 7, 4, 2, 3, 11, 12, 13, 14, 15, 16, 17}, topIndex = 1, length = 18
        vystup: data = {100, 0, 2, 1, 2, 5, 6, 7, 4, 8, 3, 11, 12, 13, 14, 15, 16, 17}
*/
void siftDown(int data[], const size_t topIndex, const size_t length)
{
    size_t s = topIndex;
    size_t l = 2*topIndex+1;
    size_t r = 2*topIndex+2;
    if(l < length && data[l] < data[s])
        s = l;
    if(r < length && data[r] < data[s])
        s = r;
    if(s != topIndex){
        swap(data[topIndex], data[s]);
        siftDown(data, s, length);
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori heap na poli 'data' preusporiadanim prvkov.
    Verzia heap-u je Min-heap (hodnota kazdeho uzla je mensia alebo rovna ako hodnoty vsetkych jeho nasledovnikov).
    Pouzite algoritmus sift down.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia preusporiada, aby bolo heap-om
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        'data' je heap-om

    PRIKLAD:
        vstup:  data = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6}, length = 11
        vystup: data = {1, 2, 3, 2, 2, 5, 7, 4, 2, 8, 6}
*/
void buildHeapSiftDown(int data[], const size_t length)
{
    for(int i = length/2-1; i>=0;i--)
        siftDown(data, i, length);
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia preusporiada pole 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus heap sort.

    PARAMETRE:
        [in,out] data - pole, ktore funkcia usporiada
        [in] length - dlzka pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        Pole 'data' je usporiadane

    PRIKLAD:
        vstup:  data = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6}, length = 11
        vystup: data = {8, 7, 6, 5, 4, 3, 2, 2, 2, 2, 1}
*/
void heapSort(int data[], const size_t length)
{
    for(int i = length/2-1; i>=0; i--)
        siftDown(data, i, length);
    for(int i = length-1; i>=0; i--){
        swap(data[0], data[i]);
        siftDown(data, 0, i);
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    //1. int data[] = {3, 4, 10, 5, 5, 11, 15, 7, 8, 9, 10, 14,  8, 1, 2};int len = sizeof(data)/sizeof(data[0]);size_t addIndex = 12;siftUp(data, addIndex);printArray(data, len);
    //2. int data[] = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};size_t lenght = 11;buildHeapSiftUp(data, lenght);int len = sizeof(data)/sizeof(data[0]);printArray(data, len);


    /*int data[] = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};
    int len = sizeof(data)/sizeof(data[0]);
    size_t topIndex = 1;
    size_t lenght = 11;
    heapSort(data, len);
    printArray(data, len);*/

    return 0;
}
