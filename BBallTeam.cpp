// BBallTeam.cpp

// Implementation of the BasketballTeam Class

// Created by Joaquin Warren April 2022
// Tournament created by Shendwei Jian and Jacob Perez April 2022

#include "BBallTeam.hpp"
#include <cstring>

using namespace std;
namespace BasketballTourney{
    // default constructor
    // Jacob comment: I changed the constructors to look a bit more like the ones from the labs so it would be a bit
    // easier to understand, if you want you can change it back
    BBallTeam::BBallTeam() {
        name = " ";
        numGamesPlayed = 0;
        numGamesWon = 0;
        offensiveEfficiency = 0.00;
        defensiveEfficiency = 0.00;
        powerRate = 0.00;
        goalPercentageShot = 0.00;
        goalPercentageAllowed = 0.00;
        power = 0.00;
    }

    // parameterized constructor
    BBallTeam::BBallTeam(string teamName, int numGames, int numWins, double teamOffensiveEfficiency,
                         double teamDefensiveEfficiency, double teamPowerRate, double percentShot,
                         double percentAllowed, double teamPower) {
        name = teamName;
        numGamesPlayed = numGames;
        numGamesWon = numWins;
        offensiveEfficiency = teamOffensiveEfficiency;
        defensiveEfficiency = teamDefensiveEfficiency;
        powerRate = teamPowerRate;
        goalPercentageShot = percentShot;
        goalPercentageAllowed = percentAllowed;
        power = teamPower;
    }

    // Accessors
    string BBallTeam::getName() const{
        return name;
    }
    int BBallTeam::getNumGamesPlayed() const{
        return numGamesPlayed;
    }
    int BBallTeam::getNumGamesWon() const{
        return numGamesWon;
    }
    double BBallTeam::getOffensiveEfficiency() const{
        return offensiveEfficiency;
    }
    double BBallTeam::getDefensiveEfficiency() const{
        return defensiveEfficiency;
    }
    double BBallTeam::getPowerRate() const{
        return powerRate;
    }
    double BBallTeam::getGoalPercentageShot() const{
        return goalPercentageShot;
    }
    double BBallTeam::getGoalPercentageAllowed() const{
        return goalPercentageAllowed;
    }
    double BBallTeam::getPower() const{
        return power;
    }


    // Mutators
    void BBallTeam::setName(string myName){
        name = myName;
    }
    void BBallTeam::setNumGamesPlayed(int games){
        numGamesPlayed = games;
    }
    void BBallTeam::setNumGamesWon(int wins){
        numGamesWon = wins;
    }
    void BBallTeam::setOffensiveEfficiency(double myOffensiveEfficiency){
        offensiveEfficiency = myOffensiveEfficiency;
    }
    void BBallTeam::setDefensiveEfficiency(double myDefensiveEfficiency){
        defensiveEfficiency = myDefensiveEfficiency;
    }
    void BBallTeam::setPowerRate(double myPowerRate){
        powerRate = myPowerRate;
    }
    void BBallTeam::setGoalPercentageShot(double percentShot){
        goalPercentageShot = percentShot;
    }
    void BBallTeam::setGoalPercentageAllowed(double percentAllowed){
        goalPercentageAllowed = percentAllowed;
    }
    void BBallTeam::setPower(){
        double winRate = (getNumGamesWon()*1.0)/(getNumGamesPlayed()*1.0);
        double totalEfficiency = getOffensiveEfficiency()+getDefensiveEfficiency();
        double myPowerRate = getPowerRate();
        power = myPowerRate*winRate*totalEfficiency*(getGoalPercentageShot()/100.0);
    }

    // Kinda confused on what to do with the Tournament constructor

    BBallTournament::BBallTournament() {

    }

    // Prints results, last in vector should be
    void BBallTournament::printResults() {
        for (int i=0; i< (int) results.size(); i++) {
            cout << i + 1 << ". " << results.at(i).getName() << endl;
        }
        cout << "------------------" << endl;
    }
    // displays currently participating teams
    void BBallTournament::printParticipatingTeams() {
        for (size_t j=0; j < participatingTeams.size(); j++) {
            cout << participatingTeams[j].getName() << endl;
        }
        cout << "------------------" << endl;
    }

    void BBallTournament::fight(BBallTeam team1, BBallTeam team2) {

        cout << team1.getName()<<" power: "<<team1.getPower()<<endl;
        cout<<"       VS                 ";
        // If team2 power > team1 power, team1 swaps position with team 2
        if (team2.getPower() > team1.getPower()) {
            swap(team1, team2);
            cout << team2.getName()<< " has won!" << endl;
        } 
         else {
            cout << team1.getName()<< " has won!" << endl;
        }
        cout<<team2.getName()<<" power: "<<team2.getPower()<<endl<<endl;
    }// WIP algorithm, how do we decide who wins?  Compare the double power

    void BBallTournament::addParticipatingTeams(vector<BBallTeam> teams) {
        string teamName;
        int currentAmount = 0;
        int totalNeeded = 32;
        int randomTeam;
        srand(rand()%1000); // set seed to random value
        while (currentAmount != totalNeeded) {
            cout << "Currently has " << currentAmount << " out of " << totalNeeded << " teams." << endl;
            cout << "Which team name would you like to add? Enter -1 if you want the rest to be randomly chosen." << endl;
            cin >> teamName;
            if(teamName == "-1") {
                cout << "Randomly adding the rest of the teams." << endl;
                for (int x = 0; x < (totalNeeded-currentAmount); ++x) {
                    bool teamFound = false;
                    while (currentAmount != totalNeeded) { //check if the team selected is in the participatingTeams vector, if it is then reroll, else push
                        randomTeam = (rand() % 700) - 1;
                        teamFound = false;
                        if (randomTeam < 0) {
                          randomTeam = 0;
                        }
                        for(size_t i=0;i<participatingTeams.size();i++){ 
                            if(participatingTeams[i].getName() == teams[randomTeam].getName()){ // IF ALREADY INSIDE VECTOR
                                teamFound = true;
                            }
                        }
                        if (!teamFound) {
                            currentAmount++;
                            cout << teams.at(randomTeam).getName() << " added!" << endl;
                            participatingTeams.push_back(teams.at(randomTeam));
                        }
                    }
                }
                cout << endl;
            }
            else {
                bool exist=false;
                //find if team name exist in myTeamVector
                for(size_t i=0;i<teams.size();i++){
                    if(teams[i].getName()==teamName){
                        exist=true;
                        cout << "Team found and added!" << endl;
                        currentAmount++;
                        participatingTeams.push_back(teams.at(i));
                    }
                }
                if(!exist){
                  cout << "Team does not exist!" << endl;
                }
            }
        }
    } // for every team inside the vector, push onto the participatingTeams queue

    void BBallTournament::startTournament(){
        BBallTeam winner;
        string teamName;
        bool exist=false;
        // Display every participating team
        printParticipatingTeams();
        while(!exist){
            cout << "Guess which team is going to win: ";
            cin >> teamName;
            for(size_t i= 0;i<participatingTeams.size();i++){
                if(strcasecmp(teamName.c_str(), participatingTeams[i].getName().c_str()) == 0){
                    exist= true;
                }
            }
            if(!exist){
                cout<<"Please enter an existing team name."<<endl;
            }
        }
        // Shuffles the teams around every match
        random_shuffle(participatingTeams.begin(), participatingTeams.end());
        matchup(participatingTeams.size());
        // Once matchup is over, full tournament results are displayed
        cout << "Tournament Results: " << endl;
        for(size_t i=0;i<participatingTeams.size();i++){
            cout << i + 1 << ". " << participatingTeams[i].getName() << endl;
            results.push_back(participatingTeams[i]);
        }
        // Congratulations if you won btw
        if(strcasecmp(teamName.c_str(), participatingTeams[0].getName().c_str()) == 0){
            cout << "Congratulations! You are the champion!" << endl;
        }
        cout << "------------------------------" << endl;
    }

    void BBallTournament::matchup(size_t size){
        size_t newSize=size/2;
        if(size>1){
            for(size_t i=0;i<newSize;i++){\
                cout << "Game " << i+1 << ":" << endl;
                fight(participatingTeams[i],participatingTeams[size-i-1]);
            }
            if(newSize==16){
                cout<<"16 teams have advanced, and the 1/8 final will be played next."<<endl;
            }
            else if(newSize==8){
                cout<<"8 teams have advanced, and the 1/4 final will be played next."<<endl;
            }
            else if(newSize==4){
                cout<<"4 teams have advanced, and the semifinal will be played next."<<endl;
            }
            else if(newSize==2){
                cout<<"the top 2 teams have advanced, and the final will be played next."<<endl;
            }
            /* Commented out for cleaning
            for(size_t i=0;i<participatingTeams.size();i++){
                cout<<i+1<<". "<<participatingTeams[i].getName()<<endl;
            }
             */
            cout<<"------------------"<<endl;
            matchup(newSize);
        }
    }

    void BBallTournament::swap(BBallTeam team1, BBallTeam team2){
        size_t team1Loc;
        size_t team2Loc;
        BBallTeam tempTeam;
        for(size_t i=0;i<participatingTeams.size();i++){
            //mark the location of team1
            if(participatingTeams[i].getName()==team1.getName()){
                team1Loc= i;
            }
            //mark the location of team2
            if(participatingTeams[i].getName()==team2.getName()){
                team2Loc= i;
            }
        }
        //set temp = team1
        tempTeam= team1;
        //set new team1 = team2
        participatingTeams[team1Loc]=team2;
        //set new team2 = tempTeam
        participatingTeams[team2Loc]=tempTeam;
    }
}