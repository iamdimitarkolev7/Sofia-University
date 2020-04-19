#include <iostream>
#include <cstring>
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
            std::cout << "Name: " << users[i].getName() << std::endl;
            std::cout << "Email: " << users[i].getEmail() << std::endl;
            std::cout << "Age: " << users[i].getAge() << std::endl;
            std::cout << "ID: " << users[i].getID() << std::endl;
            std::cout << std::endl;
        }
    }
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
                        break;
                    }

                    counter++;
                }
                else if (counter == 1)
                {
                    strcpy(challenge, token);
                    Challenge chall(challenge);

                    if (!chall.isValid())
                        break;

                    counter++;
                }
                else
                {
                    strcpy(names[index], token);

                    if (!users.contains(names[index]))
                    {
                        std::cout << "\'" << names[index] << "\' not in users list" << std::endl;
                        break;
                    }

                    index++;
                }

                token = strtok(NULL, " ");
            }

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
        }
        else if (strcmp(input, "finish") == 0)
        {
            //finish
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
            //list_by
        }
        else if (strcmp(input, "load") == 0)
        {
            //load
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
