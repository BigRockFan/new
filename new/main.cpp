#include "entity.h"

int main()
{
	entity guy = *new entity(4, 12, 9, "Rohan"); //attack, health, magic, name
	entity minion = *new entity(2, 10, "Minion"); //attack, health, name
	int choice;
	guy.printbattle(minion);
	while (minion.checkhealth() == 1 && guy.checkhealth() == 1)
	{
		if (guy.checkcharging1() == 0)
		{
			cout << "\nYour Turn-\nWould you like to:\n1) Slash with your sword\n2) Attack with magic" << endl;
			cin >> choice;
			if (choice == 1)
			{
				guy.slash(&minion); 
				guy.printbattle(minion);
			}
			else if (choice == 2)
			{
				guy.charging();
			}
			else
			{
				cout << "Try again!" << endl;
				continue;
			}
		}
		else if (guy.checkcharging1() == 1 && guy.checkcharging2() == 0)
		{
			guy.charged();
		}
		else if (guy.checkcharging1() == 1 && guy.checkcharging2() == 1)
		{
			guy.magicatt(&minion);
			guy.chargereset();
		}
		cout << endl;
		cout << minion.GetName() << "'s turn-";
		minion.slash(&guy);
		guy.printbattle(minion);
	}

	return 0;
}