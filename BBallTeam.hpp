// BBallTeam.hpp

// Declaration of the BasketballTeam Class

// Created by Joaquin Warren April 2022
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


namespace BasketballTourney{
    using namespace std;
    class BBallTeam{
        public:
        // default constructor
        BBallTeam(); 
        // parameterized constructor
        BBallTeam(string teamName,int teamGamesPlayed,int teamGamesWon,double teamOffensiveEfficiency,
        double teamDefensiveEfficiency,double teamPowerRate,double teamPercentShot,double teamPercentAllowed,
        double teamPower);

        // Accessors
        string getName() const;
        int getNumGamesPlayed() const;
        int getNumGamesWon() const;
        double getOffensiveEfficiency() const;
        double getDefensiveEfficiency() const;
        double getPowerRate() const;
        double getGoalPercentageShot() const;
        double getGoalPercentageAllowed() const;
        double getPower() const;

        // Mutators    
        void setName(string myName);
        void setNumGamesPlayed(int games);
        void setNumGamesWon(int wins);
        void setOffensiveEfficiency(double myOffensiveEffiency);
        void setDefensiveEfficiency(double myDefensiveEffiency);
        void setPowerRate(double myPowerRate);
        void setGoalPercentageShot(double percentShot);
        void setGoalPercentageAllowed(double percentAllowed);
        void setPower(double myPower);

        private:
        string name;
        int numGamesPlayed;
        int numGamesWon;
        double offensiveEfficiency;
        double defensiveEfficiency;
        double powerRate;
        double goalPercentageShot;
        double goalPercentageAllowed;
        double power;
    };

    class BBallTournament {
    public:
        // Default Constructor
        BBallTournament(); // IDk what to do with the constructor but it's here
        void printResults();// Prints results
        BBallTeam fight(); // WIP algorithm, how do we decide who wins?  Compare the double power
        void addParticipatingTeams(vector<BBallTeam> teams); // for every team inside the vector, push onto the participatingTeams queue
        void clearMatchup(); //Clears matchup vector
        void startTournament();//Clears tournament vector
        void swap(BBallTeam team1, BBallTeam team2); // swaps the position of 2 teams in the vector.
    private:
        //Declares the private team vectors
        vector<BBallTeam> participatingTeams;
        vector<BBallTeam> results;
        vector<BBallTeam> matchup;
    };
}

