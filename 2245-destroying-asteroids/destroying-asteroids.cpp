class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        unsigned long long totalMass = mass;

        for(int i = 0; i < asteroids.size(); i++){
            if(totalMass >= asteroids[i]){
                totalMass += asteroids[i];
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};