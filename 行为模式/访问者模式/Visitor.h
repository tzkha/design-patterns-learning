#pragma once
#include <iostream>
#include "Member.h"
using namespace std;

class MaleMember;
class FemaleMember;

class AbstractAction{
public:
    virtual void maleDoing(MaleMember* male) = 0;
    virtual void femaleDoing(FemaleMember* female) = 0;
    virtual ~AbstractAction(){}
};

class Anger : public AbstractAction{
public:
    void maleDoing(MaleMember* male) override;
    void femaleDoing(FemaleMember* female) override;
    void warning();
    void fight();
};

class Horror : public AbstractAction{
public:
    void maleDoing(MaleMember* male) override;
    void femaleDoing(FemaleMember* female) override;
    void help();
    void thinking();
};