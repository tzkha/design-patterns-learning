#include "Country.h"

class Country;

class WorldGovt : public MediatorOrg {
public:
    void declare(string msg, Country* country, string name = string()) override;
};

class Revolution : public MediatorOrg {
public:
    void declare(string msg, Country* country, string name = string()) override;
};