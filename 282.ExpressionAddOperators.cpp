/*
282. Expression  Add operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

*/

class Solution {
public:
    vector<string> addOperators(string &num, int target) 
    {
        vector<string> result;
        if (num.size() < 1) return result;
        dfs(num, target, 0, "", 0, 0, result);
        return result;
    }
    
private:
    void dfs(const string &num, const int target, 
            int curr_index, string path, long prev_value, long curr_res, vector<string> &result)
    {
        if (curr_index == num.size())
        {
            if (curr_res == target) result.push_back(path);
            return;
        }
        
        for (auto i = curr_index; i < num.size(); ++i)
        {
            if (num[curr_index] == '0' && i > curr_index) break; // why?
            
            auto sub_str = num.substr(curr_index, i-curr_index+1);
            long next_value = atoi(sub_str.c_str());
            
            // here, curr_index MUST be i+1 to prevent duplicates
            if (curr_index)
            {
                dfs(num, target, i+1, path+"+"+sub_str, next_value, curr_res+next_value, result);
                dfs(num, target, i+1, path+"-"+sub_str, -next_value, curr_res-next_value, result);
                /*
                这里，假设实参  num = "234", target = 14, path = "2+3", prev_value = 3, curr_res = 6, curr_index = 1
                计算得      next_value = 4
                运算符优先级不同，必需回溯以保证正确性
                we want 2+3*4 = 14, so we can't simply set @curr_res being curr_res*next_value, which is 6*4=24, 
                and the @path is 2+3*4, however, it should be 14, so we need backtrack to guarantee the correctness.
                */
                dfs(num, target, i+1, path+"*"+sub_str, prev_value*next_value, (curr_res-prev_value)+prev_value*next_value, result);
            }
            else
            {
                dfs(num, target, i+1, sub_str, next_value, next_value, result);
            }
        }
    }
};