#include "allClasses.h"

using namespace std;

//Animal
Animal::Animal() : m_color("GRAY"), m_childCount(0), m_avgLifetime(0) {};
Animal::Animal( const char* color, int childs, float avgLifetime ) :  m_color(strdup(color)), m_childCount(childs), m_avgLifetime(avgLifetime) {};
Animal::Animal(ifstream& in_file) {
    in_file.read((char*)&m_color, sizeof(m_color));
    in_file.read((char*)&m_childCount, sizeof(m_childCount));
    in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
}
// TBD
Animal* Animal::copy() {};
Animal* Mammals::copy() {};
Animal* Horse::copy()
{
    Animal *h = new Horse(this->m_color, this->m_childCount, this->m_avgLifetime, this->m_pregnancyTime, this->m_milkLiters, this->m_type);
    return h;
}
Animal* Birds::copy() {};
Animal* Flamingo::copy()
{
    Animal *h = new Flamingo(this->m_color, this->m_childCount, this->m_avgLifetime, this->m_incubationTime, this->m_avgHeight);
    return h;
}
Animal* Fish::copy() {};
Animal* MammalsFish::copy() {};
Animal* GoldFish::copy()
{
    Animal *h = new GoldFish(this->m_color, this->m_childCount, this->m_avgLifetime, this->m_pregnancyTime, this->m_milkLiters, this->m_finCount, this->m_gillsCount, this->m_avgWeight, this->m_avgLength);
    return h;
}
Animal* Mermaid::copy()
{
    Animal *h = new Mermaid(this->m_color, this->m_childCount, this->m_avgLifetime, this->m_pregnancyTime, this->m_milkLiters, this->m_finCount, this->m_gillsCount, this->m_firstName, this->m_lastName);
    return h;
}

//Animal::Animal( ifstream& in_file )
// {

// };
//virtual Animal::~Animal();

void Animal::Save(ofstream &ofs) {
    ofs << m_color << " ";
    ofs << m_childCount << " ";
    ofs << m_avgLifetime << " ";
}

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
//virtual Animal Animal::copy() const {};
//Mamal
Mammals::Mammals() : m_milkLiters(0), m_pregnancyTime(0) {};

Mammals::Mammals( const char* color, int childs, float avgLifetime, float preg, float milk ) : Animal(color, childs, avgLifetime), m_pregnancyTime(preg), m_milkLiters(milk) {};

Mammals::Mammals(ifstream& in_file): Animal(in_file) {
    in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
    in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
}
//TBD
// Mammals::Mammals( ifstream& in_file )
// {

// };//init the Mammals from a binary file

//virtual ~Mammals::Mammals();

void Mammals::Save(ofstream &ofs) {
    ofs << m_pregnancyTime << " ";
    ofs << m_milkLiters << " ";
}

float Mammals::GetPregnanceTime() const
{
    return m_pregnancyTime;
};


float Mammals::GetMilk() const
{
    return m_milkLiters;
};
//virtual Animal Mammals::copy() const {};

Birds::Birds() : m_incubationTime(0) {}

Birds::Birds( const char* color, int childs, float avgLifetime, float incubation ) : Animal(color, childs, avgLifetime), m_incubationTime(incubation) {}


Birds::Birds(ifstream& in_file): Animal(in_file) {
    in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}

void Birds::Save(ofstream &ofs) {
    ofs << m_incubationTime << " ";
}
float Birds::GetIncubationTime() const
{
    return m_incubationTime;
};
//virtual Animal Birds::copy() const {};

Fish::Fish() : m_finCount(0), m_gillsCount(0) {};//set the default color to GRAY and other params to 0

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime), m_finCount(fin), m_gillsCount(gills) {}

Fish::Fish(ifstream& in_file): Animal(in_file) {
    in_file.read((char*)&m_finCount, sizeof(m_finCount));
    in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
}

void Fish::Save(ofstream &ofs) {
    ofs << m_finCount << " ";
    ofs << m_gillsCount << " ";
}
int	Fish::GetFinCount() const
{
    return m_finCount;
};

int	Fish::GetGillsCount() const
{
    return m_gillsCount;
};
//virtual Animal Fish::copy() const {};

Horse::Horse() : m_type(NULL) {};//set the default color to GRAY and other params to 0

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) : Mammals(color, childs, avgLifetime, preg, milk), m_type(strdup(type)) {}

Horse::Horse(ifstream& in_file): Mammals(in_file) {
    in_file.read((char*)&m_type, sizeof(m_type));
}

void Horse::Save(ofstream &ofs) {
    ofs << m_type << " ";
}
const char*	Horse::GetType() const
{
    return m_type;
};
//virtual Animal Horse::copy() const {
//    Animal mirror = new Horse(this.m_color, this.m_childCount, this)
//};

Flamingo::Flamingo() : m_avgHeight(0) {};//set the default color to GRAY and other params to 0


Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color, childs, avgLifetime, incubation), m_avgHeight(avgHeight) {}

Flamingo::Flamingo(ifstream& in_file): Mammals(in_file) {
    in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}
//Flamingo( ifstream& in_file );//init the Flamingo from a binary file

//virtual ~Flamingo();

void Flamingo::Save(ofstream &ofs) {
    ofs << m_avgHeight << " ";
}
float Flamingo::GetHeight() const
{
    return m_avgHeight;
};

MammalsFish::MammalsFish() {};//set the default color to GRAY and other params to 0

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) : Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills) {}
//MammalsFish::MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
//virtual ~MammalsFish();

void MammalsFish::Save(ofstream &ofs) {};

GoldFish::GoldFish() : m_avgWeight(0), m_avgLength(0) {};//set the default color to GRAY and other params to 0
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills) {}
//GoldFish::GoldFish( ifstream& in_file );//init the GoldFish from a binary file
//virtual ~GoldFish();

void GoldFish::Save(ofstream &ofs) {
    ofs << m_avgWeight << " ";
    ofs << m_avgLength << " ";
}

float GoldFish::GetWeight() const
{
    return m_avgWeight;
};//return the avg weight of the gold fish

float GoldFish::GetLength() const
{
    return m_avgWeight;
};


Mermaid::Mermaid() : m_firstName(NULL), m_lastName(NULL) {};//set the default color to GRAY and other params to 0

Mermaid::Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName ) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_firstName(strdup(firstName)), m_lastName(strdup(lastName)) {}
//Mermaid( ifstream& in_file );//init the Mermaid from a binary file
//virtual ~Mermaid();

void Mermaid::Save(ofstream &ofs) {
    ofs << m_firstName << " ";
    ofs << m_lastName << " ";
}

const char*	Mermaid::GetFirstName() const
{
    return m_firstName;
};//return the first name of the mermaid
const char*	Mermaid::GetLastName() const
{
    return m_lastName;
};//return the last name of the mermaid


Zoo::Zoo() : m_name(NULL), m_address(NULL), m_ticketPrice(0), m_openHours(NULL), m_closeHours(NULL), m_numOfAnimals(0), m_animals(NULL) {};//default c'tor  - all to 0 or null
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close) : m_name(strdup(name)), m_address(strdup(address)), m_ticketPrice(ticket), m_openHours(strdup(open)), m_closeHours(strdup(close)), m_animals(NULL) {}

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
    m_animals = (Animal**)realloc(m_animals, (m_numOfAnimals+1)*sizeof(Animal));
    Animal* newAnimal = an->copy();
    m_animals[m_numOfAnimals] = newAnimal;
	m_numOfAnimals++;
};//creates a copy of "an" (deep copy) and adds an animal to the array

//public:
Zoo& Zoo::operator+( Animal* an ){
    m_animals = (Animal**)realloc(m_animals, (m_numOfAnimals+1)*sizeof(Animal));
    m_animals[m_numOfAnimals] = an;
    m_numOfAnimals++;
};//adds an animal (only pointer, no copy needed) to the class and returns this with the change
Zoo Zoo::operator+( const Zoo& other ) const{
    Zoo* newZoo = new Zoo(this->m_name, this->m_address, m_ticketPrice, this->m_openHours, this->m_closeHours);
    for (unsigned i = 0; i < sizeof(m_animals); i++){
        newZoo->AddAnimal(m_animals[i]);
    }
    Animal** otherAnimals = other.GetAnimals();
    for (unsigned i = 0; i < sizeof(otherAnimals); i++){
        newZoo->AddAnimal(otherAnimals[i]);
    }

}; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
//
//public:
//	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
//	friend ifstream& operator>>( ifstream& in, Zoo& z );//operator to read the zoo from a text file
//
//public:
void Zoo::Save( ofstream& ofs ) const{
    ofs << m_name << " ";
    ofs << m_address << " ";
    ofs << m_ticketPrice << " ";
    ofs << m_openHours << " ";
    ofs << m_closeHours << " ";

    SaveAnimals(ofs);
};//method to save the info to a text file

void Zoo::SaveAnimals(ofstream &ofs) const {
    ofs << m_numOfAnimals << endl;

    for( unsigned int i = 0; i < m_numOfAnimals; ++i )
    {
        m_animals[i]->Save( ofs );	// calls the virtual function p->save(os);
    }
}
//	void Load( ifstream& ifs );//method to load the info from a text file
//	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file