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

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    return 0;
}

int main()
{
    Liste liste;
    initialise(&liste);
    cout<<est_vide(&liste)<<endl;
    ajoute(&liste,5);
    ajoute(&liste,6);
    ajoute(&liste,7);
    affiche(&liste);
    cout <<recupere(&liste,2)<<endl;
    cout<<cherche(&liste, 5)<<endl;
    stocke(&liste, 2,8);
    cout<<cherche(&liste, 8)<<endl;
}
