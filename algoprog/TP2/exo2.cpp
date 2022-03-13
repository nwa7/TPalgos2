#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
    int taille = toSort.size();
    int taillesorted=1;
    Array& sorted=w->newArray(taille);
    sorted.set(0,toSort[0]);
    for (int x=1;x<taille;x++){
        for (int i=0;i<taillesorted+1;i++){
            if (i==taillesorted){
                sorted.insert(i,toSort[x]);
                taillesorted+=1;
                break;
            }
            else if (toSort[x]<sorted[i]){
                sorted.insert(i, toSort[x]);
                taillesorted+=1;
                break;
            }
        }
    }
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
