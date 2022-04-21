// BBallTeam.hpp

// Declaration of the BasketballTeam Class

// Created by Joaquin Warren April 2022
#include <string>
#include <iostream>

using namespace std;
namespace BasketballTourney{

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

}

