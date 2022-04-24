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
    void BBallTeam::setPower(double myPower){
        power = myPower;
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

    BBallTeam BBallTournament::fight() {
        // Declares the fight loser
        BBallTeam fightLoser;

        // If team 0 is greater than team 1, winning team is pushed back into participating teams
        // else, team 1 is pushed back into participating teams
        if (matchup.at(0).getPower() > matchup.at(1).getPower()) {
            participatingTeams.push_back(matchup.at(0));
            matchup.at(1) = fightLoser;
        }  else {
            participatingTeams.push_back(matchup.at(1));
            matchup.at(0) = fightLoser;
        }
        clearMatchup();

        return fightLoser;
    }// WIP algorithm, how do we decide who wins?  Compare the double power

    void BBallTournament::addParticipatingTeams(vector<BBallTeam> teams) {
        for (int i = 0; i < (int) teams.size() - 1; i++) {
            participatingTeams.push_back(teams.at(i));
        }
    } // for every team inside the vector, push onto the participatingTeams queue

    void BBallTournament::clearMatchup() {
        // Clears the matchup vector
        for (int i = 0; i < (int) matchup.size() - 1; i++) {
            matchup.pop_back();
        }
    }

    void BBallTournament::startTournament(){
        // Declares a temporary value to
        int tempVal = participatingTeams.size();

        // While tempVal is != 1, the participating teams at the front are pushed back to matchup
        // the front is swapped out to the back and popped
        // fight algorithm is called and the return value of that is pushed to= results
        // tempval is decreased
        // final value in participatingTeams is pushed as final result
        // results are printed
        //
        //
        while (tempVal != 1) {
            matchup.push_back(participatingTeams.front());
            swap(participatingTeams.front(), participatingTeams.at(participatingTeams.size()-1));
            participatingTeams.pop_back();
            matchup.push_back(participatingTeams.at(1));
            swap(participatingTeams.front(), participatingTeams.at(participatingTeams.size()-1));
            participatingTeams.pop_back();
            results.push_back(fight());

            tempVal--;
        }
        results.push_back(participatingTeams.at(0));
        printResults();
    }
    void BBallTournament::swap(BBallTeam team1, BBallTeam team2){
        // Stores team1 in tempteam, makes team1 into team2 and team2 into tempteam
        BBallTeam tempTeam;
        tempTeam = team1;
        team1 = team2;
        team2 = tempTeam;
        // Swaps out the team value at 0 and the team
        participatingTeams.at(0) = team1;
        participatingTeams.at(participatingTeams.size()-1) = team2;
    }// swap the position of 2 teams.
}