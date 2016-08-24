/*
 * observer.h
 *
 *  Created on: 2016Äê8ÔÂ23ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <list>

using namespace std;

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void update(float temp, float humidity, float pressure) {}
};

class WeatherData {
public:
    WeatherData() {}
    virtual ~WeatherData() {}
    void registerObeserver(Observer *observer);
    void removeObserver(Observer *observer);
    void setMeasurements(float temp, float humidity, float pressure);
private:
    void measurementChanged();
    void notifyObserver();

private:
    float mTemperature;
    float mHumidity;
    float mPressure;

    list<Observer*> mObservers;
};

class CurrentConditionDisplay :public Observer
{
public:
    CurrentConditionDisplay(WeatherData *pWeatherData);
    void update(float temp, float humidity, float pressure);
private:
    void display();
private:
    float mTemperature, mHumidity, mPressure;
    WeatherData *mpWeatherData;
};

class StatisticsDisplay :public Observer
{
public:
    StatisticsDisplay(WeatherData *pWeatherData);
    void update(float temp, float humidity, float pressure);
private:
    void display();
private:
    float mTemperature, mHumidity, mPressure;
    int mUpdateNum;
    WeatherData *mpWeatherData;
};



#endif /* OBSERVER_H_ */
