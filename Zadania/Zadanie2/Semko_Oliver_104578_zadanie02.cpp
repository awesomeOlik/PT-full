/*
Meno a priezvisko: Oliver Semko

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie02.cpp (pouzite vase udaje bez diakritiky).
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
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};


//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na zaciatok zoznamu

    PRIKLADY:
        list={} a val=0 ... zoznam po vykonani funkcie ... {0}
        list={-3} a val=1 ... zoznam po vykonani funkcie ... {1,-3}
        list={6,6,6,8} a val=10 ... zoznam po vykonani funkcie ... {10,6,6,6,8}
*/
Node * vytvorNode(const int val){
    return new Node{val, nullptr};
}

void prependNode(List* list, const int val) {
	Node * nwNode = vytvorNode(val);
	nwNode->next = list->first;
	list->first = nwNode;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na koniec zoznamu

    PRIKLADY:
        list={} a val=7 ... zoznam po vykonani funkcie ... {7}
        list={0} a val=1 ... zoznam po vykonani funkcie ... {0,1}
        list={1,2,3,4,5} a val=6 ... zoznam po vykonani funkcie ... {1,2,3,4,5,6}
*/

void appendNode(List* list, const int val) {
    Node * nwNode = vytvorNode(val);
    if(!list->first)
        list->first = nwNode;
    else{
        Node * pom = list->first;
        while(pom->next){
            pom = pom->next;
        }
    pom->next = nwNode;
    }

}

void printList(const List * list){
    Node * pom = list ->first;
    while(pom){
        std::cout << pom->data << " ";
        pom = pom->next;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),
    ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.

    PARAMETRE:
        [in] data - vstupne pole cisiel
        [in] n - dlzka vstupneho pola

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci vsetky hodnoty zo vstupneho pola 'data' (v zachovanom poradi).
        V pripade prazdneho pola (dlzka 0), funkcia vrati prazdny zoznam (prazdny zoznam je taky, kde smernik 'first'
        ukazuje na 'nullptr'). V pripade neplatnej dlzky (ak je parameter 'n' zaporny), funkcia vrati 'nullptr'.

    PRIKLADY:
        data={1} a n=1 ... vrati zoznam ... {1}
        data={7,6,41,2} a n=4 ... vrati zoznam ... {7,6,41,2}
        data={3,2,1} a n=0 ... vrati zoznam ... {}
        data={6,3,9,10} a n=-7 ... vrati ... 'nullptr'
*/
List* createListFromArray(const int* data, const int n) {



	return nullptr;// tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'. Symetricky zoznam ma
    tvar 0,1,2,...val...2,1,0.

    PARAMETRE:
        [in] val - hodnota uzla podla, ktoreho sa vytvori novy symetricky zretazeny zoznam (uzol v strede zoznamu).

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci prvky v takom poradi, aby bol symetricky. V pripade 'val'<0, funkcia vrati
        'nullptr'.

    PRIKLADY:
        val=-31 ... vrati ... nullptr
        val=0 ... vrati zoznam ... {0}
        val=1 ... vrati zoznam ... {0,1,0}
        val=2 ... vrati zoznam ... {0,1,2,1,0}
        val=3 ... vrati zoznam ... {0,1,2,3,2,1,0}
        val=4 ... vrati zoznam ... {0,1,2,3,4,3,2,1,0}
        val=6 ... vrati zoznam ... {0,1,2,3,4,5,6,5,4,3,2,1,0}
*/

List* createSymmetricList(const int val) {
    if(val<0)
        return nullptr;
    Node* head = nullptr;
    List * list = new List;
    Node* nwNode = new Node;
    nwNode->data = 0;
    nwNode->next = head;
    head = nwNode;
    int i;
    for(i=0;i<=val;i++){
        Node* pom= new Node;
        nwNode->next = pom;
        pom->data = i;
        pom->next = nullptr;
        nwNode=pom;
    }
    for(i=val;i>0;i--){
        Node* pom= new Node;
        nwNode->next = pom;
        pom->data = i-1;
        pom->next = nullptr;
        nwNode=pom;
    }

    //printList(list);
	return list; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    RETURN:
        Result::SUCCESS, ak bol prvy uzol vymazany
        Result::FAILURE, ak nebol prvy uzol vymazany (vstupny zoznam bol prazdny)

    PRIKLADY:
        list={} ... funkcia vrati Result::FAILURE
        list={5} ... zoznam po vykonani funkcie ... {} a vrati Result::SUCCESS
        list={10,10,10} ... zoznam po vykonani funkcie ... {10,10} a vrati Result::SUCCESS
        list={3,2,1} ... zoznam po vykonani funkcie ... {2,1} a vrati Result::SUCCESS
*/

Result removeFirstNode(List* list) {
    if(list->first){
        Node * pom = list->first->next;
        delete list->first;
        list->first = pom;
    }
    else{
        return Result::FAILURE;

    }

    return Result::SUCCESS;// tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla, ktory sa hlada

    RETURN:
        Funkcia vrati prvy uzol, ktory obsahuje hodnotu 'val'. Ak sa taky uzol v zozname nenachadza alebo je vstupny
        zoznam prazdny, vtedy funkcia vrati 'nullptr'.

    PRIKLADY:
        list={}, val=10 ... funkcia vrati 'nullptr'
        list={2}, val=3 ... funkcia vrati 'nullptr'
        list={1,2,3,4,5,6}, val=-1 ... funkcia vrati 'nullptr'
        list={1}, val=1 ... funkcia vrati uzol s hodnotou 1
        list={5,9,18}, val=9 ... funkcia vrati uzol s hodnotou 9
*/

Node* findNodeInList(List* list, const int val) {
    Node *pom = list->first;
    while (pom) {
        if (pom->data == val) {
            return pom;
        }
        else
            pom = pom->next;
    }
	return nullptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
    rovnake hodnoty uzlov v rovnakom poradi).

    PARAMETRE:
        [in] list1 - prvy zretazeny zoznam
        [in] list2 - druhy zretazeny zoznam

    RETURN:
        'true' - ak su vstupne zoznamy rovnake
        'false' - ak vstupne zoznamy nie su rovnake

    PRIKLADY:
        list1={1}
        list2={}
        Funkcia vrati 'false'.

        list1={}
        list2={5,3}
        Funkcia vrati 'false'.

        list1={}
        list2={}
        Funkcia vrati 'true'.

        list1={1}
        list2={1}
        Funkcia vrati 'true'.

        list1={4,-9,2}
        list2={4,-9,2}
        Funkcia vrati 'true'.

        list1={3,2,1}
        list2={1,2,3}
        Funkcia vrati 'false'.

        list1={2}
        list2={7,4,5}
        Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
    Node *pom1=list1->first;
    Node *pom2=list2->first;
    while(pom1!=nullptr && pom2!=nullptr)
    {
        if(pom1->data != pom2->data)
            return false;
        pom1 = pom1->next;
        pom2 = pom2->next;
    }
    return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam prekopirovanim vsetkych hodnot uzlov vstupneho zoznamu 'list' v obratenom
    poradi.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam

    RETURN:
        Zretazeny oznam, ktory vznikne prekopirovanim hodnot uzlov vstupneho zoznamu 'list' v obratenom poradi.

    PRIKLADY:
        list={} ... funkcia vrati ... {} t.j. prazdny zoznam
        list={1} ... funkcia vrati ... {1}
        list={5,6} ... funkcia vrati ... {6,5}
        list={8,14,2,3} ... funkcia vrati ... {3,2,14,8}
*/

List* copyListReverse(List* list) {
    List * list2 = new List;
    list2->first = nullptr;
    Node *nwNode=list->first;
    Node *pred=nullptr;
    Node *po=nullptr;
    while(nwNode != nullptr)
    {
        po = nwNode->next;
        nwNode->next = pred;
        pred = nwNode;
        nwNode = po;
    }
    list2->first = pred;
	return list2; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyhlada predchodcu zadaneho uzla 'node' vo vstupnom zretazenom zozname 'list'. Uzol 'node' je vzdy
    existujucim uzlom vstupneho zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] node - uzol zretazeneho zoznamu 'list', ktoreho predchodcu hladame

    RETURN:
        Uzol, ktory je predchodcom uzla 'node' v zozname 'list'. V pripade hladania predchodcu prveho uzla zoznamu,
        funkcia vrati 'nullptr'.

    PRIKLADY:
        list={4}
        node=4
        Funkcia vrati 'nullptr'.

        list={1,2,3,4,5}
        node=1
        Funkcia vrati 'nullptr'.

        list={-2,-3,56,4,41}
        node=-3
        Funkcia vrati uzol s hodnotou -2.

        list={10,54,69,82,6}
        node=6
        Funkcia vrati uzol s hodnotou 82.
*/

Node* findPreviousNode(List* list, Node* node) {
    list->first = nullptr;
    Node *nwNode = list->first;
    Node *pred = nullptr;
    if(nwNode==node)
        return nullptr;
    else{
        pred = nwNode;
        nwNode = nwNode->next;
        while(nwNode != nullptr)
        {
            if(nwNode == node)
                return pred;
            pred =nwNode;
            nwNode = nwNode->next;
        }
    }
	return nullptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zduplikuje vsetky uzly vstupneho zoznamu 'list', ktore obsahuju kladnu hodnotu.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    PRIKLADY:
        list={} ... po vykonani funkcie ... {}
        list={3} ... po vykonani funkcie ... {3,3}
        list={-1,1} ... po vykonani funkcie ... {-1,1,1}
        list={-8,-9,-13} ... po vykonani funkcie ... {-8,-9,-13}
        list={1,0,-2,3,-4} ... po vykonani funkcie ... {1,1,0,-2,3,3,-4}
*/

void duplicatePositiveNodes(List* list) {

}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main(int argc, char** argv) {

    /*List * list = new List;
    list->first = nullptr;*/
    /*List * list1 = new List;
    list1->first = nullptr;
    List * list2 = new List;
    list2->first = nullptr;*/
    //1. prependNode(list, 2);
    //2. appendNode(list, 2);
    //3. int data[] = {3, 4, 58};int n = sizeof(data)/sizeof(data[0]);createListFromArray(data, n); //-------->COSI ZLE
    //5. removeFirstNode(list);
    //6. findNodeInList(list, 3);
    //7. areListsEqual(list1, list2);
    //4. createSymmetricList(6);

    return 0;
}
