// main.cpp

// Declaration of the main file

// Created by Shengwei Jian April 2022

#include "BBallTeam.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void displayAll(vector<BasketballTourney::BBallTeam> myTeamVector);//display all existing team from myTeamVector
void addTeam(vector<BasketballTourney::BBallTeam> &myTeamVector,string name);//add a new team to myTeamVector
void modifyTeam(vector<BasketballTourney::BBallTeam> &myTeamVector,string name);//modify a team from myTeamVector
void pastRank();


void displayAll(vector<BasketballTourney::BBallTeam> myTeamVector){
    // Modified the displayAll to be a bit more readable
    // added pages
    int pageIncrements = 15; // This can be modified to any number
    int currentPage = 1;
    int totalPages = (static_cast<int>(myTeamVector.size())/pageIncrements) + 1;
    int startDisplay;
    int endDisplay;
  
    while (currentPage != -1) {
      currentPage -= 1;
      startDisplay = currentPage * pageIncrements;
      endDisplay = startDisplay + pageIncrements;
      if (endDisplay > static_cast<int>(myTeamVector.size())) {
        endDisplay = static_cast<int>(myTeamVector.size());
      }
      cout << "Teams listing:" << endl;
      for(auto x = startDisplay; x < endDisplay; ++x) {
        cout << " Name: " << myTeamVector[x].getName() << endl;
          cout << " Games played: " << myTeamVector[x].getNumGamesPlayed() << endl;
          cout << " Games won: " << myTeamVector[x].getNumGamesWon() << endl;
          cout << " Offensive Efficiency: " << myTeamVector[x].getOffensiveEfficiency() << endl;
          cout << " Defensive Efficiency: " << myTeamVector[x].getDefensiveEfficiency() << endl;
          cout << " Power Rate: " << myTeamVector[x].getPowerRate() << endl;
          cout << " Goal Percentage Shot: " << myTeamVector[x].getGoalPercentageShot() << endl;
          cout << " Goal Percentage Allowed: " << myTeamVector[x].getGoalPercentageAllowed() << endl;
          cout << " Power: " << myTeamVector[x].getPower() << endl;
          cout << "--------------------------------------------" << endl;
      }
      
      cout << "Currently displaying Page " << currentPage + 1 << " out of " << totalPages << endl;
      cout << "What page would you like to jump to? Type -1 to cancel." << endl;
      cin >> currentPage;
      
      if (currentPage > totalPages) { // error handling if value is too high
        currentPage = totalPages;
      }
  }
}

void addTeam(vector<BasketballTourney::BBallTeam> &myTeamVector,string name){
    BasketballTourney::BBallTeam myTeam;
    bool exist=false;

    //check if team name existed 
    for(size_t i=0;i<myTeamVector.size();i++){
        if(myTeamVector[i].getName()==name){
            exist=true;
        }
    }

    //if team name existed, jump to modify function
    if(exist){
        modifyTeam(myTeamVector,name);
    }
    else{
        int numGamesPlayed;
        int numGamesWon=10000;
        double offensiveEfficiency;
        double defensiveEfficiency;
        double powerRate=10;
        double goalPercentageShot;
        double goalPercentageAllowed;
        double power;
        cout<<"Enter the number of games played: ";
        cin>>numGamesPlayed;
        while(numGamesWon>numGamesPlayed){
            cout<<"Enter a number of games won: ";
            cin>>numGamesWon;

            //error message if number of games won > number of games played.
            if(numGamesWon>numGamesPlayed){
                cout<<"Error: Number of games won > Number of games played."<<endl;
            }
        }
        cout<<"Enter a offensive efficiency: ";
        cin>>offensiveEfficiency;
        cout<<"Enter a defensive efficiency: ";
        cin>>defensiveEfficiency;
        while(powerRate>1){
            cout<<"Enter a power rate: ";
            cin>>powerRate;

            //error message if power rate > 1.
            if(powerRate>1){
                cout<<"Error: power rate > 1."<<endl;
            }
        }
        cout<<"Enter a goal percentage shot: ";
        cin>>goalPercentageShot;
        cout<<"Enter a goal percentage allowed: ";
        cin>>goalPercentageAllowed;
        myTeam.setName(name);
        myTeam.setNumGamesPlayed(numGamesPlayed);
        myTeam.setNumGamesWon(numGamesWon);
        myTeam.setOffensiveEfficiency(offensiveEfficiency);
        myTeam.setDefensiveEfficiency(defensiveEfficiency);
        myTeam.setPowerRate(powerRate);
        myTeam.setGoalPercentageShot(goalPercentageShot);
        myTeam.setGoalPercentageAllowed(goalPercentageAllowed);
        myTeam.setPower();

        //push back into myTeamVector
        myTeamVector.push_back(myTeam);

        //completed message
        cout << "----------------------------------" << endl;
        cout<<" Team added successfully! "<<endl;
        cout<<" Name: "<<myTeam.getName()<<endl;
        cout<<" Games played: "<<myTeam.getNumGamesPlayed()<<endl;
        cout<<" Games won: "<<myTeam.getNumGamesWon()<<endl;
        cout<<" Offensive Efficiency: "<<myTeam.getOffensiveEfficiency()<<endl;
        cout<<" Defensive Efficiency: "<<myTeam.getDefensiveEfficiency()<<endl;
        cout<<" Power Rate: "<<myTeam.getPowerRate()<<endl;
        cout<<" Goal Percentage Shot: "<<myTeam.getGoalPercentageShot()<<endl;
        cout<<" Goal Percentage Allowed: "<<myTeam.getGoalPercentageAllowed()<<endl;
        cout<<" Power: "<<myTeam.getPower()<<endl;
        cout << "----------------------------------" << endl;
    }
}

void modifyTeam(vector<BasketballTourney::BBallTeam> &myTeamVector, string name){
    bool exist=false;
    int loc = -1;
    //find if team name exist in myTeamVector
    for(size_t i=0;i<myTeamVector.size();i++){
        if(myTeamVector[i].getName()==name){

            //if team exist, exist = true, and make the location, to make changes to the data later
            exist=true;
            loc = i;
        }
    }
    if(exist){
        int pick=0;
        cout<<"Team existed, You can modify the values of the team."<<endl;
        while(pick!=-1){

            //modify menu
            cout<<"1. Name"<<endl<<"2. Games played"<<endl<<"3. Games won"<<endl<<"4. Offensive Efficiency"<<endl<<"5. Defensive Efficiency"
                <<endl<<"6. Power Rate"<<endl<<"7. Goal Percentage Shot"<<endl<<"8. Goal Percentage Allowed"<<endl<<"-1. exit"<<endl;
            cout<<"Pick one to modify(-1 to exit): ";
            cin>>pick;
            switch(pick){
                case 1:{
                    string teamName;
                    cout<<"enter a new team name: ";
                    cin>>teamName;
                    myTeamVector[loc].setName(teamName);
                    break;
                }
                case 2:{
                    int numGamesPlayed;
                    bool pass=false;
                    while(!pass){
                        cout<<"enter a new number of games played: ";
                        cin>>numGamesPlayed;

                        //error message if number of games played < number of games won
                        if(numGamesPlayed<myTeamVector[loc].getNumGamesWon())
                            cout<<"error: number of games played < number of games won."<<endl;
                        else
                            pass=true;
                    }
                    myTeamVector[loc].setNumGamesPlayed(numGamesPlayed);
                    break;
                }
                case 3:{
                    int numGamesWon;
                    bool pass=false;
                    while(!pass){
                        cout<<"enter a new number of games won: ";
                        cin>>numGamesWon;

                        //error message number of games won > number of games played
                        if(numGamesWon>myTeamVector[loc].getNumGamesPlayed())
                            cout<<"error: number of games won > number of games played."<<endl;
                        else
                            pass=true;
                    }
                    myTeamVector[loc].setNumGamesWon(numGamesWon);
                    break;
                }
                case 4:{
                    double offensiveEfficiency;
                    cout<<"enter a new offensive efficiency: ";
                    cin>>offensiveEfficiency;
                    myTeamVector[loc].setOffensiveEfficiency(offensiveEfficiency);
                    break;
                }
                case 5:{
                    double defensiveEfficiency;
                    cout<<"enter a new defensive efficiency: ";
                    cin>>defensiveEfficiency;
                    myTeamVector[loc].setDefensiveEfficiency(defensiveEfficiency);
                    break;
                }
                case 6:{
                    double powerRate;
                    bool pass=false;
                    while(!pass){
                        cout<<"enter a new power rate: ";
                        cin>>powerRate;

                        //error message if power rate > 1
                        if(powerRate>1)
                            cout<<"error: power rate > 1."<<endl;
                        else
                            pass=true;
                    }
                    myTeamVector[loc].setPowerRate(powerRate);
                    break;
                }
                case 7:{
                    double goalPercentageShot;
                    cout<<"enter a new goal Percentage Shot: ";
                    cin>>goalPercentageShot;
                    myTeamVector[loc].setGoalPercentageShot(goalPercentageShot);
                    break;
                }
                case 8:{
                    double goalPercentageAllowed;
                    cout<<"enter a new goal Percentage Allowed: ";
                    cin>>goalPercentageAllowed;
                    myTeamVector[loc].setGoalPercentageAllowed(goalPercentageAllowed);
                    break;
                }
                case -1:
                    break;
                default:
                    cout<<"invaild command."<<endl;
            }
        }
        myTeamVector[loc].setPower(); // update power value to match 
        //completed message
        cout<<"Team modification completed"<<endl;
        cout<<"Name: "<<myTeamVector[loc].getName()<<" Games played: "<<myTeamVector[loc].getNumGamesPlayed()<<" Games won: "<<myTeamVector[loc].getNumGamesWon()<<" \nOffensive Efficiency: "
            <<myTeamVector[loc].getOffensiveEfficiency()<<" Defensive Efficiency: "<<myTeamVector[loc].getDefensiveEfficiency()<<" Power Rate: "<<myTeamVector[loc].getPowerRate()
            <<" \nGoal Percentage Shot: "<<myTeamVector[loc].getGoalPercentageShot()<<" Goal Percentage Allowed: "<<myTeamVector[loc].getGoalPercentageAllowed()<<" Power: "<<myTeamVector[loc].getPower()<<endl<<endl;
    }

        //if team does not exist, ask user if he wants to add this new team
    else{
        char yn;
        cout<<"team does not exist, do you want to add it to the list?(Y/N)"<<endl;
        cin>>yn;
        if(yn=='Y'||yn=='y'){
            addTeam(myTeamVector,name);
        }
    }
}

void removeTeam(vector<BasketballTourney::BBallTeam> &myTeamVector, string name) {
    bool exist = false;
    int location;

    //checks if the team exists in the vector
    for (size_t i = 0; i < myTeamVector.size(); i++) {
        if(myTeamVector[i].getName() == name) {
            exist = true;
            location = i;
        }
    }

    //checks if the user input team is in the vector
    if (exist == false) { //if not in the vector
        cout << "Team does not exist. Enter a different team to remove: " <<endl;
        cin >> name; //prompt the user to input another team that exists
        removeTeam(myTeamVector, name); 
    }
    else {
        myTeamVector.erase(myTeamVector.begin()+location); //removes the team at location
        cout << name << " team was successfully removed." << endl;
    }
}

int main(){
    string temp;
    string name;
    int numGamesPlayed;
    int numGamesWon;
    double offensiveEfficiency;
    double defensiveEfficiency;
    double powerRate;
    double goalPercentageShot;
    double goalPercentageAllowed;
    double power;


    ifstream myfile;
    myfile.open("cbb20.csv");

    //check if file opened
    if (!myfile.is_open()) {
        cout<<"File opening unsuccessful."<<endl;
    }
    else{
        cout<<"File opened successfully!"<<endl;

        //a vector to store all existing teams
        vector<BasketballTourney::BBallTeam> myTeamVector;
        vector<BasketballTourney::BBallTournament> tournamentVector;
        //read the file and store all teams to myTeamVector
        getline(myfile, temp);
        for(size_t i=0;i<353;i++){ // 353 total, 32 lesser
            BasketballTourney::BBallTeam myTeam;
            getline (myfile,temp,',');
            getline (myfile,name,',');
            getline (myfile,temp,',');
            myfile>>numGamesPlayed;
            getline (myfile,temp,',');
            myfile>>numGamesWon;
            getline (myfile,temp,',');
            myfile>>offensiveEfficiency;
            getline (myfile,temp,',');
            myfile>>defensiveEfficiency;
            getline (myfile,temp,',');
            myfile>>powerRate;
            getline (myfile,temp,',');
            myfile>>goalPercentageShot;
            getline (myfile,temp,',');
            myfile>>goalPercentageAllowed;
            getline(myfile, temp);
            myTeam.setName(name);
            myTeam.setNumGamesPlayed(numGamesPlayed);
            myTeam.setNumGamesWon(numGamesWon);
            myTeam.setOffensiveEfficiency(offensiveEfficiency);
            myTeam.setDefensiveEfficiency(defensiveEfficiency);
            myTeam.setPowerRate(powerRate);
            myTeam.setGoalPercentageShot(goalPercentageShot);
            myTeam.setGoalPercentageAllowed(goalPercentageAllowed);
            myTeam.setPower();
            myTeamVector.push_back(myTeam);
        }
        myfile.close();
        ifstream fileTwo;
        fileTwo.open("cbb19.csv");
        

        if (!fileTwo.is_open()) {
        cout<<"File opening unsuccessful."<<endl;
        }
        else{
            cout<<"File opened successfully!"<<endl;
            getline(fileTwo, temp); // skip
            for(size_t i=0;i<353;i++){ // 353 total
                BasketballTourney::BBallTeam myTeam;
                getline (fileTwo,name,',');
                getline (fileTwo,temp,',');
                fileTwo>>numGamesPlayed;
                getline (fileTwo,temp,',');
                fileTwo>>numGamesWon;
                getline (fileTwo,temp,',');
                fileTwo>>offensiveEfficiency;
                getline (fileTwo,temp,',');
                fileTwo>>defensiveEfficiency;
                getline (fileTwo,temp,',');
                fileTwo>>powerRate;
                getline (fileTwo,temp,',');
                fileTwo>>goalPercentageShot;
                getline (fileTwo,temp,',');
                fileTwo>>goalPercentageAllowed;
                getline(fileTwo, temp);
                myTeam.setName(name);
                myTeam.setNumGamesPlayed(numGamesPlayed);
                myTeam.setNumGamesWon(numGamesWon);
                myTeam.setOffensiveEfficiency(offensiveEfficiency);
                myTeam.setDefensiveEfficiency(defensiveEfficiency);
                myTeam.setPowerRate(powerRate);
                myTeam.setGoalPercentageShot(goalPercentageShot);
                myTeam.setGoalPercentageAllowed(goalPercentageAllowed);
                myTeam.setPower();
                myTeamVector.push_back(myTeam);
            }
            fileTwo.close();
        }
      
        //user menu
        int pick;
        while(pick!=-1){

            //pls give a nice introduce title
            cout<<"Basketball Program!"<<endl;
            cout<<"1. Display all teams."<<endl;
            cout<<"2. Add a new team."<<endl;
            cout<<"3. Modify a existing team."<<endl;
            cout<<"4. Remove a team."<<endl;
            cout<<"5. Start the tournament."<<endl;
            cout<<"6. List all the winning teams in previous tournaments."<<endl;
            cout<<"-1. Exit."<<endl;
            cout << "Input an option: ";
            cin>>pick;
            cout << endl;
            switch(pick){
                case 1:{//Display all teams
                    displayAll(myTeamVector);
                    break;
                }
                case 2:{//add a new team
                    string teamName;
                    cout<<"Enter a team name."<<endl;
                    cin>>teamName;
                    addTeam(myTeamVector,teamName);
                    break;
                }
                case 3:{//modify an existing team
                    string teamName;
                    cout<<"Enter the team name."<<endl;
                    cin>>teamName;
                    modifyTeam(myTeamVector,teamName);
                    break;
                }
                case 4:{//remove a team
                    string teamName;
                    cout << "Enter a team to remove." << endl;
                    cin >> teamName;
                    removeTeam(myTeamVector, teamName);
                    break;
                }
                case 5:{//start the tournament.
                    BasketballTourney::BBallTournament newTournament;
                    newTournament.addParticipatingTeams(myTeamVector); // no more error check, guaranteed to be even team count
                    newTournament.startTournament();
                    /* This is screwing up and idk why, it's giving me an std out of range error
                    If anyone wants to try and fix this please do so, this is brainrot inducing
                    NOTE: Thank you to Shengwei Jian for the fix
                    */
                    // Pushes tournament into tournament vector
                    tournamentVector.push_back(newTournament);
                    break;
                }
                case 6:{//List all the winning teams in the history
                    int tournamentNumber;
                    cout << "Which tournament results do you want to view?" << endl;
                    for (auto x = 0; x < tournamentVector.size(); x++) {
                      int y = x + 1;
                      cout << "Tournament " << y << endl;
                    }
                    cout << "Number: ";
                    cin >> tournamentNumber;
                    cout << "Tournament " << tournamentNumber << " results: " << endl;
                    tournamentVector[tournamentNumber - 1].printResults();
                    break;
                }
                case -1:
                    cout<<"Exiting program..."<<endl;
                    break;
                default:
                    cout<<"Invalid command."<<endl;
            }
        }
    }
    
    return 0;
}