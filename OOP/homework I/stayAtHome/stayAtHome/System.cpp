#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include "System.h"
#include "User.h"
#include "VectorUser.h"
#include "ChallengesArray.h"

ChallengesArray uniqueChallenges;
VectorUser users;
int id = 1;

const int EMAIL_LENGTH = 100;
const int AGE_LENGTH = 10;
const int NAME_LENGTH = 1024;
const int INPUT_LENGTH = 10000;
const int ACTION_LENGTH = 128;
const int CHALLENGE_LENGTH = 31;

System& System::i()
{
	static System instance;
	return instance;
}

System::System()
{
	std::cout << "Start of the program: " << std::endl;
}

System::~System()
{
	std::cout << "End of the program!" << std::endl;
}

void System::registration(const User& user)
{
    users.push(user);
    std::cout << "Successful registration!" << std::endl;
}

void System::profile_info(const char* _name)
{
    for (int i = 0; i < users.getSize(); i++)
    {
        if (strcmp(_name, users[i].getName()) == 0)
        {
            std::cout << std::endl;
            std::cout << "Name: " << users[i].getName() << std::endl;
            std::cout << "Email: " << users[i].getEmail() << std::endl;
            std::cout << "Age: " << users[i].getAge() << std::endl;
            std::cout << "ID: " << users[i].getID() << std::endl;
            std::cout << std::endl;
        }
    }
}

void System::list_by(const char* sort)
{
    if (strcmp(sort, "newest") == 0)
    {
        char status[512];
        std::fill_n(status, 512, 0);
        std::cout << "Tag\t\tRating\tStatus\t\tTotal\tDone\t" << std::endl;

        for (int i = 0; i < uniqueChallenges.getSize(); i++)
        {
            if (uniqueChallenges[i].getOcc() == 1)
                strcpy(status, "new");
            else if (uniqueChallenges[i].getOcc() >= 2 && uniqueChallenges[i].getOcc() <= 10)
            {
                strcpy(status, "quite recently");
                std::cout << uniqueChallenges[i].getName() << "\t\t" << uniqueChallenges[i].getRating() << "\t"
                    << status << "\t" << uniqueChallenges[i].getOcc() << "\t" << uniqueChallenges[i].getNumOfRaters() << std::endl;
                return;
            }
            else if (uniqueChallenges[i].getOcc() > 10)
                strcpy(status, "old");

            std::cout << uniqueChallenges[i].getName() << "\t\t" << uniqueChallenges[i].getRating() << "\t"
                << status << "\t\t" << uniqueChallenges[i].getOcc() << "\t" << uniqueChallenges[i].getNumOfRaters() << std::endl;
        }
    } 
    else if (strcmp(sort, "oldest") == 0)
    {
        char status[512];
        std::fill_n(status, 512, 0);
        std::cout << "Tag\t\tRating\tStatus\t\tTotal\tDone\t" << std::endl;

        for (int i = uniqueChallenges.getSize() - 1; i >= 0; i--)
        {
            if (uniqueChallenges[i].getOcc() == 1)
                strcpy(status, "new");
            else if (uniqueChallenges[i].getOcc() >= 2 && uniqueChallenges[i].getOcc() <= 10)
            {
                strcpy(status, "quite recently");
                std::cout << uniqueChallenges[i].getName() << "\t\t" << uniqueChallenges[i].getRating() << "\t"
                    << status << "\t" << uniqueChallenges[i].getOcc() << "\t" << uniqueChallenges[i].getNumOfRaters() << std::endl;
                return;
            }
            else if (uniqueChallenges[i].getOcc() > 10)
                strcpy(status, "old");

            std::cout << uniqueChallenges[i].getName() << "\t\t" << uniqueChallenges[i].getRating() << "\t"
                << status << "\t\t" << uniqueChallenges[i].getOcc() << "\t" << uniqueChallenges[i].getNumOfRaters() << std::endl;
        }
    }
    /*else if (strcmp(sort, "most_popular") == 0)
    {
        char status[512];
        std::fill_n(status, 512, 0);
        std::cout << "Tag\t\tRating\tStatus\t\tTotal\tDone\t" << std::endl;

        for (int i = uniqueChallenges.getSize() - 1; i >= 0; i--)
        {
            if (uniqueChallenges[i].getOcc() == 1)
                strcpy(status, "new");
            else if (uniqueChallenges[i].getOcc() >= 2 && uniqueChallenges[i].getOcc() <= 10)
                strcpy(status, "quite recently");
            else if (uniqueChallenges[i].getOcc() > 10)
                strcpy(status, "old");

            std::cout << uniqueChallenges[i].getName() << "\t\t\t" << uniqueChallenges[i].getRating() << "\t"
                << status << "\t\t" << uniqueChallenges[i].getOcc() << "\t" << uniqueChallenges[i].getNumOfRaters() << std::endl;
        }
    }*/
    else
    {
        std::cout << "Invalid sort method!" << std::endl;
    }

    return;

}

void System::help()
{
    std::cout << " - List of commands - " << std::endl
        << "\tregistration <name> <age> <email> - Registrates user." << std::endl
        << "\tchallenge <name> <challenge name> <names> - Challenge users." << std::endl
        << "\tfinish <challenge> <userID> <rating> - Finish a challenge." << std::endl
        << "\tprofile_info <name> - Shows all data about the user." << std::endl
        << "\tlist_by <sort> - List sorted users." << std::endl
        << "\tload users.txt - Loads data about all registered users." << std::endl
        << "\tload challenges.bin - Loads data about all regisered challenges." << std::endl
        << "\thelp - Shows info about the commands." << std::endl
        << "\tend - Terminates the program." << std::endl;
}

bool System::isNumber(char* s)
{
    for (int i = 0; i < strlen(s); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int System::charToInt(char* s)
{
    int startIndex = 0;
    bool isNegative = false;

    if (s[0] == '-')
    {
        isNegative = true;
        startIndex = 1;
    }

    int length = strlen(s);
    int result = 0;

    for (int i = startIndex; i < length; i++)
    {
        int currentDigit = s[i] - '0';
        result += currentDigit * std::pow(10, length - i - 1);
    }

    if (isNegative)
    {
        return -result;
    }

    return result;
}

double System::charToDouble(char* s)
{
    int length = strlen(s);
    double result = 0, ind = 10;
    int index = indexOf(s, '.');
    int startIndex = 0;
    bool isNegative = false;

    if (s[0] == '-')
    {
        isNegative = true;
        startIndex = 1;
    }

    if (index == 0)
    {
        return (double)charToInt(s);
    }

    for (int i = startIndex; i < length; i++)
    {
        if (index > i)
        {
            int currentDigit = s[i] - '0';
            result += currentDigit * std::pow(10, index - i - 1);
        }
        else if (index < i)
        {
            int currentDigit = s[i] - '0';
            double adding = currentDigit / ind;
            result += adding;
            ind *= 10;
        }
    }

    if (isNegative)
    {
        return -result;
    }

    return result;
}

int System::indexOf(char* s, char sym)
{
    int index = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == sym)
        {
            index = i;
        }
    }

    return index;
}

void System::run()
{
    char input[INPUT_LENGTH];

    for (;;)
    {
        std::cin.getline(input, INPUT_LENGTH);
        char action[ACTION_LENGTH];
        char* token = strtok(input, " ");
        strcpy(action, token);

        if (strcmp(action, "registration") == 0)
        {
            char name[NAME_LENGTH], age[AGE_LENGTH], email[EMAIL_LENGTH];
            bool isName = true;
            token = strtok(NULL, " ");

            std::fill_n(name, NAME_LENGTH, 0), std::fill_n(age, AGE_LENGTH, 0), std::fill_n(email, EMAIL_LENGTH, 0);

            while (token)
            {
                if (isName)
                {
                    strcpy(name, token);
                    isName = false;
                }
                else
                {
                    if (isNumber(token))
                    {
                        strcpy(age, token);
                    }
                    else
                    {
                        strcpy(email, token);
                    }
                }

                token = strtok(NULL, " ");
            }

            if (strlen(age) == 0)
            {
                strcpy(age, "Unknown");
            }

            if (strlen(email) == 0)
            {
                strcpy(email, "Unknown");
            }

            User user(name, age, email, id);
            
            if (user.isValid())
            {
                registration(user);
                id++;
            }
            
        }
        else if (strcmp(input, "challenge") == 0)
        {
            char name1[NAME_LENGTH], challenge[CHALLENGE_LENGTH], names[20][NAME_LENGTH];
            token = strtok(NULL, " ");
            bool continueProgram = true;
            int counter = 0, index = 0;
            std::fill_n(name1, NAME_LENGTH, 0), std::fill_n(challenge, CHALLENGE_LENGTH, 0);
            for (int i = 0; i < 20; i++)
                std::fill_n(names[i], NAME_LENGTH, 0);

            while (token)
            {
                if (counter == 0)
                {
                    strcpy(name1, token);
                    if (!users.contains(name1))
                    {
                        std::cout << "Name \'" << name1 << "\' is not in the user list!" << std::endl;
                        continueProgram = false;
                    }

                    counter++;
                }
                else if (counter == 1)
                {
                    strcpy(challenge, token);
                    Challenge chall(challenge);

                    if (!chall.isValid())
                        continueProgram = false;

                    counter++;
                }
                else
                {
                    strcpy(names[index], token);

                    if (!users.contains(names[index]))
                    {
                        std::cout << "Name \'" << names[index] << "\' not in users list" << std::endl;
                        continueProgram = false;
                    }

                    index++;
                }

                token = strtok(NULL, " ");
            }

            if (continueProgram)
            {
                Challenge _challenge(challenge);

                if (!uniqueChallenges.contains(challenge))
                {
                    uniqueChallenges.push(_challenge);
                }
                else
                {
                    for (int i = 0; i < uniqueChallenges.getSize(); i++)
                    {
                        if (strcmp(uniqueChallenges[i].getName(), challenge) == 0)
                        {
                            uniqueChallenges[i].incrementOcc();
                        }
                    }
                }

                for (int i = 0; i < index; i++)
                {
                    for (int j = 0; j < users.getSize(); j++)
                    {
                        if (strcmp(names[i], users[j].getName()) == 0)
                        {
                            users[j].addChallenge(_challenge);
                        }
                    }
                }

                std::cout << "Successfully challenged!" << std::endl;
            }
        }
        else if (strcmp(input, "finish") == 0)
        {
            token = strtok(NULL, " ");
            int counter = 0;
            char challName[CHALLENGE_LENGTH], _userId[5], _grade[10];
            std::fill_n(challName, CHALLENGE_LENGTH, 0), std::fill_n(_userId, 5, 0), std::fill_n(_grade, 10, 0);

            strcpy(challName, token);
            int userId = 0;
            double grade = 0;
            bool isValidId = false, continueProgram = true;

            while (token)
            {
                if (counter == 0)
                {
                    counter++;
                    if (!uniqueChallenges.contains(challName))
                    {
                        std::cout << "No such challenge!" << std::endl;
                        continueProgram = false;
                    }
                }
                else if (counter == 1)
                {
                    counter++;
                    strcpy(_userId, token);

                    userId = charToInt(_userId);

                    for (int i = 0; i < users.getSize(); i++)
                    {
                        if (users[i].getID() == userId)
                        {
                            isValidId = true;
                        }
                    }

                    if (!isValidId)
                    {
                        std::cout << "No user with such ID!" << std::endl;
                        continueProgram = false;
                    }
                }
                else
                {
                    strcpy(_grade, token);
                    grade = charToDouble(_grade);

                    std::cout << "Grade: " << grade << std::endl;

                    if (grade < -5.0 || grade > 10.0)
                    {
                        std::cout << "Invalid rating! rating must be in [-5; 10] interval!" << std::endl;
                        continueProgram = false;
                    }
                }

                token = strtok(NULL, " ");
            }

            if (continueProgram)
            {
                /*
                for (int i = 0; i < users.getSize(); i++)
                {
                    if (userId == users[i].getID())
                    {
                        if (!(users[i].getUnfinished()).contains(challName))
                        {
                            std::cout << "Selected user has no data for this challenge!" << std::endl;
                            break;
                        }
                        else
                        {
                            //users[i].removeChallenge(challName);
                        }
                    }
                }
                */

                for (int i = 0; i < uniqueChallenges.getSize(); i++)
                {
                    if (strcmp(uniqueChallenges[i].getName(), challName) == 0)
                    {
                        uniqueChallenges[i].updateData(grade);
                    }
                }
            }

        }
        else if (strcmp(input, "profile_info") == 0)
        {
            token = strtok(NULL, " ");
            char name[NAME_LENGTH];
            std::fill_n(name, NAME_LENGTH, 0);
            strcpy(name, token);

            profile_info(name);
        }
        else if (strcmp(input, "list_by") == 0)
        {
            token = strtok(NULL, " ");
            char sort[512];
            std::fill_n(sort, 512, 0);
            strcpy(sort, token);

            list_by(sort);
        }
        else if (strcmp(input, "load") == 0)
        {
            std::fstream file;

            token = strtok(NULL, " ");
            char fullFileName[512], fileName[16], fileExt[16];
            strcpy(fullFileName, token);

            token = strtok(fullFileName, ".");
            strcpy(fileName, token);

            token = strtok(NULL, ".");
            strcpy(fileExt, token);

            if (strcmp(fileExt, "txt") == 0)
            {
                
            }

            else if (strcmp(fileExt, "bin") == 0)
            {

            }

            else
            {
                std::cout << "Wrong file extension!" << std::endl;
            }
        }
        else if (strcmp(input, "help") == 0)
        {
            help();
        }
        else if (strcmp(input, "end") == 0)
        {
            break;
        }
        else
        {
            std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
        }
    }
}
