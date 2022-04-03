#include <bits/stdc++.h>
using namespace std;
class VehicleHistory
{
private:
    float VHRating;		// overall history rating of the car
	int yrsOld;         // age of the car
    long int kmDriven;  // number of km car is driven
    int minorAccidents; // number of minor accidents car faced
    int majorAccidents; // number of major accidents car faced
public:
	VehicleHistory()	// default constructor
	{
		VHRating = 0.0;
		yrsOld = 0;
		kmDriven = 0;
		minorAccidents = 0;
		majorAccidents = 0;
	}
	void setHistory() 	// for taking input of data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Vehicle History Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the age of the car in yrs:\t\t";
        cin >> yrsOld;
        cout << "\t\t\t\t\t  Enter the number of kilometers driven:\t";
        cin >> kmDriven;
        cout << "\t\t\t\t\t  Enter the number of minor accidents:\t\t";
        cin >> minorAccidents;
        cout << "\t\t\t\t\t  Enter the number of major accidents:\t\t";
        cin >> majorAccidents;
        
        calculateVHRating();
    }
    void getHistory() const	// for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Vehicle History*****" << endl;
        cout << "\t\t\t\t\t  Age of the car:\t\t\t\t" << yrsOld << endl;
		cout << "\t\t\t\t\t  Number of km driven:\t\t\t\t" << kmDriven << endl;
		cout << "\t\t\t\t\t  Number of minor accidents:\t\t\t" << minorAccidents << endl;
		cout << "\t\t\t\t\t  Number of major accidents:\t\t\t" << majorAccidents << endl;
		cout << "\t\t\t\t\t  Overall Vehicle History Rating:\t\t" << VHRating << endl;
    }
    float getVHRating()	const	// returns VHRating
    {
    	return VHRating;
	}
    void calculateVHRating(); 	// for calculating overall historyRating
	~VehicleHistory()			// destructor
    {
    	cout << "Vehicle History class destroyed!!" << endl;
	}
};

void VehicleHistory :: calculateVHRating()
{
	float rating = 10.0;
	// rating based on age
	rating = rating - (0.1 * pow(2, yrsOld));
	
	// rating based on km driven
	if(kmDriven < 200000)
		rating = rating - (kmDriven * 0.00001);
	else if(kmDriven < 300000)
		rating = rating - 3 * (kmDriven * 0.00001);
	else
		rating = rating - 5;
	
	// rating based on accidents
	rating = rating - minorAccidents;
	rating = rating - 2 * majorAccidents;
	
	if(rating < 0)
		rating = 0.0;
	
	VHRating = rating;
}

class PaintQuality
{
private:
    float paintRating;    // overall paint rating of the car
    float paintThickness; // for thickness of the paint in microns(60 to 110 good)
    int minorScratches;   // number of minor scratches on the car
    int majorScratches;   // number of major scratches on the car
    bool paintMatch;      // does the paint match yes or no
    bool isProtection;    // is a protection layer present yes or no
public:
	PaintQuality()			// default constructor
	{
		paintRating = 0.0;
		paintThickness = 0.0;
		minorScratches = majorScratches = 0;
		paintMatch = isProtection = 0;
	}
	void setPaint()       // for taking input of data members
    {
        cout << endl;
    	cout << "\t\t\t\t\t\t*****Paint Quality Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the paint thickness in microns:\t\t";
        cin >> paintThickness;
        cout << "\t\t\t\t\t  Enter the number of minor scratches:\t\t";
        cin >> minorScratches;
        cout << "\t\t\t\t\t  Enter the number of major scratches:\t\t";
        cin >> minorScratches;
        cout << "\t\t\t\t\t  Does the paints match(0/1):\t\t\t";
        cin >> paintMatch;
        cout << "\t\t\t\t\t  Is there any paint protection(0/1):\t\t";
        cin >> isProtection;
        
        calculatePQRating();
    }
    void getPaint() const	// for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Paint Quality Details*****" << endl;
        cout << "\t\t\t\t\t  Paint thickness:\t\t\t\t" << paintThickness << endl;
        cout << "\t\t\t\t\t  Number of minor scratches:\t\t\t" << minorScratches << endl;
        cout << "\t\t\t\t\t  Number of major scratches:\t\t\t" << minorScratches << endl;
        cout << "\t\t\t\t\t  Does the paints match(0/1):\t\t\t" << paintMatch << endl;
        cout << "\t\t\t\t\t  Is there any paint protection(0/1):\t\t" << isProtection << endl;
        cout << "\t\t\t\t\t  Overall Tyre Quality Rating:\t\t\t" << paintRating << endl;
    }
    float getPQRating()	const	// returns paintRating
    {
    	return paintRating;
	}
    void calculatePQRating(); 	// for calculating paintRating
    ~PaintQuality()			// destructor
    {
    	cout << "Paint Quality class destroyed!!" << endl;
	}
};

void PaintQuality :: calculatePQRating()
{
	float rating = 10.0;
	
	// rating based on paint thickness
	if(paintThickness < 60 || paintThickness > 110)
		rating = rating - 2;
	
	// rating based on scratches on the car
	rating = rating - (0.1 * minorScratches);
	rating = rating - (0.5 * majorScratches);
	
	// rating based on paint matching
	if(!paintMatch)
		rating = rating - 1;
	
	// rating based on paint protection
	if(!isProtection)
		rating = rating - 1;
	
	if(rating < 0)
		rating = 0.0;
		
	paintRating = rating;
}

class FrameState
{
private:
    float frameRating;        // overall frame rating of the car
    int minorDents;         // number of minor dents in the car
    int majorDents;         // number of major dents in the car
    int windowsFunctioning; // number of windows working properly
public:
	FrameState()		// default constructor
	{
		frameRating = 0.0;
		minorDents = majorDents = windowsFunctioning = 0;
	}
    void setFrame() // for taking input of data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Frame State Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the number of minor dents:\t\t";
        cin >> minorDents;
        cout << "\t\t\t\t\t  Enter the number of major dents:\t\t";
        cin >> majorDents;
        cout << "\t\t\t\t\t  Enter the number of windows working properly:\t";
        cin >> windowsFunctioning;
        
        calculateFSRating();
    }
    void getFrame() const	// for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Frame State Details*****" << endl;
        cout << "\t\t\t\t\t  The number of minor dents:\t\t\t" << minorDents << endl;
        cout << "\t\t\t\t\t  The number of major dents:\t\t\t" << majorDents << endl;
        cout << "\t\t\t\t\t  The number of windows working properly:\t" << windowsFunctioning << endl;
        cout << "\t\t\t\t\t  Overall Frame Rating:\t\t\t\t" << frameRating << endl;
    }
    float getFSRating()	const	// returns frameRating
    {
    	return frameRating;
	}
    void calculateFSRating(); 	// for calculating frameRating
    ~FrameState()		// destructor
    {
    	cout << "Frame State class destroyed!!" << endl;
	}
};

void FrameState :: calculateFSRating()
{
	float rating = 10.0;
	
	// rating based on dents
	rating = rating - (0.5 * minorDents) - majorDents;
	
	// rating based windows functioning
	rating = rating - 2 * (4 - windowsFunctioning);
	
	if(rating < 0)
		rating = 0.0;
	
	frameRating = rating;
}

class WheelAlignment
{
private:
    float alignmentRating; // overall wheel alignment rating of the car
    float frontCaster;     // total caster in the front wheels
    float frontCamber;     // total camber in the front wheels
    float frontToe;        // total toe in the front wheels
    float rearCamber;      // total camber in the rear wheels
    float rearToe;         // total toe in the rear wheels
    float thrustAngle;     // total thrust angle
public:
	WheelAlignment()		// default constructor
	{
		alignmentRating = 0.0;
		frontCaster = frontCamber = frontToe = 0.0;
		rearCamber = rearToe = thrustAngle = 0.0;
	}
    void setAlignment() 	// for taking input of data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Wheel Alignment Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the front caster value:\t\t\t";
        cin >> frontCaster;
        cout << "\t\t\t\t\t  Enter the front camber value:\t\t\t";
        cin >> frontCamber;
        cout << "\t\t\t\t\t  Enter the front toe value:\t\t\t";
        cin >> frontToe;
		cout << "\t\t\t\t\t  Enter the rear camber value:\t\t\t";
        cin >> rearCamber;
        cout << "\t\t\t\t\t  Enter the rear toe value:\t\t\t";
        cin >> rearToe;
        cout << "\t\t\t\t\t  Enter the thrust angle value:\t\t\t";
        cin >> thrustAngle;
        
        calculateWARating();
    }
    void getAlignment() const // for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Wheel Alignment Details*****" << endl;
        cout << "\t\t\t\t\t  The front caster value:\t\t\t" << frontCaster << endl;
        cout << "\t\t\t\t\t  The front camber value:\t\t\t" << frontCamber << endl;
        cout << "\t\t\t\t\t  The front toe value:\t\t\t\t" << frontToe << endl;
		cout << "\t\t\t\t\t  The rear camber value:\t\t\t" << rearCamber << endl;
        cout << "\t\t\t\t\t  The rear toe value:\t\t\t\t" << rearToe << endl;
        cout << "\t\t\t\t\t  The thrust angle value:\t\t\t" << thrustAngle << endl;
    	cout << "\t\t\t\t\t  Overall Wheel Alignment Rating:\t\t" << alignmentRating << endl;
	}
    float getWARating()	const	// returns alignmentRating
    {
    	return alignmentRating;
	}
    void calculateWARating(); 	// for calculating alignmentRating
    ~WheelAlignment()		// destructor
    {
    	cout << "Wheel Alignment class destroyed!!" << endl;
	}
};

void WheelAlignment :: calculateWARating()
{
	float rating = 10.0;
	
	// rating based on front caster
	if(frontCaster < 0.8 || frontCaster > 4.8)
		rating = rating - 1;
	
	// rating based on front camber
	if(frontCamber < -2.30 || frontCamber > 0.9)
		rating = rating - 1;
	
	// rating based on front toe
	if(frontToe < -0.17 || frontToe > 0.17)
		rating = rating - 1;
	
	// rating based on rear camber
	if(rearCamber < -4.30 || rearCamber > -0.30)
		rating = rating - 2;
	
	// rating based on rear toe
	if(rearToe < 0.06 || rearToe > 0.23)
		rating = rating - 2;
	
	// rating based on thrust angle
	if(thrustAngle != 0.0)
		rating = rating - 1;
	
	if(rating < 0)
		rating = 0.0;
	
	alignmentRating = rating;
}

class TyreQuality
{
private:
    float tyreRating; // overall tyre rating of the car
    float treadDepth; // tread depth in mm in each tyre(min should be 1.6mm)
    int punctures;    // number of punctures fixed / unfixed (if any)
public:
	TyreQuality()		// default constructor
	{
		tyreRating = treadDepth = 0.0;
		punctures = 0;
	}
    void setTyre() // for taking input of data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Tyre Quality Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the tread depth in millimeters:\t\t";
        cin >> treadDepth;
		cout << "\t\t\t\t\t  Enter the number of punctures fixed/unfixed:\t";
        cin >> punctures;
        
        calculateTQRating();
    }
    void getTyre() const // for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Tyre Quality Details*****" << endl;
        cout << "\t\t\t\t\t  The tread depth in millimeters:\t\t" << treadDepth << endl;
		cout << "\t\t\t\t\t  The number of punctures:\t\t\t" << punctures << endl;
		cout << "\t\t\t\t\t  Overall Tyre Rating:\t\t\t\t" << tyreRating << endl;
    }
    float getTQRating()	const	// returns tyreRating
    {
    	return tyreRating;
	}
    void calculateTQRating(); 	// for calculating tyreRating
    ~TyreQuality()		// destructor
    {
    	cout << "Tyre Quality class destroyed!!" << endl;
	}
};

void TyreQuality :: calculateTQRating()
{
	float rating = 10.0;
	
	// rating based on tread depth
	if(treadDepth < 1.6 || treadDepth > 4.0)
		rating = rating - 4;
	
	// rating based on punctures
	rating = rating - punctures;
	
	if(rating < 0)
		rating = 0.0;
	
	tyreRating = rating;
}

class EngineQuality
{
private:
    float engineRating;      // overall engine rating of the car
    float soundQuality;      // sound quality rating of the sound that the engine makes
    bool engineOil;			// is good engine oil present in the engine
    bool coolant;			// is good coolant present in the engine
public:
	EngineQuality()			// default constructor
	{
		engineRating = soundQuality = 0.0;
		engineOil = coolant = 0;
	}
    void setEngine() // for taking input of data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Engine Quality Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the sound quality rating of the engine:\t";
        cin >> soundQuality;
        cout << "\t\t\t\t\t  Is good quality engine oil present(0/1):\t";
        cin >> engineOil;
        cout << "\t\t\t\t\t  Is good quality coolant present(0/1):\t\t";
        cin >> coolant;
        
        calculateEQRating();
    }
    void getEngine() const // for printing data members
    {
    	cout << endl;
    	cout << "\t\t\t\t\t\t*****Engine Quality Details*****" << endl;
        cout << "\t\t\t\t\t  The sound quality rating of the engine:\t" << soundQuality << endl;
        cout << "\t\t\t\t\t  Is good quality engine oil present(0/1):\t" << engineOil << endl;
        cout << "\t\t\t\t\t  Is good quality coolant present(0/1):\t\t" << coolant << endl;
        cout << "\t\t\t\t\t  Overall Engine Rating:\t\t\t" << engineRating << endl;
    }
    float getEQRating()	const	// returns engineRating
    {
    	return engineRating;
	}
    void calculateEQRating(); 	// for calculating engineRating
    ~EngineQuality()		// destructor
    {
    	cout << "Engine Quality class destroyed!!" << endl;
	}
};

void EngineQuality :: calculateEQRating()
{
	float rating = 10.0;
	
	// rating based on sound quality
	rating = rating - (10 - soundQuality);
	
	// rating based on engine oil
	if(!engineOil)
		rating = rating - 1;
	
	// rating based on coolant
	if(!coolant)
		rating = rating - 1;
	
	if(rating < 0)
		rating = 0.0;
	
	engineRating = rating;
}

class Upholstery
{
private:
    float upholsteryRating; 	// overall upholstery rating of the car
public:
	Upholstery()				// default constructor
	{
		upholsteryRating = 0.0;
	}
    void setUpholstery() 		// for taking input of data members
    {
        cout << endl;
    	cout << "\t\t\t\t\t\t*****Upholstery Details*****" << endl;
        cout << "\t\t\t\t\t  Enter the upholstery rating:\t\t\t";
        cin >> upholsteryRating;
    }
    void getUpholstery() const	// for printing data members
    {
        cout << endl;
    	cout << "\t\t\t\t\t\t*****Upholstery Details*****" << endl;
        cout << "\t\t\t\t\t  The Overall Upholstery Rating:\t\t" << upholsteryRating << endl;
    }
    float getURating() const	// returns upholsteryRating
    {
    	return upholsteryRating;
	}
	~Upholstery()		// destructor
	{
    	cout << "Upholstery class destroyed!!" << endl;
	}
};
