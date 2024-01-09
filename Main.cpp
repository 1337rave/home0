#include <iostream>
#include <string>

// ������� ���� "������� �������"
class Pet {
protected:
    std::string name;
    int age;

public:
    // ����������� ����� "������� �������"
    Pet(const std::string& petName, int petAge) : name(petName), age(petAge) {}

    // ����� ��� ��������� ���������� ��� �������
    void displayInfo() const {
        std::cout << "Name: " << name << "\nAge: " << age << " years" << std::endl;
    }
};

// �������� ���� "������"
class Dog : public Pet {
private:
    std::string breed;

public:
    // ����������� ����� "������"
    Dog(const std::string& dogName, int dogAge, const std::string& dogBreed)
        : Pet(dogName, dogAge), breed(dogBreed) {}

    // ����� ��� ��������� ���������� ��� ������
    void displayInfo() const {
        Pet::displayInfo();  // ������ ������ �������� �����
        std::cout << "Breed: " << breed << std::endl;
    }
};

// �������� ���� "ʳ���"
class Cat : public Pet {
private:
    std::string color;

public:
    // ����������� ����� "ʳ���"
    Cat(const std::string& catName, int catAge, const std::string& catColor)
        : Pet(catName, catAge), color(catColor) {}

    // ����� ��� ��������� ���������� ��� ����
    void displayInfo() const {
        Pet::displayInfo();  // ������ ������ �������� �����
        std::cout << "Color: " << color << std::endl;
    }
};

// �������� ���� "������"
class Parrot : public Pet {
private:
    std::string species;

public:
    // ����������� ����� "������"
    Parrot(const std::string& parrotName, int parrotAge, const std::string& parrotSpecies)
        : Pet(parrotName, parrotAge), species(parrotSpecies) {}

    // ����� ��� ��������� ���������� ��� ������
    void displayInfo() const {
        Pet::displayInfo();  // ������ ������ �������� �����
        std::cout << "Species: " << species << std::endl;
    }
};

int main() {
    // ��������� ��'���� ����� ������� ������
    Dog myDog("Loki", 3, "Golden Retriever");
    Cat myCat("Michael", 2, "Tabby");
    Parrot myParrot("Polly", 1, "Amazon");

    // ��������� ���������� ��� ����� �������
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
