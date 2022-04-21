// BBallTeam.cpp

// Implementation of the BasketballTeam Class

// Created by Joaquin Warren April 2022

#include "BBallTeam.hpp"

using namespace std;
namespace BasketballTourney{
    // default constructor
    BBallTeam::BBallTeam():name(" "),numGamesPlayed(0),numGamesWon(0),
    offensiveEfficiency(0.00),defensiveEfficiency(0.00),powerRate(0.00),
    goalPercentageShot(0.00),goalPercentageAllowed(0.00),power(0.00){}

    // parameterized constructor
    BBallTeam::BBallTeam(string teamName,int numGames,int numWins,
    double teamOffensiveEfficiency,double teamDefensiveEfficiency,
    double teamPowerRate,double percentShot, double percentAllowed,double teamPower)
    :name(teamName),numGamesPlayed(numGames),numGamesWon(numWins),offensiveEfficiency(teamOffensiveEfficiency),
    defensiveEfficiency(teamDefensiveEfficiency),powerRate(teamPowerRate),goalPercentageShot(percentShot),
    goalPercentageAllowed(percentAllowed),power(teamPower){}

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
}