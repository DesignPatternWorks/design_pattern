/*
 * strategy.cpp
 *
 *  Created on: 2016Äê7ÔÂ31ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#include <iostream>
#include "strategy.hpp"

using namespace std;

duck::duck(enum FLY_TYPE flyType) {
    // TODO Auto-generated constructor stub
    switch (flyType) {
        case FLY_WITH_WINGS:
            flyBehavior = new FlyWithWings();
            break;
        case FLY_LIKE_ROCKET:
            flyBehavior = new FlyLikeRocket();
            break;
        default:
            flyBehavior = new FlyNoWay();
            break;
    }
}

duck::~duck() {
    // TODO Auto-generated destructor stub
}

void duck::performFly() {
    flyBehavior->fly();
}

void FlyWithWings::fly() {
    cout << "I can fly with wings." << endl;
}

void FlyNoWay::fly() {
    cout << "I can not fly!" << endl;
}

void FlyLikeRocket::fly() {
    cout << "I fly like a rocket!" << endl;
}

MallardDuck::MallardDuck()
    :duck(FLY_WITH_WINGS)
{
}
