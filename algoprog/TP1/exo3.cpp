#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);


int search(int value, Array& toSort, int size){
    Context _("search", value, size); // do not care about this, it allow the display of call stack

    // your code
    if (size == 0){
        return 0;
    }
    else {
        if (toSort[size-1]==value){
            return size-1;
        }
        else {
            return (search(value, toSort, size-1));
        }
    }
    // check the last cell and if it does not correspond
    // then consider a smaller array when recalling search
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new SearchWindow(search); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}




