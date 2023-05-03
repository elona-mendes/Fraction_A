// #pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>


#ifndef FRACTION_H
#define FRACTION_H

namespace ariel {};
    class Fraction{
      
        private:
            int numerator;
            int denominator; 
            // float _num;
                            
        public:

             // Constructor. Also works as a conversion from double and
            // also as a default ctor.
            Fraction (const int number = 0, int denum = 1): numerator(number), denominator(denum) {
                // this->numerator = number;
                // this->denominator = denum;
            }

            // Fraction (int num = 0, int denum = 1): _num(num/denum) {
            //     float n = num/denum;
            //     _num = std::round(num * 1000.0)/1000;
            // }
            // Fraction (float num): _num(num) {
            //     _num = std::round(num * 1000.0)/1000;
            // }


            // Fraction (float num) {
            //     float rounded_number = std::round(num * 1000.0);
            //     int gcd = std::gcd(rounded_number, 1000);
            //     _numerator = rounded_number/gcd;
            //     _denominator = 1000/gcd;
            // }
            // // Constructor. Also works as a conversion from double and
            // // also as a default ctor.
            // Fraction (const int& numerator= 0, const int& denumer= 1): _numerator(numerator), _denominator(denumer) {
            // }

            //-------------------------------------
            // getters
            //-------------------------------------
            int getNumerate() const {
                return numerator;
            }

            int getDenom() const {
                return denominator;
            }
            // int getNumerate(){
            //     float rounded_number = std::round(_num * 1000.0);
            //     int gcd = std::gcd(rounded_number, 1000);
            //     return rounded_number/gcd;
            // }
            // int getDenom(){
            //     float rounded_number = std::round(_num * 1000.0);
            //     int gcd = std::gcd(rounded_number, 1000);
            //     return 1000/gcd;
            // }
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


            // const Complex operator-(const Complex& other) const {
            //     return Complex(_re - other._re, _im - other._im);
            // }

            Fraction& operator-=(const Fraction& other) {
                numerator-= other.numerator;
                denominator-= other.denominator;
                return *this;
            }
            friend Fraction& operator-= (Fraction& a11, const float& other);
            friend float& operator-= (float& a11, const Fraction& other);

            // (a+bi)*(c+di) = 
            // (ac-bd) + (ad+bc)i
            Fraction& operator*=(const Fraction& other) {
                int new_numerate = numerator*other.numerator - denominator*other.denominator;
                int new_denomer = numerator*other.denominator + denominator*other.numerator; 
                this->numerator = new_numerate;
                this->denominator = new_denomer;
                // version with bug
                // _im = _re*other._im + _im*other._re; 
                // _re = _re*other._re - _im*other._im;
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
// }
#endif