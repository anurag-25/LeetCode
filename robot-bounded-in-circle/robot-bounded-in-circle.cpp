class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector <vector <int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector <int> pos = {0, 0};
        int direction = 0;
        for (int i=0; i<instructions.length(); i++) {
            if (instructions[i] == 'L') direction = (direction+3)%4;
            else if (instructions[i] == 'R') direction = (direction+1) %4;
            else {
                pos[0] += directions[direction][0];
                pos[1] += directions[direction][1];
            }
        }
        return ( (pos[0]==0 && pos[1]==0) || direction!=0);
    }
};