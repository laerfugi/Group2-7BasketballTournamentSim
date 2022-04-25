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
void addTeam(vector<BasketballTourney::BBallTeam> myTeamVector,string name);//add a new team to myTeamVector
void modifyTeam(vector<BasketballTourney::BBallTeam> myTeamVector,string name);//modify a team from myTeamVector
void pastRank();


void displayAll(vector<BasketballTourney::BBallTeam> myTeamVector){
    // Modified the displayAll to be a bit more readable
    cout << "Teams listing:" << endl;
    for(size_t i=0;i<myTeamVector.size();i++){
        cout << " Name: " << myTeamVector[i].getName() << endl;
        cout << " Games played: " << myTeamVector[i].getNumGamesPlayed() << endl;
        cout << " Games won: " << myTeamVector[i].getNumGamesWon() << endl;
        cout << " Offensive Efficiency: " << myTeamVector[i].getOffensiveEfficiency() << endl;
        cout << " Defensive Efficiency: " << myTeamVector[i].getDefensiveEfficiency() << endl;
        cout << " Power Rate: " << myTeamVector[i].getPowerRate() << endl;
        cout << " Goal Percentage Shot: " << myTeamVector[i].getGoalPercentageShot() << endl;
        cout << " Goal Percentage Allowed: " << myTeamVector[i].getGoalPercentageAllowed() << endl;
        cout << " Power: " << myTeamVector[i].getPower() << endl;
        cout << "--------------------------------------------" << endl;
    }
}

void addTeam(vector<BasketballTourney::BBallTeam> myTeamVector,string name){
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
        myTeam.setPower(numGamesPlayed);

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

void modifyTeam(vector<BasketballTourney::BBallTeam> myTeamVector, string name){
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
        //read the file and store the first 32 teams to myTeamVector
        getline(myfile, temp);
        for(size_t i=0;i<32;i++){
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
            myTeam.setPower(powerRate);
            myTeamVector.push_back(myTeam);
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
            cout<<"6. List all the winning teams in the history."<<endl;
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
                    break;
                }
                case 5:{//start the tournament.
                    BasketballTourney::BBallTournament newTournament;
                    if ((myTeamVector.size() % 2) != 0) {
                        cout << "Error: Uneven team count" << endl;
                        break;
                    } else
                        newTournament.addParticipatingTeams(myTeamVector);
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
                    cout << "Input: ";
                    cin >> tournamentNumber;
                    cout << "Tournament " << tournamentNumber << " results: " << endl;
                    tournamentVector[tournamentNumber].printResults();
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
    myfile.close();
    return 0;
}