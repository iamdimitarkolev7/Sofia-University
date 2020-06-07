#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include "Payer.h"
#include "Person.h"
#include "Institution.h"
#include "Organization.h"
#include "Group.h"

void findMostPopularInstitution(std::vector<Group> groups, std::vector<Organization> organizations)
{
	std::string currentMostPopular = "";
	int maxNumberOfUsers = 0;

	for (int i = 0; i < groups.size(); i++)
	{
		if (maxNumberOfUsers < groups[i].getUsersCount())
		{
			maxNumberOfUsers = groups[i].getUsersCount();
			currentMostPopular = groups[i].getInstitutionName();
		}
	}

	for (int i = 0; i < organizations.size(); i++)
	{
		if (maxNumberOfUsers < organizations[i].getUsersCount())
		{
			currentMostPopular = organizations[i].getInstitutionName();
			maxNumberOfUsers = organizations[i].getUsersCount();
		}
	}

	std::cout << "The most popular institution is: " << currentMostPopular
		<< " with " << maxNumberOfUsers << " users!" << std::endl;
}

void clearInstitutions(std::vector<Group>& groups, std::vector<Organization>& organizations)
{
	std::vector<Group> resultGroup;
	std::vector<Organization> resultOrganization;

	for (int i = 0; i < groups.size(); i++)
		if (groups[i].isValid())
			resultGroup.push_back(groups[i]);

	for (int i = 0; i < organizations.size(); i++)
		if (organizations[i].isValid())
			resultOrganization.push_back(organizations[i]);

	groups.clear();
	organizations.clear();

	for (int i = 0; i < resultGroup.size(); i++)
		groups.push_back(resultGroup[i]);

	for (int i = 0; i < resultOrganization.size(); i++)
		organizations.push_back(resultOrganization[i]);
}

void manageGroupsAndUsers(std::vector<Person>& users, std::vector<Group>& groups)
{
	for (int i = 0; i < groups.size(); i++)
	{
		int currentGroupID = groups[i].getInstitutionID();

		if (!groups[i].isValid())
			continue;

		for (int j = 0; j < users.size(); j++)
		{
			int currentUserID = users[j].getInsuranceID();
			std::string currentUserName = users[j].getName();

			if ((currentGroupID >= 1000 && currentGroupID <= 1999) && (currentUserID >= 1000 && currentUserID <= 1999))
			{
				if (!groups[i].hasMember(currentUserName))
					groups[i].addMember(currentUserName);
			}
			else if ((currentGroupID >= 2000 && currentGroupID <= 2999) && (currentUserID >= 2000 && currentUserID <= 2999))
			{
				if (!groups[i].hasMember(currentUserName))
					groups[i].addMember(currentUserName);
			}
			else if ((currentGroupID >= 3000 && currentGroupID <= 3999) && (currentUserID >= 3000 && currentUserID <= 3999))
			{
				if (!groups[i].hasMember(currentUserName))
					groups[i].addMember(currentUserName);
			}
			else if ((currentGroupID >= 4000 && currentGroupID <= 4999) && (currentUserID >= 4000 && currentUserID <= 4999))
			{
				if (!groups[i].hasMember(currentUserName))
					groups[i].addMember(currentUserName);
			}
		}
	}
}

int main()
{
	std::function<bool(int, int)> rule = [](int personID, int groupID) -> bool {return abs(personID - groupID) < 1000; };

	Payer payer1("Gosho", 1500, rule), payer2("Pesho", 2500, rule), payer3("Mitko", 3500, rule), payer4("Kolev", 4500, rule);
	Person person1("Dimitar", &payer1), person2("Georgi", &payer1), person3("Nikolay", &payer1), person4("Teodor", &payer1);
	Person person5("Atanas", &payer2), person6("Kostadin", &payer2), person7("Martin", &payer2), person8("Dragan", &payer2);
	Person person9("Koicho", &payer3), person10("Kircho", &payer3), person11("Kalin", &payer3), person12("Miro", &payer3);
	Person person13("Radostin", &payer4), person14("Stoiko", &payer4), person15("Milko", &payer4), person16("Hristo", &payer4);

	std::vector<Person> allUsers = { person1, person2, person3, person4, person5, person6, person7, person8,
									person9, person10, person11, person12, person13, person14, person15, person16 };

	Group group1("Magic group", &payer1), group2("Elite group", &payer1), group3("Football group", &payer1);
	Group group4("Demo group", &payer2);
	Group group5("C++ group", &payer3), group6("Java group", &payer3);
	Group group7("HP group", &payer4);
	Group group8("Invalid group"), group9("Another invalid group");

	std::vector<Group> allGroups = { group1, group2, group3, group4, group5, group6, group7, group8, group9 };

	manageGroupsAndUsers(allUsers, allGroups);

	/*for (int i = 0; i < allGroups.size(); i++)
	{
		allGroups[i].print();
	}*/

	Organization org1("Adidas org." ,"7-E-24", &payer1), org2("Nike org.", "7-A-12", &payer2), org3("Puma org.", "groove street", &payer1);
	
	org1.addGroup(allGroups[0]); org1.addGroup(allGroups[6]);
	org2.addGroup(allGroups[1]); org2.addGroup(allGroups[5]); org2.addGroup(allGroups[7]); org2.addGroup(allGroups[8]);

	//Test compatibility
	if (org1.isCompatibleWith(org2))
		std::cout << org1.getInstitutionName() << " is compatible with " << org2.getInstitutionName() << std::endl;
	else
		std::cout << org1.getInstitutionName() << " is NOT compatible with " << org2.getInstitutionName() << std::endl;

	if (org1.isCompatibleWith(org3))
		std::cout << org1.getInstitutionName() << " is compatible with " << org3.getInstitutionName() << std::endl;
	else
		std::cout << org1.getInstitutionName() << " is NOT compatible with " << org3.getInstitutionName() << std::endl;
		
	std::vector<Organization> allOrganisations = { org1, org2, org3 };

	findMostPopularInstitution(allGroups, allOrganisations);

	//Test clear function
	std::cout << "Groups size: " << allGroups.size() << std::endl;
	std::cout << "Org size: " << allOrganisations.size() << std::endl;

	clearInstitutions(allGroups, allOrganisations);

	std::cout << "Groups size: " << allGroups.size() << std::endl;
	std::cout << "Org size: " << allOrganisations.size() << std::endl;

	//Test rule function
	if (payer1.applyRule(person1.getInsuranceID(), group7.getInstitutionID()))
		std::cout << person1.getName() << " is a member of " << group7.getInstitutionName() << "." << std::endl;
	else
		std::cout << person1.getName() << " is NOT a member of " << group7.getInstitutionName() << "." << std::endl;

	if (payer1.applyRule(person1.getInsuranceID(), group1.getInstitutionID()))
		std::cout << person1.getName() << " is a member of " << group1.getInstitutionName() << "." << std::endl;
	else
		std::cout << person1.getName() << " is NOT a member of " << group1.getInstitutionName() << "." << std::endl;

	if (payer3.applyRule(person3.getInsuranceID(), group9.getInstitutionID()))
		std::cout << person3.getName() << " is a member of " << group9.getInstitutionName() << "." << std::endl;
	else
		std::cout << person3.getName() << " is NOT a member of " << group9.getInstitutionName() << "." << std::endl;

	if (payer2.applyRule(person7.getInsuranceID(), group1.getInstitutionID()))
		std::cout << person7.getName() << " is a member of " << group1.getInstitutionName() << "." << std::endl;
	else
		std::cout << person7.getName() << " is NOT a member of " << group1.getInstitutionName() << "." << std::endl;

	return 0;
}