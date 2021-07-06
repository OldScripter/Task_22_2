#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> registration;
    do
    {
        std::cout << "Please enter the surname (or next, or exit):\n";
        std::string surname;
        std::cin >> surname;

        if (surname == "next")
        {
            std::map<std::string, int>::iterator it = registration.begin();
            if (!registration.empty())
            {
                std::cout << it->first << "\n";
                if (it->second > 1)
                {
                    it->second--;
                }
                else
                {
                    registration.erase(it);
                }
            }
            else
            {
                std::cerr << "Registration book is empty. Add some patients.\n";
            }

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
            std::map<std::string, int>::iterator it = registration.find(surname);
            if (it != registration.end())
            {
                it->second++;
            }
            else
            {
                registration.insert(std::make_pair(surname, 1));
            }
        }
    } while (true);

    std::cout << "Program is finished." << "\n";
    return 0;
}