/*
 * decorator.hpp
 *
 *  Created on: 2016Äê9ÔÂ1ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#ifndef DECORATOR_HPP_
#define DECORATOR_HPP_

#include <string>

using namespace std;

class Beverage {
public:
    Beverage();
    virtual ~Beverage() {
    }

    virtual string getDescription() = 0;
    virtual float cost() = 0;
private:
    string mDescription;
};

class CondimentDecorator: public Beverage {
public:
    virtual string getDescription() = 0;
private:
    string mDescription;
};

class Espresso: public Beverage {
public:
    Espresso();
    float cost();
    string getDescription();

private:
    string mDescription;
};

class HouseBlend: public Beverage {
public:
    HouseBlend();
    float cost();

private:
    string mDescription;
};

class Mocha: public CondimentDecorator {
public:
    Mocha(Beverage *pBererage);
    string getDescription();
    float cost();
private:
    Beverage *mpBeverage;
};

class Soy: public CondimentDecorator {
public:
    Soy(Beverage *pBererage);
    string getDescription();
    float cost();
private:
    Beverage *mpBeverage;
};



#endif /* DECORATOR_HPP_ */

