#include <iostream>
#include "Country.h"
#include "Mediator.h"
using namespace std;

int main(){
    WorldGovt* worldGovt = new WorldGovt();
    Alabasta* alabasta = new Alabasta(worldGovt);
    Dressrosa* dressrosa = new Dressrosa(worldGovt);
    worldGovt->addMember(alabasta);
    worldGovt->addMember(dressrosa);
    alabasta->declare("I am alabasta", dressrosa->getName());
    dressrosa->declare("I am dressrosa", alabasta->getName());
    cout << "--------------------------" << endl;
    Revolution* revolution = new Revolution();
    Kamabaka* kamabaka = new Kamabaka(revolution);
    LuLusia* lulusia = new LuLusia(revolution);
    revolution->addMember(kamabaka);
    revolution->addMember(lulusia);
    lulusia->declare("I am lulusia", kamabaka->getName());
    delete worldGovt;
    delete alabasta;
    delete dressrosa;
    delete revolution;
    delete lulusia;
    delete kamabaka;
    return 0;
}