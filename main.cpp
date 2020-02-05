#include <iostream>
#include <list.h>

using namespace std;

int main()
{
    list* mylist = new list();
    for(int i = 0; i<10; i++)
    {
        mylist->add(i);
    }
    mylist->addToFront(-1);
    mylist->print();
    cout<<endl;
    cout<<mylist->getByIndex(4)->getData()<<endl<<endl;
    mylist->insertAt(12, 4);
    mylist->print();

    delete mylist;
    return 0;
}
