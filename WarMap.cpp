#include "WarMap.h"

WarMap::WarMap()
{
}

WarMap::~WarMap()
{
	for (auto a : areasWT)
	{
		delete a;
	}
}

Area *WarMap::getArea(string name)
{
	for (auto a : areasWT)
	{
		if (a->getName() == name)
		{
			return a;
		}
	}
	return nullptr;
}

bool WarMap::isAccessible(Area *source, Area *destination)
{
	reset();

	if (source == nullptr || destination == nullptr)
	{
		return false;
	}
	return source->isAccessible(destination);
}

bool WarMap::isAccessible(Area *source, Area *destination, string type)
{
	reset();
	if (source == nullptr || destination == nullptr)
	{
		return false;
	}

	return source->isAccessible(destination, type);
}

bool WarMap::addEdge(Area *source, Area *destination, double distance, string type)
{
	if (source == nullptr || destination == nullptr)
	{
		return false;
	}

	Area *s = this->getArea(source->getName());
	Area *d = this->getArea(destination->getName());
	if (s == nullptr || d == nullptr)
	{
		return false;
	}
	Edge *e = new Edge(distance, type, source, destination);
	return s->addEdge(e);
}

bool WarMap::addArea(Area *a)
{
	list<Area *>::iterator it;

	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		if (*it == a)
		{
			return false;
		}
	}
	areasWT.push_back(a);
	return true;
}

void WarMap::reset()
{
	list<Area *>::iterator it;
	if (areasWT.size() == 0)
	{
		return;
	}
	for (auto a : areasWT)
	{
		a->visited = false;
	}
}

list<Area *> WarMap::getAreaList()
{
	return this->areasWT;
}

AreaIterator *WarMap::createAreaIterator()
{
	return new AreaIterator(this);
}

list<Area *>::iterator WarMap::begin()
{
	return areasWT.begin();
}

list<Area *>::iterator WarMap::end()
{
	return areasWT.end();
}

EdgeIterator *WarMap::createEdgeIterator()
{
	return new EdgeIterator(this);
}

list<Area *> WarMap::shortestPath(Area *source, Area *destination)
{
	list<Area *> ans;

	if (source == nullptr || destination == nullptr)
	{
		return ans;
	}

	if (isAccessible(source, destination) == false)
	{
		return ans;
	}

	for (auto a : areasWT)
	{
		a->setDist(INT_MAX);
		a->setPrev(nullptr);
	}

	list<Area *> toBeChecked;
	toBeChecked.push_back(source);
	source->setDist(0);
	while (toBeChecked.empty() == false)
	{
		Area *curr = toBeChecked.front();
		toBeChecked.pop_front();

		if (curr->getEdges().empty() == false)
		{

			for (auto e : curr->getEdges())
			{
				Area *v = e->getDestination();

				double NewDist = curr->getDist() + e->getDistance();

				if (NewDist < v->getDist())
				{
					v->setDist(NewDist);
					v->setPrev(curr);
					if (find(toBeChecked.begin(), toBeChecked.end(), v) == toBeChecked.end())
					{
						toBeChecked.push_back(v);
					}
				}
			}
		}
	}
	if (destination->getPrev() == nullptr)
	{
		return ans;
	}
	Area *node = destination;
	while (node != nullptr)
	{
		ans.push_back(node);
		node = node->getPrev();
	}
	ans.reverse();
	return ans;
}

list<Area *> WarMap::shortestPath(Area *source, Area *destination, string type)
{
	list<Area *> ans;

	if (source == nullptr || destination == nullptr)
	{
		return ans;
	}

	if (isAccessible(source, destination, type) == false)
	{
		return ans;
	}

	for (auto a : areasWT)
	{
		a->setDist(INT_MAX);
		a->setPrev(nullptr);
	}

	list<Area *> toBeChecked;
	toBeChecked.push_back(source);
	source->setDist(0);
	while (toBeChecked.empty() == false)
	{
		Area *curr = toBeChecked.front();
		toBeChecked.pop_front();

		if (curr->getEdges().empty() == false)
		{
			for (auto e : curr->getEdges())
			{
				double ans = e->getDistance();
				Area *v = e->getDestination();
				Country *control = v->getControllingCountry();
				list<Country *> allies = control->getAllies();
				if (destination == v)
				{
					if (type == "Harbour")
					{
						if (e->getType() == type)
						{

							double NewDist = curr->getDist() + ans;

							if (NewDist < v->getDist())
							{
								v->setDist(NewDist);
								v->setPrev(curr);
								if (find(toBeChecked.begin(), toBeChecked.end(), v) == toBeChecked.end())
								{
									toBeChecked.push_back(v);
								}
							}
						}
					}
					else
					{
						if (e->getType() != type)
						{
							ans *= 2;
						}
						double NewDist = curr->getDist() + ans;

						if (NewDist < v->getDist())
						{
							v->setDist(NewDist);
							v->setPrev(curr);
							if (find(toBeChecked.begin(), toBeChecked.end(), v) == toBeChecked.end())
							{
								toBeChecked.push_back(v);
							}
						}
					}
				}else if (find(allies.begin(), allies.end(), source->getControllingCountry()) != allies.end()){
					if (type == "Harbour")
					{
						if (e->getType() == type)
						{

							double NewDist = curr->getDist() + ans;

							if (NewDist < v->getDist())
							{
								v->setDist(NewDist);
								v->setPrev(curr);
								if (find(toBeChecked.begin(), toBeChecked.end(), v) == toBeChecked.end())
								{
									toBeChecked.push_back(v);
								}
							}
						}
					}
					else
					{
						if (e->getType() != type)
						{
							ans *= 2;
						}
						double NewDist = curr->getDist() + ans;

						if (NewDist < v->getDist())
						{
							v->setDist(NewDist);
							v->setPrev(curr);
							if (find(toBeChecked.begin(), toBeChecked.end(), v) == toBeChecked.end())
							{
								toBeChecked.push_back(v);
							}
						}
					}
				}
			}
		}
	}
	if (destination->getPrev() == nullptr)
	{
		return ans;
	}
	Area *node = destination;
	while (node != nullptr)
	{
		ans.push_back(node);
		node = node->getPrev();
	}
	ans.reverse();
	return ans;
}