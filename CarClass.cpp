#include "BasicClasses.cpp"
#include <bits/stdc++.h>
using namespace std;

// inheriting all the basic classes 
// showing multiple inheritence
class Car : private VehicleHistory, private PaintQuality, private FrameState, private WheelAlignment, 
				private TyreQuality, private EngineQuality, private Upholstery
{
private:
	string carModel;		// model of the car
    string carNumber;		// number of the car
    string carColour;		// colour of the car
    float carRating;		// overall rating of the car
public:
	static int carCount;	// for counting the number of cars
	Car()				// default constructor 
	{
		carModel = "CarModel";
		carNumber = "CarNumber";
		carColour = "CarColour";
		carRating = 0.0;
	}
    void incrementCount()	// for incrementing carCount on addition of a car
	{
		carCount++;
	}
	int getCount() const	// returns value of carCount
	{
		return carCount;
	}
    void setCar();			// for taking input of data members
    void getCar() const;			// for printing all the information about the car
    float getRating() const	// returns carRating
    {
    	return carRating;
	}
    void calculateRating(); // calculates rating
    void getCarRating() const;	// displays car details and rating only
    // friend functions for displaying data
	friend void getVH(Car&);
    friend void getPQ(Car&);
    friend void getFS(Car&);
    friend void getWA(Car&);
    friend void getTQ(Car&);
    friend void getEQ(Car&);
    friend void getU(Car&);
    // friend functions for setting data
    friend void setVH(Car&);
    friend void setPQ(Car&);
    friend void setFS(Car&);
    friend void setWA(Car&);
    friend void setTQ(Car&);
    friend void setEQ(Car&);
    friend void setU(Car&);
    ~Car()			// destructor
    {
    	cout << endl;
    	cout << "Car class destroyed!!" << endl;
	}
}C[5];

// friend function definitions
void getVH(Car& c)
{
	c.getHistory();
}

void getPQ(Car& c)
{
	c.getPaint();
}

void getFS(Car& c)
{
	c.getFrame();
}

void getWA(Car& c)
{
	c.getAlignment();
}

void getTQ(Car& c)
{
	c.getTyre();
}

void getEQ(Car& c)
{
	c.getEngine();
}

void getU(Car& c)
{
	c.getUpholstery();
}

void setVH(Car& c)
{
	c.setHistory();
}

void setPQ(Car& c)
{
	c.setPaint();
}

void setFS(Car& c)
{
	c.setFrame();
}

void setWA(Car& c)
{
	c.setAlignment();
}

void setTQ(Car& c)
{
	c.setTyre();
}

void setEQ(Car& c)
{
	c.setEngine();
}

void setU(Car& c)
{
	c.setUpholstery();
}

int Car :: carCount = 0;	// initialising static variable carCount

// function definitions
void Car :: setCar()
{
	cout << endl;
	cout << "\t\t\t\t\t\t*****Basic Car Information*****" << endl;
	cout << "\t\t\t\t\t  Enter car model:\t\t\t\t";
	getline(cin >> ws, carModel);
	cout << "\t\t\t\t\t  Enter car number:\t\t\t\t";
	getline(cin >> ws, carNumber);
	cout << "\t\t\t\t\t  Enter car colour:\t\t\t\t";
	getline(cin >> ws, carColour);
	
	setHistory();
	setPaint();
	setFrame();
	setAlignment();
	setTyre();
	setEngine();
	setUpholstery();
	
	calculateRating();
}

void Car :: getCar() const
{
   	cout << endl;
	cout << "\t\t\t\t\t\t*****Basic Car Information*****" << endl;
	cout << "\t\t\t\t\t  Enter car model:\t\t\t\t" << carModel << endl;
	cout << "\t\t\t\t\t  Enter car number:\t\t\t\t" << carNumber << endl;
	cout << "\t\t\t\t\t  Enter car colour:\t\t\t\t" << carColour << endl;
	
	getHistory();
	getPaint();
	getFrame();
	getAlignment();
	getTyre();
	getEngine();
	getUpholstery();
	
	cout << endl;
	cout << "\t\t\t\t\t  OVERALL CAR RATING:\t\t\t\t" << getRating() << endl;
}

void Car :: calculateRating()
{
	float rating;
	rating += getVHRating();
	rating += getPQRating();
	rating += getFSRating();
	rating += getWARating();
	rating += getTQRating();
	rating += getEQRating();
	rating += getURating();
	
	rating = (rating / 7) * 10;
	
	carRating = rating;
}

void Car :: getCarRating() const
{
	cout << endl;
	cout << "\t\t\t\t\t\t*****Basic Car Information*****" << endl;
	cout << "\t\t\t\t\t  Enter car model:\t\t\t" << carModel << endl;
	cout << "\t\t\t\t\t  Enter car number:\t\t\t" << carNumber << endl;
	cout << "\t\t\t\t\t  Enter car colour:\t\t\t" << carColour << endl;
	cout << "\t\t\t\t\t  OVERALL CAR RATING:\t\t\t" << getRating() << endl;
}
