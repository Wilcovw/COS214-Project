#ifndef MEMENTO_H
#define MEMENTO_H
#include <vector>

using namespace std;
class WarMap;
class WarPhase;
class Country;
class Communication;
class Memento
{
private:
	friend class WarEngine;
	/**
	 * @brief Construct a new Memento object
	 * 
	 * @param allCountries All countries to sotre
	 * @param c The communication network to store
	 * @param map The map to store
	 */
	Memento(vector<Country *> allCountries, Communication *c, WarMap *map);
	/**
	 * @brief Phase of the warphase to store
	 * 
	 */
	WarPhase *warphase;

public:
	/**
	 * @brief Destroy the Memento object
	 * 
	 */
	virtual ~Memento();
};

#endif