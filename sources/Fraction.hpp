#include <iostream>
#include <stdexcept>
#include <numeric>

namespace ariel {};
class Fraction{

    private:
        int numerator;
        int denominator; 

    public:

         // Constructor. Also works as a conversion from double and
        // also as a default ctor.
        Fraction (const int number = 0, int denum = 1): numerator(number), denominator(denum) {
            // this->numerator = number;
            // this->denominator = denum;
        }

        //-------------------------------------
        // getters
        //-------------------------------------
        int getNumerate() const {
            return numerator;
        }

        int getDenom() const {
            return denominator;
        }

        // Logical NOT
        bool operator!() const {
            return numerator==0 && denominator==0;
        }

        Fraction operator-() const {
            return Fraction(-numerator , denominator);
        }

        //----------------------------------------
        // binary operators
        //----------------------------------------
        friend Fraction operator+ (const Fraction& a11, const Fraction& other);
        friend Fraction operator+ (const Fraction& a11, const float& other);
        friend Fraction operator+ (const float& a11, const Fraction& other);

        Fraction& operator+=(const Fraction& other) {
            numerator+= other.numerator;
            denominator+= other.denominator;
            return *this; // for call chaining
        }
        friend Fraction& operator+= (Fraction& a11, const float& other);
        friend float& operator+= (float& a11, const Fraction& other);

        friend Fraction operator- (const Fraction& c11, const Fraction& c22);
        friend Fraction operator- (const Fraction& a11, const float& other);
        friend Fraction operator- (const float& a11, const Fraction& other);

        friend Fraction operator* (const Fraction& c11, const Fraction& c22);
        friend Fraction operator* (const Fraction& a11, const float& other);
        friend Fraction operator* (const float& a11, const Fraction& other);

        // friend Fraction operator* (const float& c1, const Fraction& c2);
        friend Fraction operator/ (const Fraction& c11, const Fraction& c22);
        friend Fraction operator/ (const Fraction& a11, const float& other);
        friend Fraction operator/ (const float& a11, const Fraction& other);

        Fraction& operator-=(const Fraction& other) {
            numerator-= other.numerator;
            denominator-= other.denominator;
            return *this;
        }
        friend Fraction& operator-= (Fraction& a11, const float& other);
        friend float& operator-= (float& a11, const Fraction& other);

        Fraction& operator*=(const Fraction& other) {
            int new_numerate = numerator*other.numerator - denominator*other.denominator;
            int new_denomer = numerator*other.denominator + denominator*other.numerator; 
            this->numerator = new_numerate;
            this->denominator = new_denomer;
            return *this;
        }
        friend Fraction& operator*= (Fraction& a11, const float& other);
        friend float& operator*= (float& a11, const Fraction& other);

        //----------------------------------------

        // prefix increment:
        Fraction& operator++() {
            numerator++;
            return *this;
        }

        // postfix increment:
        Fraction operator++(int dummy_flag_for_postfix_increment) {
            Fraction copy = *this;
            numerator++;
            return copy;
        }

        // prefix reduction:
        Fraction& operator--() {
            numerator--;
            return *this;
        }

        // postfix reduction:
        Fraction operator--(int dummy_flag_for_postfix_increment) {
            Fraction copy = *this;
            numerator--;
            return copy;
        }

        friend bool operator>= (const Fraction& c11, const Fraction& c22);
        friend bool operator>= (const float& c11, const Fraction& c22);
        friend bool operator>= (const Fraction& c11, const float& c22);

        friend bool operator<= (const Fraction& c11, const Fraction& c22);
        friend bool operator<= (const float& c11, const Fraction& c22);
        friend bool operator<= (const Fraction& c11, const float& c22);

        friend bool operator> (const Fraction& c11, const Fraction& c22);
        friend bool operator> (const float& c11, const Fraction& c22);
        friend bool operator> (const Fraction& c11, const float& c22);

        friend bool operator< (const Fraction& c11, const Fraction& c22);
        friend bool operator< (const float& c11, const Fraction& c22);
        friend bool operator< (const Fraction& c11, const float& c22);


        friend bool operator==(const Fraction& c11, const Fraction& c22);
        friend bool operator== (const float& c11, const Fraction& c22);
        friend bool operator== (const Fraction& c11, const float& c22);

        friend bool operator!=(const Fraction& c11, const Fraction& c22);
        friend bool operator!= (const float& c11, const Fraction& c22);
        friend bool operator!= (const Fraction& c11, const float& c22);


        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend std::ostream& operator<< (std::ostream& output, const Fraction& c11);
        friend std::istream& operator>> (std::istream& input , Fraction& c11);
        //-------------------------------------
};
