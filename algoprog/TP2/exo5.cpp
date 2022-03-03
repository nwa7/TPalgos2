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
    int pivot = toSort[0];

	// split
    for (int x=0;x<taille;x++){
		for (int i=0; i<taille/2; i++){
			first.insert(toSort[i],i)
		}
		for (int i2=taille/2;i2<taille; i++){
			second.insert(toSort[i2],taille/2-i2));
		}
    }
	// recursiv splitAndMerge of lowerArray and greaterArray

	// merge
}

void merge(Array& first, Array& second, Array& result)
{

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
