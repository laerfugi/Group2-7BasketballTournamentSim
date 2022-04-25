// BBallTeam.cpp

// Implementation of the BasketballTeam Class

// Created by Joaquin Warren April 2022

#include "BBallTeam.hpp"

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
    void BBallTeam::setPower(double myPowerRate){
        power = myPowerRate;
    }

    // Kinda confused on what to do with the Tournament constructor

    BBallTournament::BBallTournament() {

    }

    // Prints results, last in vector should be
    void BBallTournament::printResults() {
        for (int i=0; i< (int) results.size(); i++) {
            cout << results.size() << results.at(i).getName() << endl;
        }
    }

    void BBallTournament::fight(BBallTeam team1, BBallTeam team2) {

        if (team2.getPower() > team1.getPower()) {
            swap(team1, team2);
            cout << team2.getName() <<" power: "<<team2.getPower()<< " has won!" << endl;
            cout << team1.getName() <<" power: "<<team1.getPower()<< " has lose!" << endl;
        } 
         else {
            cout << team1.getName() <<" power: "<<team1.getPower()<< " has won!" << endl;
            cout << team2.getName() <<" power: "<<team2.getPower()<< " has lose!" << endl;
        }
    }// WIP algorithm, how do we decide who wins?  Compare the double power

    void BBallTournament::addParticipatingTeams(vector<BBallTeam> teams) {
        for (size_t i = 0; i <teams.size(); i++) {
            participatingTeams.push_back(teams.at(i));
        }
    } // for every team inside the vector, push onto the participatingTeams queue

    void BBallTournament::startTournament(){
        BBallTeam winner;
        string teamName;
        cout << "Input your team name: ";
        cin>>teamName;


        matchup(participatingTeams.size());
        for(size_t i=0;i<participatingTeams.size();i++){
            cout<<i<<". "<<participatingTeams[i].getName()<<endl;
        }
    }

    void BBallTournament::matchup(size_t size){
        size_t newSize=size/2;
        if(size>1){
            for(size_t i=0;i<newSize;i++){
                fight(participatingTeams[i],participatingTeams[size-i-1]);
            }
            for(size_t i=0;i<participatingTeams.size();i++){
                cout<<i<<". "<<participatingTeams[i].getName()<<endl;
            }
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