class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(3, INT_MIN);  //this vector holds our triplet
        cache[0] = nums[0]; //there is atleast one element which is the current mininum so we set it equal to that(it might even be int_min)

        for(int num : nums) {
            if((num == cache[0]) || (num == cache[1]) || (num == cache[2]))
                continue;   //since we are wroking with stricly increasing i don't wanna create false triplets

            if(num < cache[0])
                cache[0] = num; //we have a new min element

            else {  //the element is larger than our current_min
                if(cache[1] == INT_MIN) //it means that an increasing second number hasn't been found yet, so we simply assign
                    cache[1] = num;

                else if(num < cache[1]) //it means the number has been assigned but we have found a number lesser than the second number but greater than first
                    cache[1] = num;

                else {
                    if(cache[2] == INT_MIN) {   //i don't think an if block is really required here, but i just kind of went with the visualization, so our third element 
                                                //is int_min which means it hasnt' been assigned yet, so since we are here we have found our triplet and we return true
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
//HOLY SHIT MAN I COOKED, AND I COOKED HARD ASF. I told ya I would be back to my prime someday, and I think even though I wasn't at my prime, but this is one of my best 
//soultions yet so yeah.... Initially had no idea, then drew a graph x and y. y = value, x = index. I just had no idea what to do when I encounter a new min value, I was like
//do I scrap my previous 2nd element due to i < j < k and then I couldn't really figure the decision. Then opened the discussion tab, skipped all the idiots who posted 
//their solutions and then saw someone's comment which said to try and ignore this decision. THen I pondered and it made sense. suppose we had only one element, then it is 
//a no brainer to update the first element with the min we just saw, But say we had two and we see a new min element, so we update cache[0] but the second eleement is 
//still in place. so if we encounter a value larger than the second value we found our answer cuz even though the first element is wrong, we know it WAS lesser than the 
//second element and had satisfied the conditions and so we return true. Quite an interesting algorithm(greedy) Also I am very happy that I just kept writing code 
//with like muscle memory without even thinking and just visualizing the algo and it had no syntax or logical and first try pass baby woohooo