#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Unicorn
{
	
private:

public:
	string name;
    static vector<Unicorn> list;
	
	Unicorn(string n)
	{
		cout << "Attempting Unicorn Creation..." << endl;
		for (vector<Unicorn>::iterator i = list.begin(); i != list.end(); ++i)
		{
            if (i->name == n)
            {
                std::cout << "Error: Unicorn with name \"" << n << "\" already exists.\n";
                return;
            }
		}
        name = n;
        list.push_back(*this);
		cout << "Unicorn " << n << " spawned." << endl;

		cout << "Unicorn List:" << endl;
		for (vector<Unicorn>::iterator i = list.begin(); i != list.end(); ++i)
		{
			cout << i->name << endl;;
		}
	}

	void destroy(string n)
	{
		bool gone = false;
		cout << "Searching for Unicorn..." << endl;
		for (vector<Unicorn>::iterator i = list.begin(); i != list.end();)
		{
			if (i->name == n)
			{
				cout << "Unicorn Found." << endl;
				cout << "Destroying Unicorn " << i->name << "..." << endl;
				i = list.erase(i);
				cout << "Unicorn annihilated." << endl;
				gone = true;
			}
			else
				i++;
		}

		if (gone == true)
		{
			cout << "Reformatting Unicorn List..." << endl;
			list.shrink_to_fit();
			cout << "Unicorn List Reformatted!" << endl;
		}
	}
};

vector<Unicorn> Unicorn::list;

int main()
{
	//Creating Major NPCs as Unicorns for testing.
	Unicorn Naxar = Unicorn("Naxar");
	Unicorn Redge = Unicorn("Redge");
	Unicorn Asher = Unicorn("Asher");
	Unicorn Juun = Unicorn("Juun");
	Unicorn Aegis = Unicorn("Aegis");
	Unicorn Volaren = Unicorn("Volaren");
	Unicorn Reila = Unicorn("Reila");

	//Wait that one doesn't exist anymore
	Asher.destroy("Asher");

	Unicorn Naxar2 = Unicorn("Naxar");
	Unicorn Caliban = Unicorn("Caliban");
	Unicorn Anastasia = Unicorn("Anastasia");
	Unicorn Raze = Unicorn("Raze");

	//Ok that should be goo- wait thost aren't NPCs, those are the eventual MCs.
	Caliban.destroy("Caliban");
	Anastasia.destroy("Anastasia");

	Unicorn Vinrasix = Unicorn("Vinrasix");
}