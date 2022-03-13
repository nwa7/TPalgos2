#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
    int taille = toSort.size();
    for (int x=0; x<taille;x++){
        int min=toSort.get(x);
        int indice=x;
        for (int i=x+1; i<taille; i++){
            if (min>toSort.get(i)){
                min=toSort.get(i);
                indice=i;
            }
        }
    toSort.swap(x,indice);
    }

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
