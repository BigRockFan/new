#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//Header begins here

class entity 
{
private:
	int attack;
	int magic;
	int health;
	bool energy[2];
	string name;
public:
	entity(int att, int heal, int mag, string name)
	{
		attack = att;
		magic = mag;
		health = heal;
		energy[0] = 0, energy[1] = 0;
		this->name = name;
	}
	entity(int att, int heal, string name)
	{
		attack = att;
		health = heal;
		energy[0] = 0, energy[1] = 0;
		this->name = name;
	}

public:
	int GetHealth();
	int GetAttack();
	int GetMagic();
	string GetName();
	void printbattle(entity);
	void printstats();
	void slash(entity*);
	void magicatt(entity*);
	int checkhealth();
	int checkcharging1();
	int checkcharging2();
	void charging();
	void charged();
	void chargereset();
};

int entity::GetHealth()
{
	return health;
}

int entity::GetAttack()
{
	return attack;
}

int entity::GetMagic()
{
	return magic;
}

string entity::GetName()
{
	return name;
}

void entity::printbattle(entity enemy)
{
	cout << "YOU: " << health << endl;
	cout << "ENEMY: " << enemy.GetHealth() << endl;
}
void entity::printstats()
{
	cout << "Attack: " << attack << endl;
	cout << "Magic: " << magic << endl;
	cout << "Health: " << health << endl;
}
void entity::slash(entity *enemy)
{
	(*enemy).health -= attack;
	cout << endl << name << " hit " << (*enemy).name << " for " << attack << " damage!\n";
}
void entity::magicatt(entity *enemy)
{
	(*enemy).health -= magic;
	cout << endl << name << " hit " << (*enemy).name << " for " << magic << " damage!\n";
}
int entity::checkhealth()
{
	if (health <= 0)
		return 0;
	else
		return 1;
}
int entity::checkcharging1()
{
	if (energy[0] == 1)
		return 1;
	else
		return 0;
}
int entity::checkcharging2()
{
	if (energy[1] == 1)
		return 1;
	else
		return 0;
}
void entity::charging()
{
	cout << endl << name << " is charging!\n";
	energy[0] = 1;
}

void entity::charged()
{
	cout << endl << name << " finished charging!\n";
	energy[1] = 1;
}

void entity::chargereset()
{
	energy[0] = 0;
	energy[1] = 0;
}

//Header ends here
#endif
