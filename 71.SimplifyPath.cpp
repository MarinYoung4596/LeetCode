/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.
Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.


Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.


Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.


Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.


Example 4:
Input: "/a/./b/../../c/"
Output: "/c"


Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"


Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/


class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> dirs;
        split(path, '/', dirs);
        std::stack<std::string> s;
        for (const auto &dir : dirs) {
            if (dir == "." || dir.empty()) {
                continue;
            } else if (dir == "..") {
                if (s.empty()) {
                    continue;
                }
                s.pop();
            } else {
                s.push(dir);
            }
        }
        std::string result;
        while (!s.empty()) {
            result = s.top() + "/" + result;
            s.pop();
        }
        return "/" +  result.substr(0, result.size() - 1);
    }

private:
    void split(const std::string &str, char sep, std::vector<std::string> &vec) {
        if (str.empty()) {
            return;
        }
        if (!vec.empty()) {
            vec.clear();
        }
        auto begin = 0;
        auto end = str.find_first_of(sep);
        while (end != std::string::npos) {
            vec.push_back(str.substr(begin, end - begin));
            begin = str.find_first_not_of(sep, end);
            end = str.find_first_of(sep, begin);
        }
        if (begin != end) {
            vec.push_back(str.substr(begin, end - begin));
        }
    }
};