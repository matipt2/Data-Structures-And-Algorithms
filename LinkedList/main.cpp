typedef int element;
typedef  struct cell
{
    element element;
    cell * next;
};

class Lista
{
protected:
    cell * header; // głowa listy
public:
    Lista();    //konstruktor
    ~Lista();  //destruktor
    void Insert(element x, cell * p); // wstawia element x na pozycję next komórki o wskaźniku p
    // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
    void Delete(cell * p); // usuwa komórkę z pozycji next komórki o wskaźniku p
    element Retrieve(cell * p); // zwraca element komórki o wskaźniku p
    cell * Locate(element x); // zwraca wskaźnik do pierwszej komórki z elementem x
    cell * First(); // zwraca wskaźnik do pierwszej komórki na liście
    cell * Next(cell * p); // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
    cell * Previous(cell * p); // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
    cell * Last(); // zwraca wskaźnik do ostatniej komórki na liście

    void print(); // wyświetla wszystkie elementy listy
};