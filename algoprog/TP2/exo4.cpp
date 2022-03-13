#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;



void recursivQuickSort(Array& toSort, int size){
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if (size==1||size==0){
        return;
    }
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
    int lowerSize = 0, greaterSize = 0; // effectives sizes
    int pivot = toSort[0];
    int size2=0;

// split
    for (int x=1;x<size;x++){
        if (toSort[x]>pivot){
            greaterArray.set(greaterSize,toSort[x]);
            greaterSize+=1;
        }
        else{
            lowerArray.set(lowerSize,toSort[x]);
            lowerSize+=1;
        }
    }
// recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray,lowerSize);
    recursivQuickSort(greaterArray,greaterSize);

// merge
    for (int t=0;t<lowerSize;t++){
        toSort.set(size2,lowerArray[t]);
        size2+=1;
    }

    toSort.set(size2,pivot);
    size2 +=1;

    for (int t=0;t<greaterSize;t++){
        toSort.set(size2,greaterArray[t]);
        size2+=1;
    }

}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
