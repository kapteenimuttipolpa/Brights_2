#pragma once

class Animal{
    public:
      Animal();
      ~Animal();
      void sleep();
      void set_age(int age){
        if(age >= 0){
            m_age = age; 
        }
        else m_age = 0;
      }

    private:
      int m_age;
};

class Wings {
  public:
    Wings();
    ~Wings();
    void flap();
};
class Eyes{
    public:
      Eyes();
      ~Eyes();
      void blink();
};
class Bird : public Animal{
    public:
      Bird();
      ~Bird();
      Eyes eyes;
      Wings wings;
      void eat();
    private:
};
class Parrot : public Bird{
    public:
      Parrot();
      ~Parrot();
      void talk();
    private:
};
