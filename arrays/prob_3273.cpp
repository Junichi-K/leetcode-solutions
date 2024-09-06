class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        for(int &h : health) 
            h = (h + power - 1)/power;
        
        vector<int> order;
        for(int i = 0; i < damage.size(); i++) 
            order.push_back(i);

        sort(order.begin(), order.end(), [&](int i, int j) {
            return health[i] * damage[j] < health[j] * damage[i];
        });

        long long result = 0;
        long long current_time = 0;

        for(int idx : order) {
            current_time += health[idx];

            result += damage[idx] * current_time;
        }

        return result;
    }
};