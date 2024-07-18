class Solution {
private:
    int time_number;//we represent the bits of the watch(the 10 bits using this member varialbe)
    vector<string> result;

public:
    vector<string> readBinaryWatch(int turnedOn) {
        helper_function(9, 0, turnedOn);

        return result;
    }

    void helper_function(int index, int bits, int &turned_on) {
        if(bits == turned_on) { //bits is equal to the number of bits in time number that are equal to 1, so when this condition is true, our time
                                //"time" is created and we perform just a little more checks before pushing things into result
            int minutes = 0b111111 & time_number;   //the way I am storing the time in time_number is that I am using the first 6 bits to store the
                                                    //minutes and the next 4 bits to store the hours(one can also use two variables, but this was just
                                                    //personal preference). So to simply obtain the number of minutes in time_number we and with the 
                                                    //shown binary
            int hours = 0b11111000000 & time_number;//obtaining the hours. and then shifting it by 6 places to the right(else it becomes too large that is
                                                    //we have to take care of the offset as well)
            hours >>= 6;

            if(hours >= 12 || minutes >= 60)    //if any of this condition is true, it means our time is invalid and we simply return
                return;

            result.push_back(to_string(hours) + ':' + (minutes < 10 ? ('0' + to_string(minutes)) : (to_string(minutes))));  //if minutes is lesser than 10
                                                                                                                            //add a leading zero(need not be
                                                                                                                            //done in case of hours)

            return;
        }

        for(int i = index; i >= 0; i--) {
            time_number |= 1 << i;//simple backtracking wherein we set bits equal to 1 then then reset the bit
            
            helper_function(i - 1, bits + 1, turned_on);

            time_number &= ~(1 << i);   //this was something new. My trash brain simply wrote time_number |= 0 << i, then found out how incredibly dumb 
                                        //this statement was and then tried to figure out by myself, couldn't then saw a way, and yeah I am a fucking noob
                                        //and just thought inside the OR and AND bubble, and couldn't even think of the not operator. (bits are hard)
        }
    }
};

//this was a good question. It was simple backtracking, but since it involved working with bits, that made it a little bit more challenging. Also learned
//a couple of new things
