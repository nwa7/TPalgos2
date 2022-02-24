#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n
    if (n==0){
        return true;
    }
    else {
        Point newz;
        newz.x=(z.x)*(z.x)-(z.y)*(z.y);
        newz.y=2*(z.y)*(z.x);

        if (z.length()>2){
            return false;
        }

        else {
            isMandelbrot(z, n-1, point);
        }
    }
    // check length of z
    // if Mandelbrot, return 1 or n (check the difference)
    // otherwise, process the square of z and recall
    // isMandebrot
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



