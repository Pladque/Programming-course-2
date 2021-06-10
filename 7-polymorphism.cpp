#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};

class Circle : public virtual Shape
{
	float r;
public:
	Circle(float newR) : r(newR) {};

	void draw()
	{
		cout << "r = " << r << endl;
	}

};

class Triangle : public virtual Shape
{
	float a, b, c;
public:
	Triangle(float newA, float newB, float newC) : a(newA), b(newB), c(newC) {};

	void draw()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
	}
};

class Square : public virtual Shape
{
	float a, b;
public:
	Square(float newA, float newB) : a(newA), b(newB) {};

	void draw()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << endl;
	}

};

void showShape(Shape* toDisplay)
{
	toDisplay->draw();
}

/////////////////////// 2 /////////////////

class Rodent
{
public:
	virtual void showMe() = 0;

	virtual ~Rodent()
	{
		cout << "deleted Rodent" << endl;
	}
};

class Mouse : public virtual Rodent
{
public:
	void showMe()
	{
		cout << "Mouse here" << endl;
	}

	~Mouse()
	{
		cout << "deleted Mouse" << endl;
	}
};

class Gerbil : public virtual Rodent
{
public:
	void showMe()
	{
		cout << "Gerbil here" << endl;
	}

	~Gerbil()
	{
		cout << "deleted Gerbil" << endl;
	}
};

class Hamster : public virtual Rodent
{
public:
	void showMe()
	{
		cout << "Hamster here" << endl;
	}

	~Hamster()
	{
		cout << "deleted Hamser" << endl;
	}
};

class BlueHamster : public virtual Hamster
{
public:
	void showMe()
	{
		cout << "BlueHamster here" << endl;
	}

	~BlueHamster()
	{
		cout << "deleted BlueHamster" << endl;
	}
};

//////////////////////  3 ////////////////

class AirCraft
{
protected:
	bool grounded;
	float range;

public:
	bool crashed;

	virtual void land() = 0;
	virtual void start() = 0;
	virtual void wait() = 0;
	virtual void refuel() = 0;
	virtual float getRange() = 0;

	virtual void displayStatus() = 0;

	/*
	virtual ~AirCraft() = 0;
	//*/

	virtual ~AirCraft()
	{
		cout << "AirCraft deleted" << endl;
	}
	//*/
};

class Boeing747 : public virtual AirCraft
{
public:
	~Boeing747()
	{
		cout << "Boeing747 deleted" << endl;
	}

	Boeing747()
	{
		grounded = true;
		crashed = false;
		this->refuel();
	}

	void land()
	{
		grounded = true;
	}
	void start()
	{
		grounded = false;
	}
	void wait()
	{
		if (!grounded)   range -= 0.1f;
	}

	void refuel()
	{
		range = 5;
	}

	float getRange()
	{
		return range;
	}

	void displayStatus()
	{
		if (!crashed)
			cout << "boeing 747 -- grounded: " << grounded << " range: " << range << endl;
	}


};

class AirbusA330 : public virtual AirCraft
{
public:

	~AirbusA330()
	{
		cout << "AirbusA330 deleted" << endl;
	}

	AirbusA330()
	{
		grounded = true;
		crashed = false;
		this->refuel();
	}

	void land()
	{
		grounded = true;
	}
	void start()
	{
		grounded = false;
	}
	void wait()
	{
		if (!grounded)   range -= 0.2f;
	}

	void refuel()
	{
		range = 7;
	}

	float getRange()
	{
		return range;
	}

	void displayStatus()
	{
		if (!crashed)
			cout << "Airbus A330 -- grounded: " << grounded << " range: " << range << endl;
	}
};

class EmbraerE195 : public virtual AirCraft
{
public:

	~EmbraerE195()
	{
		cout << "EmbraerE195 deleted" << endl;
	}

	EmbraerE195()
	{
		grounded = true;
		crashed = false;
		this->refuel();
	}

	void land()
	{
		grounded = true;
	}
	void start()
	{
		grounded = false;
	}
	void wait()
	{
		if (!grounded)   range -= 0.5f;
	}

	void refuel()
	{
		range = 11;
	}

	float getRange()
	{
		return range;
	}

	void displayStatus()
	{
		if (!crashed)
			cout << "Embraer E195 -- grounded: " << grounded << " range: " << range << endl;
	}
};

class Tower
{
	vector<AirCraft*> aircrafts;
public:
	Tower(vector<AirCraft*> planes) : aircrafts(planes) {}

	void allStart()
	{
		for (auto aircraft : aircrafts)
		{
			if (aircraft->getRange() > 0)
				aircraft->start();
		}
	}

	void refuelGrounded()
	{
		for (auto aircraft : aircrafts)
		{
			aircraft->refuel();
		}
	}

	void startById(int id)
	{
		if (aircrafts[id]->getRange() > 0)
			aircrafts[id]->start();
		else
		{
			cout << "NO FUEL: ";  aircrafts[id]->displayStatus();
		}
	}

	void waitAll()
	{
		for (int i = 0; i < aircrafts.size(); i++)
		{
			aircrafts[i]->wait();

			if (aircrafts[i]->getRange() <= 0)
			{
				cout << "CRASH: ";
				aircrafts[i]->displayStatus();
				aircrafts[i]->crashed = true;
				aircrafts.erase(aircrafts.begin() + i);
			}
		}

	}

	void landAll()
	{
		for (auto aircraft : aircrafts)
		{
			aircraft->land();
		}
	}

	void landById(int id)
	{
		aircrafts[id]->land();
	}

};

// wirtualna klasa ktora przeladowuje funkcje 
// dziecko kotre dziedziczy i nadpisuje ktoras z tych funkcji

///////////// + /////////////
class AllAdder
{
public:
	template <typename T>
	T add(T a, T b)
	{
		return a + b;
	}

	template <typename T>
	T substr(T a, T b)
	{
		return a - b;
	}

	template <typename T>
	T mult(T a, T b)
	{
		return a * b;
	}
};

class StringAdder: public AllAdder
{
public:
	string substr(string a, string b)
	{
		return a + '-' + b;
	}

	string mult(string a, string b)
	{
		string result;
		for (int i = 0; i < b.length(); i++)
		{
			result += a;
		}

		return result;
	}
};


int main()
{
	//////////////////// 1 ///////////////////
	Circle circle(5);
	Triangle triangle(1, 8, 7);
	Square square(2, 2);

	showShape(&circle);
	showShape(&triangle);
	showShape(&square);
	cout << endl << endl << endl;
	
	//////////////////// 2 /////////////////

	vector<Rodent*> rodents;

	rodents.push_back(new Hamster);
	rodents.push_back(new Hamster);
	rodents.push_back(new Gerbil);
	rodents.push_back(new Mouse);
	rodents.push_back(new BlueHamster);

	for (auto rodent : rodents)
		rodent->showMe();


	Rodent* tempRodent;
	while (!rodents.empty())
	{
		tempRodent = rodents.back();
		rodents.pop_back();
		delete tempRodent;
	}

	cout << endl << endl << endl;
	
	/////////////////// 3 /////////////////

	vector<AirCraft*> planes = vector<AirCraft*>();

	planes.push_back(new AirbusA330());
	planes.push_back(new AirbusA330());
	planes.push_back(new AirbusA330());

	planes.push_back(new Boeing747());
	planes.push_back(new Boeing747());

	planes.push_back(new EmbraerE195());
	planes.push_back(new EmbraerE195());
	planes.push_back(new EmbraerE195());

	Tower tower(planes);

	tower.allStart();
	tower.landById(7);

	for (int i = 0; i < 5; i++)
	{
		tower.waitAll();
	}

	tower.landById(3);
	tower.landById(4);
	tower.refuelGrounded();
	tower.allStart();

	for (int i = 0; i < 22; i++)
	{
		tower.waitAll();
	}

	tower.landAll();

	AirCraft* temp;
	while (!planes.empty())
	{
		temp = planes.back();
		planes.pop_back();
		delete temp;
		//temp = nullptr;
	}

	cout << endl << endl << endl;


	////////////  + /////////////
	
	cout << endl << endl << "+ Task" << endl;
	StringAdder stringAdder;

	cout << stringAdder.add(5, 7) << endl;
	cout << stringAdder.substr("aaa", "bbb") << endl;
	cout << stringAdder.AllAdder::substr(3, 3) << endl;

}

