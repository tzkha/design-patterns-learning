#include "Observer.h"
#include "NewAgency.h"

int main(){
    Morgans* ms = new Morgans;
    Gossip* gossip = new Gossip;
    Dragon* dragon = new Dragon("Dragon", ms);
    Shanks* shanks = new Shanks("Shanks", ms);
    Bartolomeo* bartolomeo = new Bartolomeo("Bartolomeo", gossip);
    ms->notify("aaaaaa");
    cout << "-----------------" << endl;
    gossip->notify("bbbbbb");
    delete ms;
    delete gossip;
    delete dragon;
    delete shanks;
    delete bartolomeo;
    return 0;
}