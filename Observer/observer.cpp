/*
 * observer.cpp
 *
 *  Created on: 2016Äê8ÔÂ24ÈÕ
 *      Author: Fantastic Mr.Fox
 */

#include "observer.h"
#include <iostream>

void WeatherData::registerObeserver(Observer *observer)
{
    mObservers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer)
{
    mObservers.remove(observer);
}

void WeatherData::notifyObserver()
{
    list<Observer*>::iterator it = mObservers.begin();
    while (it != mObservers.end()) {
        (*it)->update(mTemperature, mHumidity, mPressure);
        it++;
    }
}
void WeatherData::measurementChanged()
{
    notifyObserver();
}
void WeatherData::setMeasurements(float temp, float humidity, float pressure)
{
    mTemperature = temp;
    mHumidity = humidity;
    mPressure = pressure;
    measurementChanged();
}

CurrentConditionDisplay::CurrentConditionDisplay(WeatherData *pWeatherData)
:mpWeatherData(pWeatherData)
{
    mpWeatherData->registerObeserver(this);
}

void CurrentConditionDisplay::update(float temp, float humidity, float pressure)
{
    mTemperature = temp;
    mHumidity = humidity;
    mPressure = pressure;
    display();
}

void CurrentConditionDisplay::display()
{
    cout << "Current temperature: " << mTemperature << " humidity: " << mHumidity
         << " pressure: " << mPressure << endl;
}


StatisticsDisplay::StatisticsDisplay(WeatherData *pWeatherData)
:mTemperature(0),
 mHumidity(0),
 mPressure(0),
 mUpdateNum(0),
 mpWeatherData(pWeatherData)
{
    mpWeatherData->registerObeserver(this);
}
void StatisticsDisplay::update(float temp, float humidity, float pressure)
{
    mTemperature += temp;
    mHumidity += humidity;
    mPressure += pressure;
    mUpdateNum++;
    display();
}

void StatisticsDisplay::display()
{
    cout << "Average Statistics: " << endl;
    cout << "-----------------------------" << endl;
    cout << "T: " << mTemperature/mUpdateNum << " H: " << mHumidity/mUpdateNum
         << " P: " << mPressure/mUpdateNum << endl << endl;;
}

int main()
{
    WeatherData *pWeatherData = new WeatherData();
    CurrentConditionDisplay *currentDisplay = new CurrentConditionDisplay(pWeatherData);
    StatisticsDisplay *statisticsDisplay = new StatisticsDisplay(pWeatherData);

    pWeatherData->setMeasurements(40, 65, 30);
    pWeatherData->setMeasurements(42, 60, 32);
    pWeatherData->setMeasurements(45, 62, 27);

    delete pWeatherData;
    delete currentDisplay;
    delete statisticsDisplay;
}
