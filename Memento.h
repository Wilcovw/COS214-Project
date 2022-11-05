#ifndef MEMENTO_H
#define MEMENTO_H
#include <vector>

using namespace std;
class WarMap;
class WarPhase;
class Country;
class Communication;

class Memento{
private:
	friend class WarPhase;
	/**
	 * @brief Construct a new Memento object
	 * 
	 * @param allCountries All countries to sotre
	 * @param c The communication network to store
	 * @param map The map to store
	 */
	Memento(WarPhase* currentPhase);
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