#include <iostream>

// N'a pas été réalisé avec QT

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    size_t capacity;
    int dernier;
};


void initialise(Liste* liste)
{
    liste->premier = NULL;
}

bool est_vide(const Liste* liste)
{
    return liste->premier == NULL;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* newnoeud = (Noeud*)calloc(sizeof(Noeud), 1);
    newnoeud->donnee = valeur;
    newnoeud->suivant = liste->premier;
    liste->premier = newnoeud;
}

void affiche(const Liste* liste)
{
    Noeud* var = liste->premier;
    for(var; var != NULL; var = var->suivant) {
        cout << var->donnee<< ' ';
    }
    cout << endl;
}

int recupere(const Liste* liste, int n)
{
    int compteur=0;
    Noeud* var = liste->premier;

    for(var; var != NULL; var = var->suivant) {
        if (compteur == n){
            return(var->donnee);
        }
        compteur+=1;
    }
    
    return 0;
}

int cherche(const Liste* liste, int valeur)
{   
    int compteur=0;
    Noeud* var = liste->premier;

    for(var; var != NULL; var = var->suivant) {
        if (var->donnee==valeur){
            return(compteur);
        }
        compteur+=1;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    int compteur=0;
    Noeud* var = liste->premier;

    for(var; var != NULL; var = var->suivant) {
        if (compteur == n){
            var->donnee=valeur;
            return;
        }
        compteur+=1;
    }
}

void initialise2(DynaTableau* tableau, int capacite)
{
    tableau->donnees=new int(capacite);
    tableau->capacity = capacite;
    tableau->dernier= 0;
}

bool est_vide2(const DynaTableau* tableau)
{
    return tableau->dernier == 0;
}


void ajoute2(DynaTableau* tableau, int valeur)
{
    if (tableau->dernier == tableau->capacity){
        int *newint = new int;
        *newint = valeur;
        tableau->donnees[tableau->dernier]=*newint;
        tableau->capacity+=1;
    }
    else{
        tableau->donnees[tableau->dernier]=valeur;
    }
    
    tableau->dernier+=1;
}

void affiche2(const DynaTableau* tableau)
{

    for(int compteur=0; compteur< tableau->dernier; compteur++) {
        cout <<tableau->donnees[compteur]<< ' ';
    }
    cout << endl;
}

int recupere2(const DynaTableau* tableau, int n)
{
    if (n>tableau->dernier){
        cout << "Index out of bound"<<endl;
        return(-1);
    }
    else{
        return(tableau->donnees[n]);
    }
}

int cherche2(const DynaTableau* tableau, int valeur)
    {  
    for(int compteur=0; compteur < tableau->dernier; compteur++) {
        if (tableau->donnees[compteur]==valeur){
            return(compteur);
        }
    }
    return -1;
}

void stocke2(DynaTableau* tableau, int n, int valeur)
{
    if (n>tableau->dernier){
        cout << "Index out of bound"<<endl;
    }
    else{
        tableau->donnees[n]=valeur;
    }
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud *newnoeud= new Noeud;
    newnoeud->donnee=valeur; 
    newnoeud->suivant=NULL;

    if (liste->premier != NULL){
        Noeud *var=liste->premier;
        while(var->suivant != NULL){
            var= var->suivant;
        }
        var->suivant=newnoeud;
    }
    else{
        liste->premier=newnoeud;
    }
}
//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int varsave=liste->premier->donnee;
    if (liste->premier !=NULL){
        Noeud *supp = liste->premier;
        liste->premier=supp->suivant;
        delete(supp);

    }
    else{
        exit(-1);
    }
    return varsave;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud *newnoeud= new Noeud;

    if (liste->premier != NULL){
        newnoeud->donnee=valeur; 
        newnoeud->suivant=liste->premier;
        liste->premier=newnoeud;
    }
    else{
        newnoeud->donnee=valeur; 
        newnoeud->suivant=NULL;
        liste->premier=newnoeud;
    }
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    int varsave=liste->premier->donnee;
    if (liste->premier !=NULL){
        Noeud *supp = liste->premier;
        liste->premier=supp->suivant;
        delete(supp);

    }
    else{
        exit(-1);
    }
    return varsave;
}

int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise2(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide2(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute2(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide2(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche2(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere2(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche2(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke2(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche2(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
    std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
