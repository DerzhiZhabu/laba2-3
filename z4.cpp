#include <iostream>
#include <string>

bool isMatch(const std::string& str, const std::string& pattern) {
    int m = str.size();
    int n = pattern.size();

    // Создаем двумерный массив для хранения результатов
    bool** dp = new bool*[m + 1];
    for (int i = 0; i <= m; ++i) {
        dp[i] = new bool[n + 1];
    }

    // Инициализация
    dp[0][0] = true; // Пустая строка соответствует пустому шаблону

    // Обрабатываем случай, когда шаблон начинается с '*'
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = (pattern[j - 1] == '*') && dp[0][j - 1];
    }

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = false; // Непустая строка не может соответствовать пустому шаблону
    }

    // Заполнение массива
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; // Совпадение символов
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' заменяет символ или пустую последовательность
            } else {
                dp[i][j] = false; // Символы не совпадают
            }
        }
    }

    // Результат находится в dp[m][n]
    bool result = dp[m][n];

    // Освобождаем память
    for (int i = 0; i <= m; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    std::string str, pattern;

    // Ввод строки и шаблона
    std::cout << "Введите строку: ";
    std::cin >> str;
    std::cout << "Введите шаблон: ";
    std::cin >> pattern;

    // Проверка на соответствие
    if (isMatch(str, pattern)) {
        std::cout << "Строка соответствует шаблону.\n";
    } else {
        std::cout << "Строка не соответствует шаблону.\n";
    }

    return 0;
}
