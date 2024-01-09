#include <iostream>
#include <cstring>

class String {
protected:
    char* str;

public:
    String() : str(nullptr) {}

    String(const char* cstr) {
        if (cstr) {
            size_t len = strlen(cstr) + 1;
            str = new char[len];
            strcpy_s(str, len, cstr);
        } else {
            str = nullptr;
        }
    }

    String(const String& other) {
        if (other.str) {
            size_t len = strlen(other.str) + 1;
            str = new char[len];
            strcpy_s(str, len, other.str);
        } else {
            str = nullptr;
        }
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            if (other.str) {
                size_t len = strlen(other.str) + 1;
                str = new char[len];
                strcpy_s(str, len, other.str);
            } else {
                str = nullptr;
            }
        }
        return *this;
    }

    int length() const {
        return (str) ? static_cast<int>(strlen(str)) : 0;
    }

    void clear() {
        delete[] str;
        str = nullptr;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String result;
        size_t len1 = (str) ? strlen(str) : 0;
        size_t len2 = (other.str) ? strlen(other.str) : 0;
        size_t len = len1 + len2 + 1;

        result.str = new char[len];
        strcpy_s(result.str, len, (str) ? str : "");
        strcat_s(result.str, len, (other.str) ? other.str : "");

        return result;
    }

    String& operator+=(const String& other) {
        size_t len1 = (str) ? strlen(str) : 0;
        size_t len2 = (other.str) ? strlen(other.str) : 0;
        size_t len = len1 + len2 + 1;

        char* temp = new char[len];
        strcpy_s(temp, len, (str) ? str : "");
        strcat_s(temp, len, (other.str) ? other.str : "");

        delete[] str;
        str = temp;

        return *this;
    }

    bool operator==(const String& other) const {
        return (strcmp((str) ? str : "", (other.str) ? other.str : "") == 0);
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& obj) {
        if (obj.str) {
            os << obj.str;
        }
        return os;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* cstr) : String() {
        if (cstr) {
            size_t len = strlen(cstr);
            bool valid = true;
            for (size_t i = 0; i < len; ++i) {
                if (cstr[i] != '0' && cstr[i] != '1') {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                size_t len = strlen(cstr) + 1;
                str = new char[len];
                strcpy_s(str, len, cstr);
            }
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    void changeSign() {
        size_t len = length();
        for (size_t i = 0; i < len; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result;
        size_t len1 = (str) ? strlen(str) : 0;
        size_t len2 = (other.str) ? strlen(other.str) : 0;
        size_t len = len1 + len2 + 1;

        result.str = new char[len];
        strcpy_s(result.str, len, (str) ? str : "");
        strcat_s(result.str, len, (other.str) ? other.str : "");

        return result;
    }

    BitString& operator+=(const BitString& other) {
        size_t len1 = (str) ? strlen(str) : 0;
        size_t len2 = (other.str) ? strlen(other.str) : 0;
        size_t len = len1 + len2 + 1;

        char* temp = new char[len];
        strcpy_s(temp, len, (str) ? str : "");
        strcat_s(temp, len, (other.str) ? other.str : "");

        delete[] str;
        str = temp;

        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }

    friend std::ostream& operator<<(std::ostream& os, const BitString& obj) {
        if (obj.str) {
            os << obj.str;
        }
        return os;
    }
};

int main() {
    String str1("Hello");
    String str2(" World");
    String str3 = str1 + str2;

    std::cout << "Concatenated String: " << str3 << std::endl;

    BitString bitStr1("1101");
    BitString bitStr2("1010");
    BitString bitStr3 = bitStr1 + bitStr2;

    std::cout << "Binary String 1: " << bitStr1 << std::endl;
    std::cout << "Binary String 2: " << bitStr2 << std::endl;
    std::cout << "Sum of Binary Strings: " << bitStr3 << std::endl;

    return 0;
}
