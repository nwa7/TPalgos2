#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
    int taille = toSort.size();
    for (int x=0;x<taille-1;x++){
        if(toSort[x]>toSort[x+1]){
            toSort.swap(x,x+1);
            for (int i=x;i>0; i--){
                if (toSort[i]<toSort[i-1]){
                    toSort.swap(i,i-1);
                }

            }
        }

    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
