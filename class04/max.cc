/**
 * Compute max of vector and assert pre-conditions and post conditions
 * @file max.cc
 * @author Tom Helmuth
 * @collaborators CS230
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Compute max int in vector nums
 *
 * Pre-conditions: nums is a non-empty vector of ints
 * Post-conditions: largest is the max element in nums
 * 
 * @param nums non-empty list of integers
 * @return max int in nums
 */
int max(vector<int> nums){

    // pre-condition: what is true as function is beginning
    assert(nums.size() > 0);

    int largest = nums[0];
    for(size_t i = 1; i < nums.size(); i++){

        // Loop Invariant: largest >= all elements up to i - 1
        for(size_t j = 0; j < i; j++){
            assert(largest >= nums[j]);
        }
        
        if(nums[i] > largest)
            largest = nums[i];
    }

    // post-condition: what is true at the end of a function
    // Check that the answer is correct
    for(size_t j = 0; j < nums.size(); j++){
        assert(largest >= nums[j]);
    }

    return largest;
}



// Controls operation of the program.
int main() {

    vector<int> primes = {7, 5, 11, 13, 2, 3};

    vector<int> empty;

    vector<int> one_element = {5};

    cout << max(primes) << endl;
    return 0;
}
