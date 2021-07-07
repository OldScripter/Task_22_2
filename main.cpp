#include <iostream>
#include <map>

/**
 * @function Call next patient and remove him from registration book.
 * @param registrationBook Map with all patient names.
 */
void callNext(std::map<std::string, int>& registrationBook)
{
    std::map<std::string, int>::iterator it = registrationBook.begin();
    if (!registrationBook.empty())
    {
        std::cout << it->first << "\n";
        if (it->second > 1)
        {
            it->second--;
        }
        else
        {
            registrationBook.erase(it);
        }
    }
    else
    {
        std::cerr << "Registration book is empty. Add some patients.\n";
    }
}

/**
 * @function Register new patient in registration book.
 * @param [in] registrationBook Map of all patient names.
 * @param [in] name of patient to be registered in registration book.
 */
void registerPatient(std::map<std::string, int>& registrationBook, std::string& name)
{
    std::map<std::string, int>::iterator it = registrationBook.find(name);
    if (it != registrationBook.end())
    {
        it->second++;
    }
    else
    {
        registrationBook.insert(std::make_pair(name, 1));
    }
}

int main() {
    std::map<std::string, int> registration;
    do
    {
        std::cout << "Please enter the surname (or next, or exit):\n";
        std::string surname;
        std::cin >> surname;

        if (surname == "next")
        {
            callNext(registration);
        }
        else if (surname == "exit")
        {
            break;
        }
        else if (surname.length() == 0 || (surname.length() > 0 && surname[0] == ' '))
        {
            std::cerr << "Bad input. Try again.\n";
        }
        else
        {
            registerPatient(registration, surname);
        }
    } while (true);

    std::cout << "Program is finished." << "\n";
    return 0;
}