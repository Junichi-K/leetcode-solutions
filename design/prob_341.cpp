/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:   
    vector<int> list;
    int pointer = 0;    //used for hasNext operations and returning the current number
    int no_of_elements;
    vector<int> temp;

    void recursion(vector<NestedInteger> &some_list) {  //just a simple recursive function
        int n = some_list.size();

        for(int i = 0; i < n; i++) {
            if(some_list[i].isInteger()) 
                temp.push_back(some_list[i].getInteger());

            else 
                recursion(some_list[i].getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();

        for(int i = 0; i < n; i++) {
            if(nestedList[i].isInteger()) //if the current number is an integer, we simply push it to our flattened list
                list.push_back(nestedList[i].getInteger());

            else { 
                recursion(nestedList[i].getList()); //otherwise we call a helper recursive function, couldn't recursively call the constructor(learnt the hard way)
                list.insert(list.end(), temp.begin(), temp.end());  //insert the list obtained after handling a particular list
                temp.erase(temp.begin(), temp.end());   //empty the temp list used to hold the above list
            }
        }

        no_of_elements = list.size();   //in the end calculate the size of the flattened list
    }
    
    int next() {
        return list[pointer++];
    }
    
    bool hasNext() {
        return pointer < (no_of_elements);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

 //pretty interesting question I would say. The new thing I learnt was that calling constructors recursively is a bad idea. I for some reason thougth that the recusive 
 //constructor would use the original private data members, but they ofcourse do not. 