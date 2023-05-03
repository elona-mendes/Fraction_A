
#include "Fraction.hpp"

using namespace std;
// using namespace ariel;


Fraction operator+ (const Fraction& a, const Fraction& other){
    return Fraction(0, 1);
}
Fraction operator+ (const Fraction& a, const float& other){
    return Fraction(0, 1);
}

Fraction operator+ (const float& a, const Fraction& other){
    return Fraction(0, 1);
}

Fraction& operator+= (Fraction& a, const float& other){
    float float_value = static_cast<float>(a.numerator/a.denominator) + other;
    a = Fraction(float_value);
    return a;
}

float& operator+= (float& a, const Fraction& other){
    a = a+(other.getNumerate()/other.getDenom());
    return a;
}

Fraction& operator-= (Fraction& a, const float& other){
    float float_value = static_cast<float>(a.numerator/a.denominator) - other;
    a = Fraction(float_value);
    return a;
}

float& operator-= (float& a, const Fraction& other){
    a = a+(other.getNumerate()/other.getDenom());
    return a;
}

Fraction& operator*= (Fraction& a, const float& other){
    float float_value = static_cast<float>(a.numerator/a.denominator) * other;
    a = Fraction(float_value);
    return a;
}

float& operator*= (float& a, const Fraction& other){
    a = a*(other.getNumerate()/other.getDenom());
    return a;
}

Fraction operator- (const Fraction& a, const float& other){
    return Fraction(0, 1);
}

Fraction operator- (const float& a, const Fraction& other){
    return Fraction(0, 1);
}

Fraction operator* (const Fraction& a, const float& other){
    return Fraction(0, 1);
}

Fraction operator* (const float& a, const Fraction& other){
    return Fraction(0, 1);
}

Fraction operator/ (const Fraction& a, const float& other){
    return Fraction(0, 1);
}

Fraction operator/ (const float& a, const Fraction& other){
    return Fraction(0, 1);
}

//-------------------------------------
// friend global binary operators
//-------------------------------------
Fraction operator- (const Fraction& c1, const Fraction& c2){
    return Fraction(0, 1);
}
Fraction operator* (const Fraction& c1, const Fraction& c2){
    return Fraction(0, 1);
}

Fraction operator/ (const Fraction& c1, const Fraction& c2){
    return Fraction(0, 1);
}

bool operator>= (const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator>= (const float& c1, const Fraction& c2){
    return 0;
}
bool operator>= (const Fraction& c1, const float& c2){
    return 0;
}

bool operator<= (const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator<= (const float& c1, const Fraction& c2){
    return 0;
}
bool operator<= (const Fraction& c1, const float& c2){
    return 0;
}


bool operator> (const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator> (const float& c1, const Fraction& c2){
    return 0;
}
bool operator> (const Fraction& c1, const float& c2){
    return 0;
}

bool operator< (const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator< (const float& c1, const Fraction& c2){
    return 0;
}
bool operator< (const Fraction& c1, const float& c2){
    return 0;
}


bool operator==(const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator== (const float& c1, const Fraction& c2){
    return 0;
}
bool operator== (const Fraction& c1, const float& c2){
    return 0;
}

bool operator!=(const Fraction& c1, const Fraction& c2){
    return 0;
}
bool operator!= (const float& c1, const Fraction& c2){
    return 0;
}
bool operator!= (const Fraction& c1, const float& c2){
    return 0;
}


//----------------------------------
// friend global IO operators
//----------------------------------
std::ostream& operator<< (std::ostream& output, const Fraction& c){
    return (output <<c.getNumerate() << '/' << c.getDenom() << ' ');
}

std::istream& operator>> (std::istream& input , Fraction& c){
    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------
    int new_re = 0, new_im = 0;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> new_re))||(!(input >> new_im))){

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } 

    return input;
}