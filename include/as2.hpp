#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <random>
#include <memory>

namespace homework {

  // Random number generator setup
  inline std::random_device rd;
  inline std::mt19937 gen(rd()); 
  inline std::uniform_real_distribution<double> dist(0.0, 1.0);
  // to generate a random number between 0 and 1, use auto random_number = dist(gen);

  // Base class for entities
  // Has a implemented method getName()
  // Has a pure virtual method attack()
  // Has a pure virtual method clone() to support polymorphic copying
  // TO DO: Nothing, everything is implemented for you
  struct Entity {
      explicit Entity(const std::string name) : name{std::move(name)} {}
      virtual ~Entity() = default;
      virtual void attack() const = 0;
      std::string getName() const {
        return name;
      }

      virtual std::unique_ptr<Entity> clone() const = 0;
    protected:
      std::string name;
  };
  
  // as 2.1
  // Derived class Knight
  // TO DO: implement attack() and clone() and setWeapon()
  // Should have a private member variable for weapon (std::string)
  // Note: use std::make_unique in clone() and the this pointer to copy the object using chatGPT is okay for this purpose
  // The attack should use std::cout to print something like "<name> swings a <weapon>\n"
  // The setWeapon() method should set the weapon variable (the private member variable) 
class Knight : public Entity {
  private:
    std::string weapon = "Longsword"; //private
  public:
    void setWeapon(std::string w){
      weapon = w; //adjusted to work with Entity inheritance
    }
    Knight(std::string n) : Entity(n) {} //adjusted naming to work w/ Entity inheritance
    void attack() const override{
      std::cout << name << " attacks with a " << weapon << '\n'; //
    }
    std::unique_ptr<Entity> clone() const override{
      //review what i did in as1 regarding make_unique to use it here
      //basically used as1 to write:
      return std::make_unique<Knight>(*this);
      //chatgpt said i had to put (*this) to indicate i want to make a copy
    }
};
  // as 2.2
  // Derived class Sorcerer
  // TO DO: implement attack() and clone() and setAbility()
  // Same as the Knight class
class Sorcerer : public Entity {
  private:
    std::string ability = "Spell";
  public:
    void setAbility(std::string a){
      ability = a;
    }
    Sorcerer(std::string n) : Entity(n) {}
    void attack() const override{
      std::cout << name << " casts " << ability << '\n';
    }
    std::unique_ptr<Entity> clone() const override{
      return std::make_unique<Sorcerer>(*this);
    }
};
  // as 2.3 (This is a stretch goal, hand it in, and if it does not work, you can still pass the assignment)
  // Duel class template
  // TO DO: create a struct/class called Duel that is templated by two types (T1 and T2)
  // The constructor should take two pointers (T1* and T2*)
  // The fight() method should:
  // - call attack() on both entities
  // - randomly select one of the two entities as the winner (use the random number generator above)
  // - print to std::cout "<name> wins the duel!\n"
  // - return a std::unique_ptr<Entity> to the winner (use clone() to copy the object)

  template <typename T1, typename T2>
  class Duel{
    private: 
      T1* entity1;
      T2* entity2;
    public:
      Duel(T1* e1, T2* e2) : entity1(e1), entity2(e2) {}
      std::unique_ptr<Entity> fight(){
        entity1->attack();
        entity2->attack();

        int win = (dist(gen) < 0.5) ? 0 : 1;

        if (win==0) {
          std::cout << entity1->getName() << " wins the duel!" << '\n';
          return entity1->clone();
        }
        else {
          std::cout << entity2->getName() << " wins the duel!" << '\n';
          return entity2->clone();
        }
          } //had to rewrite my classes as inheriting from entity
          // totally misread instructions lol sorry!
          // simple fix i think but not sure if i did it right,
          // i think Knight and Sorcerer are entities now (at least i hope so)
      };
} // namespace homework

