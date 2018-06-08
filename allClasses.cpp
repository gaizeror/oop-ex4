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
void Animal::saveType(ofstream& ofs) const
{
    string type;
    string returnedType = typeid(*this).name();
    for (int i=1; i < returnedType.length(); i++){
        type.push_back(returnedType[i]);
    }
    ofs << "\n" << type ;
}
void Animal::saveTypeBin(ofstream& ofs) const
{
    char type[2];
    strncpy(type, typeid(*this).name() + 1, 2);
    ofs.write((const char*)type, 2);
}
void Animal::Save(ofstream& ofs) {
    saveType( ofs );
    ofs << "\n" << m_color;
    ofs << "\n" << m_childCount ;
    ofs << "\n" << m_avgLifetime ;
}
void Animal::SaveBin(ofstream& ofs) const
{
    saveTypeBin(ofs);
    ofs.write((char*)&m_color,sizeof(m_color));
    ofs.write((char*)&m_childCount,sizeof(m_childCount));
    ofs.write((char*)&m_avgLifetime,sizeof(m_avgLifetime));
}
void Animal::Load(ifstream& ifs)
{
    char temp[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_color = new char[strlen(temp) + 1];

    strcpy(m_color,temp);

    ifs >> m_childCount;
    ifs >> m_avgLifetime;
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

void Mammals::SaveBin(ofstream& ofs) const
{
    Animal::SaveBin(ofs);
    ofs.write((char*)&m_pregnancyTime,sizeof(m_pregnancyTime));
    ofs.write((char*)&m_milkLiters,sizeof(m_milkLiters));
}
void Mammals::Save(ofstream &ofs) {
    Animal::Save(ofs);
    ofs << "\n" << m_pregnancyTime ;
    ofs << "\n" << m_milkLiters ;
}
void Mammals::Load(ifstream& ifs)
{
    Animal::Load(ifs);
    ifs >> m_pregnancyTime;
    ifs >> m_milkLiters;
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

void Birds::SaveBin(ofstream& ofs) const
{
    Animal::SaveBin(ofs);
    ofs.write((char*)&m_incubationTime,sizeof(m_incubationTime));
}
void Birds::Save(ofstream &ofs) {
    Animal::Save(ofs);
    ofs << "\n" << m_incubationTime ;
}
void Birds::Load(ifstream& ifs)
{
    Animal::Load(ifs);
    ifs >> m_incubationTime;
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
void Fish::SaveBin(ofstream& ofs) const
{
    Animal::SaveBin(ofs);
    ofs.write((char*)&m_finCount,sizeof(m_finCount));
    ofs.write((char*)&m_gillsCount,sizeof(m_gillsCount));
}
void Fish::Save(ofstream &ofs) {
    Animal::Save(ofs);
    ofs << "\n" << m_finCount ;
    ofs << "\n" << m_gillsCount ;
}
void Fish::Load(ifstream& ifs)
{
    Animal::Load(ifs);
    ifs >> m_finCount ;
    ifs >> m_gillsCount;
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

Horse::Horse() : Mammals(), m_type(NULL) {};//set the default color to GRAY and other params to 0

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) : Mammals(color, childs, avgLifetime, preg, milk), Animal(color,childs,avgLifetime), m_type(strdup(type)) {}

Horse::Horse(ifstream& in_file): Mammals(in_file) {
    in_file.read((char*)&m_type, sizeof(m_type));
}
void Horse::SaveBin(ofstream& ofs) const
{
    Mammals::SaveBin(ofs);
    ofs.write((char*)&m_type,sizeof(m_type));
}

void Horse::Save(ofstream &ofs) {
    Mammals::Save(ofs);
    ofs << "\n" << m_type ;
}
void Horse::Load(ifstream& ifs)
{
    Mammals::Load(ifs);
    char temp[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_type = new char[strlen(temp) + 1];
    strcpy(m_type, temp);
}
const char*	Horse::GetType() const
{
    return m_type;
};
//virtual Animal Horse::copy() const {
//    Animal mirror = new Horse(this.m_color, this.m_childCount, this)
//};

Flamingo::Flamingo() : m_avgHeight(0) {};//set the default color to GRAY and other params to 0


Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color, childs, avgLifetime, incubation), Animal(color, childs, avgLifetime), m_avgHeight(avgHeight) {}

Flamingo::Flamingo(ifstream& in_file): Birds(in_file) {
    in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}

//virtual ~Flamingo();
void Flamingo::SaveBin(ofstream& ofs) const
{
    Birds::SaveBin(ofs);
    ofs.write((char*)&m_avgHeight,sizeof(m_avgHeight));
}
void Flamingo::Save(ofstream &ofs) {
    Birds::Save(ofs);
    ofs << "\n" << m_avgHeight ;
}
void Flamingo::Load(ifstream& ifs)
{
    Birds::Load(ifs);
    ifs >> m_avgHeight;
}
float Flamingo::GetHeight() const
{
    return m_avgHeight;
};

MammalsFish::MammalsFish() {};//set the default color to GRAY and other params to 0

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) : Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills) {}
//MammalsFish::MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
//virtual ~MammalsFish();

void MammalsFish::SaveBin(ofstream& ofs) const
{
    Mammals::SaveBin(ofs);
    Fish::SaveBin(ofs);
}
void MammalsFish::Save(ofstream &ofs) {
    Mammals::Save(ofs);
    Fish::Save(ofs);
};
void MammalsFish::Load(ifstream& ifs) {};

GoldFish::GoldFish() : m_avgWeight(0), m_avgLength(0) {};//set the default color to GRAY and other params to 0
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills), Animal(color, childs, avgLifetime), m_avgWeight(avgW), m_avgLength(avgL) {}
//GoldFish::GoldFish( ifstream& in_file );//init the GoldFish from a binary file
//virtual ~GoldFish();

void GoldFish::SaveBin(ofstream& ofs) const
{
    MammalsFish::SaveBin(ofs);
    ofs.write((char*)&m_avgWeight,sizeof(m_avgWeight));
    ofs.write((char*)&m_avgLength,sizeof(m_avgLength));
}
void GoldFish::Save(ofstream &ofs) {
    MammalsFish::Save(ofs);
    ofs << "\n" << m_avgWeight ;
    ofs << "\n" << m_avgLength ;
}
void GoldFish::Load(ifstream& ifs)
{
    MammalsFish::Load(ifs);
    ifs >> m_avgWeight;
    ifs >> m_avgLength;
}
float GoldFish::GetWeight() const
{
    return m_avgWeight;
};//return the avg weight of the gold fish

float GoldFish::GetLength() const
{
    return m_avgWeight;
};


Mermaid::Mermaid() : MammalsFish(), m_firstName(NULL), m_lastName(NULL) {};//set the default color to GRAY and other params to 0

Mermaid::Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName ) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills), Animal(color, childs, avgLifetime), m_firstName(strdup(firstName)), m_lastName(strdup(lastName)) {}
//Mermaid( ifstream& in_file );//init the Mermaid from a binary file
//virtual ~Mermaid();

void Mermaid::SaveBin(ofstream& ofs) const
{
    MammalsFish::SaveBin(ofs);
    ofs.write((char*)&m_firstName,sizeof(m_firstName));
    ofs.write((char*)&m_lastName,sizeof(m_lastName));
}
void Mermaid::Save(ofstream &ofs) {
    MammalsFish::Save(ofs);
    ofs << "\n" << m_firstName ;
    ofs << "\n" << m_lastName ;
}
void Mermaid::Load(ifstream& ifs)
{
    MammalsFish::Load(ifs);
    char temp[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_firstName = new char[strlen(temp) + 1];
    strcpy(m_firstName, temp);
    char temp2[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_lastName = new char[strlen(temp) + 1];
    strcpy(m_lastName, temp);
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
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close) : m_name(strdup(name)), m_address(strdup(address)), m_ticketPrice(ticket), m_openHours(strdup(open)), m_closeHours(strdup(close)), m_numOfAnimals(0), m_animals(NULL) {}

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
    if (m_animals == NULL) {
        m_animals = (Animal**)calloc(1, sizeof(Animal));
        if (m_animals == NULL) {
            return;
        }
    }
    else {
        m_animals = (Animal**)realloc(m_animals, (m_numOfAnimals+1)*sizeof(Animal));
    }
    m_animals[m_numOfAnimals] = (Animal*)calloc(1, sizeof(Animal));
    m_animals[m_numOfAnimals] =  an->copy();
	m_numOfAnimals++;
};//creates a copy of "an" (deep copy) and adds an animal to the array

//public:
Zoo& Zoo::operator+( Animal* an ){
    m_animals = (Animal**)realloc(m_animals, (m_numOfAnimals+1)*sizeof(Animal));
    m_animals[m_numOfAnimals] = (Animal*)calloc(1, sizeof(Animal));
    m_animals[m_numOfAnimals] = an;
    m_numOfAnimals++;
    return *this;
};//adds an animal (only pointer, no copy needed) to the class and returns this with the change
Zoo Zoo::operator+( const Zoo& other ) const{
    Zoo* newZoo = new Zoo(this->m_name, this->m_address, m_ticketPrice, this->m_openHours, this->m_closeHours);
    for (unsigned i = 0; i < m_numOfAnimals; i++){
        newZoo->AddAnimal(m_animals[i]);
    }
    Animal** otherAnimals = other.GetAnimals();
    for (unsigned i = 0; i < m_numOfAnimals; i++){
        newZoo->AddAnimal(otherAnimals[i]);
    }
    return *newZoo;

}; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
Zoo& Zoo::operator+=( Animal* an ){
    AddAnimal(an);
    return *this;
};
//
//public:
//	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
//	friend ifstream& operator>>( ifstream& in, Zoo& z );//operator to read the zoo from a text file
//
//public:
void Zoo::Save( ofstream& ofs ) const{
    ofs << m_name ;
    ofs << "\n" << m_address ;
    ofs << "\n" << m_ticketPrice ;
    ofs << "\n" << m_openHours ;
    ofs << "\n" << m_closeHours ;

    SaveAnimals(ofs);
};//method to save the info to a text file

void Zoo::SaveAnimals(ofstream &ofs) const {
    ofs << "\n" << m_numOfAnimals ;

    for( unsigned int i = 0; i < m_numOfAnimals; ++i )
    {
        m_animals[i]->Save( ofs );	// calls the virtual function p->save(os);
    }
}
void Zoo::clear() {
    for( unsigned int i = 0; i < m_numOfAnimals; ++i )
    {
        if( m_animals[i] )
            delete m_animals[i];

        m_animals[i] = NULL;
    }

    delete m_animals;
}
Animal* Zoo::CreateAnimal(ifstream& is)
{
    char temp[256] = {0};
    is.getline(temp, 256, '\n');

    char* animalType = new char[strlen(temp) + 1];

    strcpy(animalType, temp);

    if( strcmp(animalType, "Horse" ) == 0)
        return new Horse;
    else if( strcmp(animalType, "GoldFish" ) == 0)
        return new GoldFish;
    else if( strcmp(animalType, "Flamingo" ) == 0)
        return new Flamingo;
    else if( strcmp(animalType, "Mermaid" ) == 0)
        return new Mermaid;
    else return NULL;
}
void Zoo::Load( ifstream& ifs ){

    char temp[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_name = new char[strlen(temp) + 1];

    strcpy(m_name,temp);

    char temp2[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_address = new char[strlen(temp) + 1];

    strcpy(m_address,temp);
    ifs >> m_ticketPrice;

    char temp3[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_openHours = new char[strlen(temp) + 1];

    strcpy(m_openHours,temp);

    char temp4[256] = {0};
    ifs.getline(temp, 256, '\n');

    char* m_closeHours = new char[strlen(temp) + 1];

    strcpy(m_closeHours,temp);

    LoadAnimals( ifs );
};//method to load the info from a text file
void Zoo::LoadAnimals(ifstream& is) {
    clear(); // first clear old content.

    is >> m_numOfAnimals;

    // allocate memory for products.
    m_animals = new Animal*[m_numOfAnimals];

    for( unsigned int i = 0; i < m_numOfAnimals && !is.eof(); ++i )
    {
        Animal* p = CreateAnimal( is );  // Creates a new product, identify its type in running time.

        p->Load( is );   // calls the virtual function p->read(is);

        m_animals[i] = p;
    }
}
void Zoo::SaveAnimalsBin(ofstream& ofs) const
{
    ofs.write((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));

    for( unsigned int i = 0; i < m_numOfAnimals; ++i )
    {
        m_animals[i]->SaveBin( ofs );	// calls the virtual function p->save(os);
    }
}

void Zoo::SaveBin(ofstream& ofs) const
{
    ofs.write((char*)&m_name, sizeof(m_name));
    ofs.write((char*)&m_address, sizeof(m_address));
    ofs.write((char*)&m_ticketPrice, sizeof(m_ticketPrice));
    ofs.write((char*)&m_openHours, sizeof(m_openHours));
    ofs.write((char*)&m_closeHours, sizeof(m_closeHours));

    SaveAnimalsBin( ofs );
};//method to save the info to a binary file
ofstream& operator<<( ofstream& out, const Zoo& z )
{
    z.Save(out);
    return out;
};
ifstream& operator>>(ifstream& in, Zoo& z )
{
    z.Load( in );
    return in;
}