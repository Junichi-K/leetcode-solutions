class Solution {
public:
    int trap(vector<int>& height) {
        //this solution is a little hard to grasp my head around but after writing the flow of control with a pen on a couple of cases, you can get the 
        //jist of it. So, we start with left and right at the borders and we calculate the amount of water stored above each "building" iteratively
        //So, it goes like this, first, we check if left building is smaller than the right building. If yes, then that is our "limiting factor". (Also
        //draw the buildings out as you iterate -> don't draw the entire skyline at the beginning, draw as you "see" them just like the algo does because 
        //that was the main concern I had like it doens't know the rest of the building yet still calculates the correct amt of water). When we are coming 
        //from the left and the right building is the bigger one, we simply do not care about the other one because there can be two cases -> either a 
        //building taller than left but smaller than right(say) appears in between indices right and left, then again left border will the limiting factor
        //otherwise if none all buildings from left to right are smaller then left then still the limiting factor would be the left building, as it would be 
        //stopped by the right building which is taller. Now comes the second part, if the current building we're at has a taller left building then water
        //can be stored on top if it and would be equal to the difference in their heights. (also one important point is that the pointer stays at a 
        //ttall building until a taller one appears due to the outer two loops). The same logic is applied to the right side as well(when left building 
        //is larger than the current right building, we keep handling the left building). HONESTLTY, the best way to demonstrate how this algo works is 
        //by drawing out the buildings from left and right as you "see" them and then calculating the amount of water on the basis of the logic below
        //and you'll clearly be able to see how this algo always gives the correct answer after a max of looking at 3 test cases.
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while (left < right) {
            if(height[left] < height[right]) {
                if (height[left] > left_max) 
                    left_max = height[left];
            
                else 
                    result += left_max - height[left];
        
                left++;
            } 
            
            else {
                if (height[right] > right_max) 
                    right_max = height[right];

                else 
                    result += right_max - height[right];
                
                right--;
            }
        }

        return result;
    }
};

//the problems getting harder boi. Also it doesn't help with the fact that my performance has gone down significantly. It's alright, just a matter of 
//time before I get back up