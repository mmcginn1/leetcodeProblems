/*
  Title: Two Sum
  Author: Matthew McGinn
  Date: 6/8/19

*/

#include<iostream>
#include<fstream>
#include<vector>

int* twoSum(const std::vector<uint64_t>& nums, uint64_t target){
  int *result = new int[2];
  for (uint64_t inx1 = 0; inx1 < nums.size(); inx1++){
    for (uint64_t inx2 = inx1 + 1; inx2 < nums.size(); inx2++){
      if (nums[inx1] + nums[inx2] == target){
	std::cout << "Sum found. \n" << std::endl;
        std::cout << "First number is " << nums[inx1] << " at: " << inx1 << std::endl;
	std::cout << "Second number is " << nums[inx2] << " at: " << inx2 << std::endl;
	result[0] = inx1;
	result[1] = inx2;
	return result;
      }
    }
  }
  return nullptr;
}


int main(){
  uint64_t target, numsElement;
  int* result;
  std::vector<uint64_t> nums;
  std::fstream dataFile("twoSumFile.txt", std::ios_base::in);
  
  if (dataFile.is_open()){
    dataFile >> target;
    while (dataFile >> numsElement){
      nums.push_back(numsElement);
    }
    result = twoSum(nums, target);
    delete result;  //maybe it'd be better to use a void function but for now, this'll do I hope
  }
  else {
    std::cout << "Error opening twoSumFile.txt" << std::endl;
  }
  system("pause");
  return 0;
}

/*
Prompt:



Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
  Thoughts/Ideas:


    First, we need to establish the input format for the test document.
    Perhaps the first number will be the target and the second will be the nums array, let's make that now
    Next, consider the fact that we don't need to look up everything twice, we could have a nested for loop to eliminate redundancy

    According to the solutions, hashmaps storing complements are another approach
*/
