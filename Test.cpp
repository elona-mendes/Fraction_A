#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Init without parameters") {
    Fraction p;
    CHECK(p.getDenom() == 1);
    CHECK(p.getNumerate() == 0);
}

TEST_CASE("Init with parameters") {
    Fraction a(5, 3);

    CHECK(a.getDenom() == 3);
    CHECK(a.getNumerate() == 5);
} 

TEST_CASE("Test arithmetic operators"){
    Fraction a(5, 3); 
    Fraction b(7, 9);

    Fraction plus = a+b;
    CHECK(plus.getNumerate() == 22);
    CHECK(plus.getDenom() == 9);

    Fraction minus = a-b;
    CHECK(minus.getNumerate() == 8);
    CHECK(minus.getDenom() == 9);
    Fraction minus1 = b-a;
    CHECK(minus1.getNumerate() == -8);
    CHECK(minus1.getDenom() == 9);

    Fraction div = a/b;
    CHECK(div.getNumerate() == 15);
    CHECK(div.getDenom() == 7);
    Fraction div1 = b/a;
    CHECK(div1.getNumerate() == 7);
    CHECK(div1.getDenom() == 15);

    Fraction mul = a*b;
    CHECK(mul.getNumerate() == 35);
    CHECK(mul.getDenom() == 27);
}

TEST_CASE("Test arithmetic operators with float"){
    Fraction a(5, 7); 

    Fraction plus = a+0.5;
    CHECK(plus.getNumerate() == 17);
    CHECK(plus.getDenom() == 14);
    Fraction plus1 = 0.5+a;
    CHECK(plus1.getNumerate() == 17);
    CHECK(plus1.getDenom() == 14);

    Fraction minus = a-0.5;
    CHECK(minus.getNumerate() == 3);
    CHECK(minus.getDenom() == 14);
    Fraction minus1 = 0.5-a;
    CHECK(minus1.getNumerate() == -3);
    CHECK(minus1.getDenom() == 14);

    Fraction div = a/3.415;
    CHECK(div.getNumerate() == 1000);
    CHECK(div.getDenom() == 4781);
    //take just the 3 digit after the dot. 
    Fraction div1 = a/3.415794;
    CHECK(div1.getNumerate() == 1000);
    CHECK(div1.getDenom() == 4781);
    Fraction div2 = 3.2/a;
    CHECK(div2.getNumerate() == 112);
    CHECK(div2.getDenom() == 25);

    Fraction mul = a*0.01;
    CHECK(mul.getNumerate() == 1);
    CHECK(mul.getDenom() == 140);
    Fraction mul1 = 0.3*a;
    CHECK(mul1.getNumerate() == 3);
    CHECK(mul1.getDenom() == 14);
}

TEST_CASE("Test logical operators"){
    Fraction a(5, 3); 
    Fraction a1(10, 6);
    Fraction b(7, 9);

    //return true(1) for a>b because 5/3 is bigger than 7/9 and false for b>a
    CHECK((a>b) == 1);
    CHECK((b>a) == 0);
    CHECK((b<a) == 1);
    CHECK((a<b) == 0);

    //return false because there aren't equals
    CHECK((b==a) == 0);
    CHECK((b==a1) == 0);
    //return true נecause they are equal in their reduced form
    CHECK((a1==a) == 1);

    CHECK((a>=b) == 1);
    CHECK((b<=a) == 1);
    CHECK((b>=a) == 0);
    CHECK((a<=b) == 0);
    //a1 and a are equals so it should return true for the both
    CHECK((a1>=a) == 1);
    CHECK((a1<=a) == 1);

    CHECK((a!=b) == 1);
    CHECK((a1!=a) == 0);  
    CHECK((b!=a) == 1);
    CHECK((a!=a1) == 0);  
}

TEST_CASE("Test logical operators with float"){
    Fraction a(5, 7); 

    CHECK((a>0.5) == 1);
    CHECK((a<2.1324) == 1);
    CHECK((0.5<a) == 1);
    CHECK((2.1324<a) == 1);

    CHECK((a==0.714) == 1);
    CHECK((0.714455==a) == 1);
    CHECK((a==0.71) == 0);
    CHECK((0.714==a) == 1);
    CHECK((0.7==a) == 0);


    CHECK((a>=0.1) == 1);
    CHECK((7.3<=a) == 0);
    CHECK((0.1>=a) == 0);
    CHECK((a<=7.3) == 1);
    //a1 and a are equals so it should return true for the both
    CHECK((a<=0.714) == 1);
    CHECK((0.714>=a) == 1);

    CHECK((0.713!=a) == 1);
    CHECK((a!=0.713) == 1);
    CHECK((a!=0.714) == 0); 
}

TEST_CASE("TEST ++ AND --"){
    Fraction a(3, 4);
    Fraction plusA = ++a;
    CHECK(a.getNumerate() == 7);
    CHECK(a.getDenom() == 4);
    CHECK(plusA.getNumerate() == 7);
    CHECK(plusA.getDenom() == 4);

    Fraction plusA1 = a++;
    CHECK(a.getNumerate() == 11);
    CHECK(a.getDenom() == 4);
    CHECK(plusA1.getNumerate() == 7);
    CHECK(plusA1.getDenom() == 4);   

    Fraction b(3, 4);
    Fraction minusB = --b;
    CHECK(b.getNumerate() == -1);
    CHECK(b.getDenom() == 4);
    CHECK(minusB.getNumerate() == -1);
    CHECK(minusB.getDenom() == 4);

    Fraction minusB1 = b--;
    CHECK(b.getNumerate() == -5);
    CHECK(b.getDenom() == 4);
    CHECK(minusB1.getNumerate() == -1);
    CHECK(minusB1.getDenom() == 4);   

}

TEST_CASE("Test cin and cout") {
    //helped by chatgpt
    Fraction a(1, 2), b(3, 4);

    string expected_output = "a: 1/2 b: 3/4";
    string unexpected_output = "a: b:";
    
    // Save the output to a string variable using a stringstream object
    stringstream output_stream;
    output_stream << "a: " << a << "b: " << b << endl;
    string program_output = output_stream.str();
    CHECK(program_output != unexpected_output);
    CHECK(program_output == expected_output);

    //CHECK INPUT
    // string expected_input = "hello";
    // string user_input;
    
    // // Prompt the user for input
    // cout << "Please enter the word 'hello': ";
    // cin >> user_input;
    // CHECK(user_input == expected_input);
}