#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return 1 + nodeIndex * 2;
}

int Heap::rightChild(int nodeIndex)
{
    return (1 + nodeIndex) * 2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
    (*this)[i] = value;
    while (i > 0 && (*this)[i] > (*this)[(i - 1) / 2])
    {
        swap((*this)[i], (*this)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    // use (*this)[i] or this->get(i) to get a value at index
    int i = nodeIndex;
    int left = this->leftChild(nodeIndex);
    int right = this->rightChild(nodeIndex);
    int largest = nodeIndex;
    if (right < heapSize && this->get(right) > this->get(largest))
    {
        largest = right;
    }
    if (left < heapSize && this->get(left) > this->get(largest))
    {
        largest = left;
    }
    if (largest != i)
    {
        swap(this->get(i), this->get(largest));
        heapify(heapSize, largest);
    }
}

void Heap::buildHeap(Array& numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        this->insertHeapNode(i, numbers.get(i));
    }
}

void Heap::heapSort()
{
   for (int i = this->size() - 1; i >=0; --i)
   {
       swap(this->get(0), this->get(i));
       this->heapify(i, 0);
   }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
