/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
    n = 15,
    Return:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
*/


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> result;
        for (auto i = 1; i <= n; ++i) {
            bool is_3_mul = i % 3 == 0;
            bool is_5_mul = i % 5 == 0;
            if (is_3_mul && is_5_mul) {
                result.push_back("FizzBuzz");
            } else if (is_3_mul) {
                result.push_back("Fizz");
            } else if (is_5_mul) {
                result.push_back("Buzz");
            } else {
                result.push_back(std::to_string(i));
            }
        }
        return result;
    }
};