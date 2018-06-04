#include "allClasses.h"

using namespace std;

//Animal
Animal::Animal() : m_color("GRAY"), m_childCount(0), m_avgLifetime(0) {};
Animal::Animal( const char* color, int childs, float avgLifetime ) :  m_color(_strdup(color)), m_childCount(childs), m_avgLifetime(avgLifetime) {};

// TBD
//Animal::Animal( ifstream& in_file )
// {

// };
//virtual Animal::~Animal();

const char* Animal::GetColor() const
{
    return m_color;
};
int	Animal::GetChildCount() const
{
    return m_childCount;
};
float Animal::GetLifetime() const
{
    return m_avgLifetime;
};

//Mamal
Mammals::Mammals() : m_milkLiters(0), m_pregnancyTime(0) {};

Mammals::Mammals( const char* color, int childs, float avgLifetime, float preg, float milk ) : Animal(color, childs, avgLifetime), m_pregnancyTime(preg), m_milkLiters(milk) {};

//TBD
// Mammals::Mammals( ifstream& in_file )
// {
    
// };//init the Mammals from a binary file

//virtual ~Mammals::Mammals();

float Mammals::GetPregnanceTime() const
{
    return m_pregnancyTime;
};


float Mammals::GetMilk() const
{
    return m_milkLiters;
};

Birds::Birds() : m_incubationTime(0) {}

Birds::Birds( const char* color, int childs, float avgLifetime, float incubation ) : Animal(color, childs, avgLifetime), m_incubationTime(incubation) {}


//Birds( ifstream& in_file );//init the Birds from a binary file


float Birds::GetIncubationTime() const
{
    return m_incubationTime;
};

Fish::Fish() : m_finCount(0), m_gillsCount(0) {};//set the default color to GRAY and other params to 0

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime), m_finCount(fin), m_gillsCount(gills) {}

//Fish( ifstream& in_file );//init the Fish from a binary file

int	Fish::GetFinCount() const
{
    return m_finCount;
};

int	Fish::GetGillsCount() const
{
    return m_gillsCount;
};

Horse::Horse() : m_type(NULL) {};//set the default color to GRAY and other params to 0

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) : Mammals(color, childs, avgLifetime, preg, milk), m_type(_strdup(type)) {}

//Horse( ifstream& in_file );//init the Horse from a binary file

const char*	Horse::GetType() const
{
    return m_type;
};

Flamingo::Flamingo() : m_avgHeight(0) {};//set the default color to GRAY and other params to 0


Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color, childs, avgLifetime, incubation), m_avgHeight(avgHeight) {}

//Flamingo( ifstream& in_file );//init the Flamingo from a binary file

//virtual ~Flamingo();

float Flamingo::GetHeight() const
{
    return m_avgHeight;
};

MammalsFish::MammalsFish() {};//set the default color to GRAY and other params to 0

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) : Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills) {}
//MammalsFish::MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
//virtual ~MammalsFish();

GoldFish::GoldFish() : m_avgWeight(0), m_avgLength(0) {};//set the default color to GRAY and other params to 0
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills) {}
//GoldFish::GoldFish( ifstream& in_file );//init the GoldFish from a binary file
//virtual ~GoldFish();
	
float GoldFish::GetWeight() const
{
    return m_avgWeight; 
};//return the avg weight of the gold fish

float GoldFish::GetLength() const
{
    return m_avgWeight;
};


Mermaid::Mermaid() : m_firstName(NULL), m_lastName(NULL) {};//set the default color to GRAY and other params to 0
	
Mermaid::Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName ) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_firstName(_strdup(firstName)), m_lastName(_strdup(lastName)) {}
//Mermaid( ifstream& in_file );//init the Mermaid from a binary file
//virtual ~Mermaid();
	
const char*	Mermaid::GetFirstName() const
{
    return m_firstName;
};//return the first name of the mermaid
const char*	Mermaid::GetLastName() const
{
    return m_lastName;
};//return the last name of the mermaid


Zoo::Zoo() : m_name(NULL), m_address(NULL), m_ticketPrice(0), m_openHours(NULL), m_closeHours(NULL), m_numOfAnimals(0), m_animals(NULL) {};//default c'tor  - all to 0 or null
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close) : m_name(_strdup(name)), m_address(_strdup(address)), m_ticketPrice(ticket), m_openHours(_strdup(open)), m_closeHours(_strdup(close)) {}

// Zoo( ifstream& in_file );//c'tor that gets a binary file and loads the data of the zoo from the file
//virtual ~Zoo();//d'tor

const char*	Zoo::GetName() const
{
    return m_name;
};//return the name of the zoo

const char* Zoo::GetAddress() const
{
    return m_address;
};//return the address of the zoo
float Zoo::GetTicketPrice() const
{
    return m_ticketPrice;
};//return the ticket price of the zoo

const char*	Zoo::GetOpenHour() const
{
    return m_openHours;
};//return the open hour of the zoo
	
const char*	Zoo::GetCloseHour() const
{
    return m_closeHours;   
};//return the close hour of the zoo

int	Zoo::GetNumOfAnimals() const
{
    return m_numOfAnimals;   
};//return the num of animals in the zoo

Animal** Zoo::GetAnimals() const
{
    return m_animals;   
};//return the animals array of the zoo

void Zoo::AddAnimal( Animal* an )
{

	m_animals[m_numOfAnimals] = an;
	m_numOfAnimals++;
};//creates a copy of "an" (deep copy) and adds an animal to the array

//public:
//	Zoo& operator+( Animal* an );//adds an animal (only pointer, no copy needed) to the class and returns this with the change
//	Zoo operator+( const Zoo& other ) const; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
//
//public:
//	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
//	friend ifstream& operator>>( ifstream& in, Zoo& z );//operator to read the zoo from a text file
//
//public:
//	void Save( ofstream& ofs ) const;//method to save the info to a text file
//	void Load( ifstream& ifs );//method to load the info from a text file
//	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file