using namespace std;

class Farm{
    string player_name, farm_name;
    double coins;
public:
    Farm(string name, string _name):player_name(name), farm_name(_name), coins(0){}
    Farm(string name, string _name, double _coins):player_name(name), farm_name(_name), coins(_coins){}
    string FarmName();
};

string Farm::FarmName(){
    return farm_name;
}