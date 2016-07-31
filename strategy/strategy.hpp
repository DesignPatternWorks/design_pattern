/*
 * strategy.hpp
 *
 *  Created on: 2016Äê7ÔÂ31ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

enum FLY_TYPE {
    FLY_WITH_WINGS,
    FLY_NO_WAY,
    FLY_LIKE_ROCKET,
};

class FlyBehavoir {
public:
    virtual void fly() = 0;
};

class duck {
public:
    duck(enum FLY_TYPE flyType);
    virtual ~duck();

    void performFly();

private:
    FlyBehavoir *flyBehavior;
};

class FlyWithWings: public FlyBehavoir {
public:
    void fly();
};

class FlyNoWay: public FlyBehavoir {
public:
    void fly();
};

class FlyLikeRocket: public FlyBehavoir {
public:
    void fly();
};

class MallardDuck: public duck {
public:
    MallardDuck();
};
#endif /* STRATEGY_HPP_ */

