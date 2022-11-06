#ifndef MEMENTO_H
#define MEMENTO_H
#include <vector>

using namespace std;
class WarPhase;
class Memento
{

/**
 * @brief Stores a phase of war in warphase. This is in order to go back to a previous state
 */
class Memento
{
private:
	friend class WarPhase;
	/**
	 * @brief Construct a new Memento object
	 *
	 * @param allCountries All countries to sotre
	 *
	 * @param allCountries All countries to store
	 * @param c The communication network to store
	 * @param map The map to store
	 */
	Memento(WarPhase *currentPhase);
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