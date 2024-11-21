#include <iostream>
#include <string>

bool isMatch(const std::string& str, const std::string& pattern) {
    int m = str.size();
    int n = pattern.size();

    bool** dp = new bool*[m + 1];
    for (int i = 0; i <= m; ++i) {
        dp[i] = new bool[n + 1];
    }


    dp[0][0] = true;

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = (pattern[j - 1] == '*') && dp[0][j - 1];
    }

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = false;
    }

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; 
            } else {
                dp[i][j] = false; 
            }
        }
    }

    
    bool result = dp[m][n];

    
    for (int i = 0; i <= m; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    std::string str, pattern;

    std::cout << "Введите строку: ";
    std::cin >> str;
    std::cout << "Введите шаблон: ";
    std::cin >> pattern;


    if (isMatch(str, pattern)) {
        std::cout << "Строка соответствует шаблону.\n";
    } else {
        std::cout << "Строка не соответствует шаблону.\n";
    }

    return 0;
}
