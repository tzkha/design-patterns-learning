#include "Sanji.h"
#include "State.h"
#include <vector>

int main(){
    Sanji* sanji = new Sanji;
    vector<int> data{7, 10, 12, 14, 16, 18, 22};
    for(const auto& item : data){
        sanji->setClock(item);
        sanji->working();
    }
    delete sanji;
    return 0;
}