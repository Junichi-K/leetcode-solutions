//this class implements a fenwick tree, more commonly known as a binary indexed tree(bit tree) and yeah it works by manipulaing the bit if that wasn't
//hard go guess
class BIT {
private:
    vector<int> bit_array;  
    int n;  //i just kept track of the size of the bit array as that would help us in updating values and not use bit_val.size() everytime. 

public: 
    BIT(int size) { //size is the size of the array we'll perform range sum on
        bit_array = vector<int>(size + 1, 0);   //bit array HAS to be assigned equal to given arraysize + 1 ALWAYS. That's how they work. Main reason 
                                                //being that 2^0 = 1. If you are ok with math you'll understand why this causes that.
        n = size;
    }

    void update(int id, int val) {  //id is the bit index(1 index)
        //so we want to update the fenwick tree by 'adding' val to id'th position. So how this works is we find the difference(like what was the value 
        //before and what it is now and then simply add the result to our tree. This is the same thing as first eliminating the effect of the value that was 
        //initially stored and then passing the new value to be stored again thereby calling the update function twice)
        while(id <= n) {
            bit_array[id] += val;
            //This expression is of course very very complicated. So, one of the most important things to note is that every bit index that is some power of
            //2(1, 2, 4, 8...) contains the sum of all the elements upto that index in the bit array and this is a very important property about this 
            //structure. Now, the way this loop works, is by "adding" the effect of val to all the indices where it needs to be "added" in the structure. For 
            //example, say index is 1, remember i said all powers of 2, so performing the below expression in loop gives the values 1 -> 2 -> 4 -> 8 ... and that
            //is exactly where the value needs to be added. Now for when our index is not a power of 2, this expression will "take us" to the next power of 2 
            //somehow. Obviously it is very difficult to write this process down, but if you graphically try and see it, you will find out how this will workp[]
            id += (id & -id);
        }
    }

    int query(int id) { //the above process in reverse
        int result = 0;

        while(id > 0) {
            result += bit_array[id];
            id -= (id & -id);
        }

        return result;
    }
};
//honestly I did the best that I could do to explain this process. But still there are so many cases and possibilities left to be explained further, one 
//NEEDS to draw out an array and see how the bit array gets populated step by step. 

class NumArray {
private:
    vector<int> &nums;
    BIT object;

public:
    NumArray(vector<int>& nums) : object(nums.size()), nums(nums) { //populates the bit array
        for(int i = 0; i < nums.size(); i++) 
            object.update(i + 1, nums[i]);
    }
    
    void update(int index, int val) {   //updates the value by finding the difference between the two values since we are keeping a copy of the bit array
                                        //after every update
        object.update(index + 1, val - nums[index]);
        nums[index] = val;  //updating the "current" array
    }
    
    int sumRange(int left, int right) { //since query returns sum from 1 -> id and we use appropriate indexing here. 
        return (object.query(right + 1) - object.query(left));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


//welp I think I was at my lowest since I have started doing this LC thingy. I wans't even able to think easier mediums before this problem and this was just 
//the nail in the coffin. So as expected, I took a light hearted break of roughly a week not just from this one, but from a lot of my other hobbies as 
//well; didn't go full out in my exericises as I usually do, didn't aim trian, and like nothing whole day basically. I just restarted today and I must 
//it was a bang with aiming(broke two old high scores today after not playing for a week)! So I have similar hopes from LC now as well. Hopefully my 
//solving skills are back to normal level(I was just constantly tanking my 
//contest ratings from 1571 to 1511 with just two contests and yeah that is very bad). I am feeling fresh once again and I am quite sure I'll only go up
//from here. Not gonna attend this weeks 2 contests cuz I don't wanna ruin this feeling. But fosho next week we slayin'. and yeah regarding this problem
//maybe if I was thinking abou it 24*7 this solution of a fenwick tree might have crossed my mind in a wild dream. 