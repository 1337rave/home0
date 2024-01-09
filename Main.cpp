#include <iostream>
#include <string>

// Базовий клас "Домашня тварина"
class Pet {
protected:
    std::string name;
    int age;

public:
    // Конструктор класу "Домашня тварина"
    Pet(const std::string& petName, int petAge) : name(petName), age(petAge) {}

    // Метод для виведення інформації про тварину
    void displayInfo() const {
        std::cout << "Name: " << name << "\nAge: " << age << " years" << std::endl;
    }
};

// Похідний клас "Собака"
class Dog : public Pet {
private:
    std::string breed;

public:
    // Конструктор класу "Собака"
    Dog(const std::string& dogName, int dogAge, const std::string& dogBreed)
        : Pet(dogName, dogAge), breed(dogBreed) {}

    // Метод для виведення інформації про собаку
    void displayInfo() const {
        Pet::displayInfo();  // Виклик методу базового класу
        std::cout << "Breed: " << breed << std::endl;
    }
};

// Похідний клас "Кішка"
class Cat : public Pet {
private:
    std::string color;

public:
    // Конструктор класу "Кішка"
    Cat(const std::string& catName, int catAge, const std::string& catColor)
        : Pet(catName, catAge), color(catColor) {}

    // Метод для виведення інформації про кішку
    void displayInfo() const {
        Pet::displayInfo();  // Виклик методу базового класу
        std::cout << "Color: " << color << std::endl;
    }
};

// Похідний клас "Папуга"
class Parrot : public Pet {
private:
    std::string species;

public:
    // Конструктор класу "Папуга"
    Parrot(const std::string& parrotName, int parrotAge, const std::string& parrotSpecies)
        : Pet(parrotName, parrotAge), species(parrotSpecies) {}

    // Метод для виведення інформації про папугу
    void displayInfo() const {
        Pet::displayInfo();  // Виклик методу базового класу
        std::cout << "Species: " << species << std::endl;
    }
};

int main() {
    // Створення об'єктів різних домашніх тварин
    Dog myDog("Loki", 3, "Golden Retriever");
    Cat myCat("Michael", 2, "Tabby");
    Parrot myParrot("Polly", 1, "Amazon");

    // Виведення інформації про кожну тварину
    std::cout << "Dog Information:\n";
    myDog.displayInfo();
    std::cout << "\n";

    std::cout << "Cat Information:\n";
    myCat.displayInfo();
    std::cout << "\n";

    std::cout << "Parrot Information:\n";
    myParrot.displayInfo();

    return 0;
}
