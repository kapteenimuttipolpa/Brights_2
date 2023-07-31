#include <iostream>
#include <memory>
#include <string>
#include <vector>
enum class species {
    Dog,
    Cat,
    None,
};
namespace animals {
class animal {
  public:
    animal() = default;
    virtual ~animal() = default;
    virtual void make_noise();

  private:
    species m_type;
    std::string m_name;
};

class dog : public animal {
  public:
    dog(species type, std::string &name);
    virtual void make_noise() override;

  private:
    species m_type;
    std::string m_name;
};

class cat : public animal {
  public:
    cat(species type, std::string &name);
    virtual void make_noise() override;

  private:
    species m_type;
    std::string m_name;
};
using animal_vec = std::vector<std::unique_ptr<animal>>;
animal_vec read_from_file(const std::string &file_name);
void print_animals(const animal_vec &all_animals);
} // namespace animals
