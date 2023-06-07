#include<iostream>
struct Person{

    public: 
        void set_age(int a){
            age_ = a; // a muuttujan elinkaari päättyy funktion päätyttyä
                      // sitä käytetään vain päivittämään privaattia muuttujaa
        }
        int get_age(){
            return age_; // tämä funktio palauttaa privaatin muuttujan arvon.
        }
    private:
        int age_; //ikä on määritelty luokan privaatissa
                  // joten sen elinkaari päättyy vasta kun olion elinkaari päättyy
};

int main()
{
    Person bob;
    bob.set_age(10);
    std::cout << bob.get_age();
 return 0;
}
/*Exercise 7:
Create a program with a class that has a private member variable.
 Implement getter and setter functions for the private variable and 
demonstrate how the lifetime of the private variable is controlled by the class.*/