#include <iostream>
// Virtual functions test.


class Animal {
public:
  // This function can always be overriden even if it's not virtual.
  // - Non virtual version:
  // void eat() { std::cout << "Animal eats!\n"; }
  // - Virtual version:
  virtual void eat() { std::cout << "Animal eats!\n"; }
};

class Dog : Animal {
public:
  void eat() { std::cout << "Dog eats!\n"; }
};

int main() {
  Animal myanimal;
  myanimal.eat();
  Dog mydog;
  mydog.eat();

  std::cout << "# Now using Animal pointers:\n";
  Animal *animalPtr1;
  Animal *animalPtr2;
  animalPtr1 = &myanimal;
  animalPtr2 = (Animal *)&mydog;

  animalPtr1->eat();
  // This will actaully call Animal eat too, not dog eat unless eat is virtual:
  animalPtr2->eat();

  std::cout << "# Now using Dog pointers:\n";
  Dog *dogPtr1;
  Dog *dogPtr2;
  dogPtr1 = &mydog;
  dogPtr2 = (Dog *)&myanimal;
  dogPtr1->eat();
  dogPtr2->eat();
}