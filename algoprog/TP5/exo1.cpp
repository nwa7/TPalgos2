#include <tp5.h>
#include <stdio.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

/***
#define ARRAY_SIZE 40
int hash(char* string)
{
    int i = 0;
    int hash_value = 0;
    while(string[i] != '\0')
    {
        hash_value += (int)string[i];
        i++;
    }
    return hash_value % ARRAY_SIZE;
}
***/

int HashTable::hash(std::string element)
{
    int hash_value =  element[0];
    // use this->size() to get HashTable size
    return hash_value%(this->size());
}

void HashTable::insert(std::string element){
    int hash_value= hash(element);
    this->set(hash_value, element);
    // use (*this)[i] or this->get(i) to get a value at index i
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
    for (int x = 0; x<namesCount; x++){
        table.insert(names[x]);
    }


}

bool HashTable::contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    int hash_value= hash(element);
    if ((*this)[hash_value] == element){
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
