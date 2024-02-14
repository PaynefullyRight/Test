#include <iostream>
using namespace std;

int main()
{
	int health = 0;
	int baseDmg;
	int defenseIn = 100;
	double defense;
	double damage;

	cout << "Program runs until health reaches 0" << endl << " " << endl;

	while (health <= 0) {	// health entry loop
		cout << "Enter positive integer for amount of health" << endl << " " << endl;
		cin >> health;
		if (!cin.good() || health <= 0) {
			cout << "Invalid entry. Please enter a positive integer" << endl << " " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	while (defenseIn <= -1 || defenseIn >= 100) { // defense entry loop
		cout << "Enter an integer between 0 and 99 for percentage of defense" << endl << " " << endl;
		cin >> defenseIn;
		if (!cin.good() || defenseIn < 0 || defenseIn > 99) {
			cout << "Invalid entry. Please enter a number between 0 and 99" << endl << " " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			defenseIn = 100;
		}
	}

	defense = (100 - defenseIn) * 0.01; // defense equals percent of damage that passes through defense

	cout << "Stats set to:" << endl
	 	 << "Health: " << health << endl
		 << "Defense: " << defenseIn << endl << " " << endl;

	while (health > 0) { // damage loop
		cout << "Enter positive integer for base damage" << endl << " " << endl;
		cin >> baseDmg;
		if (cin.good()) {
			damage = baseDmg * defense;
			health = health - damage;
			if (health < 0) {
				health = 0;
			}
		cout << "Damage dealt: " << damage << endl;
		cout << "Remaining health: " << health << endl << " " << endl;
		}
		else {
			cout << "Invalid entry. Please enter a positive integer" << endl << " " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (health == 0) {
		cout << "Enemy defeated!";
	}
}
