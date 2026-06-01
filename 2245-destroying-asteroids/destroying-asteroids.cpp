class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        unsigned long long totalMass = mass;

        for(auto& ast : asteroids){
            if(totalMass >= ast){
                totalMass += ast;
            }
            else{
                return false;
            }
        }

        return true;
    }
};