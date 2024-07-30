/*class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();


        int number = helper_function(preorder, n, 0);

        return n + 1 == number;
    }

    int helper_function(string &s, int &n, int index) {
        if(index >= n)
            return index;

        if(s[index] == '#')
            return index + 2;

        for(int i = index, s[])

        int left_tree_end = helper_function(s, n, index + 2);
        if(left_tree_end >= n)
            return n;
        int right_tree_end = helper_function(s, n, left_tree_end);

        return right_tree_end;
    }
};*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;  //we make use of the slot system, where slots refers to the amount of nodes we can have in our tree at any given time. So we set it to 1 to accomate
                        //the root
        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',') //we simply skip this separation character
                continue; 

            if (--slots < 0)    //if the places to accomodate ever becomes less than zero, it means that the tree can't be constructed, and we return false 
                return false; 

            if (preorder[i] != '#') {   //we see a node, which can accomodate two childs, so we increment slots by 2
                while (i < preorder.length() && preorder[i] != ',') //the part I messed up in my code
                    i++;  
                slots += 2;
            }
        }
        return slots == 0;  //it means that all the slots are either taken up by a # or a number in the tree 
    }
};

//left my solution above top which passed almost all the cases, just that I coulnd't really figure out how to handle 2 or more digit numbers