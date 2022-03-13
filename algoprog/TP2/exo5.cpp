#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
    // stop statement = condition + return (return stop the function even if it does not return anything)

    // initialisation
    int taille = origin.size();
    Array& first = w->newArray(taille/2);
    Array& second = w->newArray(taille-first.size());
    int fsize=taille/2;
    int ssize=taille-fsize;

    // condition d'arrêt
    if (taille> 1){
        // split
            for (int i=0; i<taille/2; i++){
                first.set(i,origin[i]);
            }
            for (int j=taille/2;j<taille; j++){
                second.set(j-taille/2,origin[j]);
            }

        splitAndMerge(first);
        splitAndMerge(second);


        if (taille==2){
            if (origin[0]>origin[1]){
                origin.swap(0,1);
                return ;
            }
        }
        if (taille == 1){
            return ;
        }

        // recursiv splitAndMerge of lowerArray and greaterArray
        int compteur =0;
        int i=0;
        int j=0;
        // merge
        while (i<fsize && j<ssize){
            if (first[i]<=second[j]){
                origin[compteur]=first[i];
                i+=1;
            }
            else {
                origin[compteur] = second[j];
                j+=1;
            }
            compteur+=1;
        }
        while (i<fsize){
            origin[compteur]=first[i];
            i+=1;
            compteur+=1;
        }
        while (j<ssize){
            origin[compteur]=second[j];
            j+=1;
            compteur+=1;
        }
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
    w->show();

    return a.exec();
}
