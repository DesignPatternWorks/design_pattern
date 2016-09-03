/*
 * decorator.cpp
 *
 *  Created on: 2016Äê9ÔÂ1ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#include "decorator.hpp"
#include <iostream>

Beverage::Beverage() :
        mDescription("Unknown beverage")
{}

Espresso::Espresso() :
        mDescription("Espresso")
{}

string Espresso::getDescription()
{
    return mDescription;
}
float Espresso::cost()
{
    return 1.99;
}

HouseBlend::HouseBlend()
:mDescription("HouseBlend")
{}

float HouseBlend::cost()
{
    return 0.89;
}

Mocha::Mocha(Beverage *pBererage)
:mpBeverage(pBererage)
{}


string Mocha::getDescription()
{
    return mpBeverage->getDescription() + " Mocha";
}

float Mocha::cost()
{
    return mpBeverage->cost() + 0.2;
}

Soy::Soy(Beverage *pBererage)
:mpBeverage(pBererage)
{}


string Soy::getDescription()
{
    return mpBeverage->getDescription() + " Soy";
}

float Soy::cost()
{
    return mpBeverage->cost() + 0.1;
}



int main()
{
    Beverage *pBeverage = new Espresso();
    cout << pBeverage->getDescription() << " $" << pBeverage->cost() << endl;
    pBeverage = new Soy(pBeverage);
    cout << pBeverage->getDescription() << " $" << pBeverage->cost() << endl;
    pBeverage = new Mocha(pBeverage);
    pBeverage = new Mocha(pBeverage);
    cout << pBeverage->getDescription() << " $" << pBeverage->cost() << endl;
}
