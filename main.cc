/*
Extra Credit Project
Roberto Velazquez 
CWID:885666107
05/21/24
*/


#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <algorithm>

int div_hash(int key, int M);
int mid_sqr_hash(int key, int M);
int double_hash(int key, int M);
int mult_hash(int key, double A, int M);
bool is_palindrome(int n);

int div_hash(int key, int M) {
    if (M <= 0) throw std::invalid_argument("M must be positive");
    return (key % M + M) % M;
}

int mid_sqr_hash(int key, int M) {
    if (M <= 0) throw std::invalid_argument("M must be positive");
    long long squared_key = static_cast<long long>(key) * key;
    std::string squared_str = std::to_string(squared_key);
    int mid_pos = squared_str.size() / 2;

    std::string mid_digits_str;
    if (squared_str.size() < 3) {
        mid_digits_str = squared_str;
    } else if (squared_str.size() % 2 == 0) {
        mid_digits_str = squared_str.substr(mid_pos - 1, 2);
    } else {
        mid_digits_str = squared_str.substr(mid_pos, 1);
    }

    int mid_digits = std::stoi(mid_digits_str);
    return mid_digits % M;
}

int double_hash(int key, int M) {
    if (M <= 0) throw std::invalid_argument("M must be positive");
    if (M == 1) return 0;
    int h1 = (key % M + M) % M;
    int h2 = 1 + (key % (M - 1) + M - 1) % (M - 1);
    int rehash = 0;

    for (int i = 1; i <= 5; ++i) {
        rehash = (h1 + i * h2) % M;
        if (is_palindrome(rehash)) {
            return rehash;
        }
    }
    std::string rehash_str = std::to_string(rehash);
    std::reverse(rehash_str.begin(), rehash_str.end());
    return std::stoi(rehash_str);
}

bool is_palindrome(int n) {
    std::string s = std::to_string(n);
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

int mult_hash(int key, double A, int M) {
    if (!(0 < A && A < 1)) {
        throw std::invalid_argument("A must be a float between 0 and 1");
    }
    if (M <= 0) throw std::invalid_argument("M must be positive");
    double fractional_part = std::fmod(key * A, 1.0);
    return static_cast<int>(M * fractional_part);
}

int main() {
    struct TestCase {
        int key;
        int M;
        double A;
        std::string test_type;
    };

    TestCase test_cases[] = {
        {12345, 95, 0.357840, "all"},
        {60, 100, 0.5, "all"},
        {123456, 999, 0.618033, "all"},
        {987654321, 1000, 0.707106, "all"},
        {56789, 500, 0.414213, "all"},
        {11111, 123, 0.333333, "all"},
        {55555, 345, 0.577215, "all"},
        {13579, 100, 0.693147, "all"},
        {24680, 789, 0.261799, "all"},
        {99999, 654, 0.101010, "all"},
        {0, 100, 0.5, "all"},
        {123, 1, 0.5, "all"},
        {123, 123456, 0.123456, "all"},
        {123, 100, 0.999999, "all"},
        {1, 10, 0.5, "all"},
        {100000, 1000, 0.314159, "all"},
        {12345, 95, 1, "all"},
        {12345, 95, 0, "all"},
        {0, 100, 0.5, "all"},
        {-1, 100, 0.5, "all"}
    };

    for (int i = 0; i < sizeof(test_cases)/sizeof(TestCase); ++i) {
        TestCase tc = test_cases[i];
        std::cout << "Test Case " << i+1 << ": Key = " << tc.key << ", M = " << tc.M << ", A = " << tc.A << std::endl;
        
        try {
            if (tc.test_type == "all" || tc.test_type == "div") {
                std::cout << "  Div Hash: " << div_hash(tc.key, tc.M) << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "  Div Hash: " << e.what() << std::endl;
        }
        
        try {
            if (tc.test_type == "all" || tc.test_type == "mid") {
                std::cout << "  Mid Square Hash: " << mid_sqr_hash(tc.key, tc.M) << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "  Mid Square Hash: " << e.what() << std::endl;
        }
        
        try {
            if (tc.test_type == "all" || tc.test_type == "double") {
                std::cout << "  Double Hash: " << double_hash(tc.key, tc.M) << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "  Double Hash: " << e.what() << std::endl;
        }
        
        try {
            if (tc.test_type == "all" || tc.test_type == "mult") {
                std::cout << "  Multiplicative Hash: " << mult_hash(tc.key, tc.A, tc.M) << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "  Multiplicative Hash: " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
