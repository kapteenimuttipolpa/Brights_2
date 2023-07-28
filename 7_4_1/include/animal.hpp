#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class animal {
  public:
    virtual ~animal() = default;
    virtual void make_sound() const = 0;
    virtual bool is_fluffy() const;
    virtual bool is_venomous() const;
    std::string name = "";

  protected:
    animal() = default;

  private:
};

class dog : public animal {
  public:
    dog();
    virtual void make_sound() const override;

  private:
};

class cat : public animal {
  public:
    cat();
    virtual void make_sound() const override;

  private:
};

class monke : public animal {
  public:
    monke();
    virtual void make_sound() const override;

  private:
};

class snake : public animal {
  public:
    snake();
    virtual void make_sound() const override;
    virtual bool is_fluffy() const override;
    virtual bool is_venomous() const override;

  private:
};

void info(const animal &any_animal);
static std::vector<std::unique_ptr<animal>> all_animals;
void print_all();
#endif // animal_hpp