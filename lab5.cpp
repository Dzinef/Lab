#include <iostream>
#include <random> 

void InputMatrix(int** matrix, int n) {
    std::cout << "Enter the elements " << n << "x" << n << ":\n";
    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j)
            std::cin >> matrix[i][j];
}

void Random(int** matrix, int n, int min_val, int max_val) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_val, max_val);
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            matrix[i][j] = dist(gen);
        }
    }
}

void OutputMatrix(int** matrix, int n) {
    std::cout << "Matrix:\n";
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j)
            std::cout << matrix[i][j] << '\t';
        std::cout << '\n';
    }
}

bool CheckingZeros(int** matrix, int n) {
    for (int i{}; i < n; ++i) {
        int row_zero{}, col_zero{};
        for (int j{}; j < n; ++j) {
            if (matrix[i][j] == 0) 
                ++row_zero;
            if (matrix[j][i] == 0) 
                ++col_zero;
        }
        if (row_zero != 1 || col_zero != 1)
            return false;
    }
    return true;
}

bool Ordering(int** matrix, int n, int* row_order) {
    for (int col{}; col < n; ++col) {
        bool found = false;
        for (int row{}; row < n; ++row) {
            if (matrix[row][col] == 0) {
                row_order[col] = row;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void Rows(int** matrix, int n, int* row_order) {
    int** temp = new int* [n];
    for (int i{}; i < n; ++i)
        temp[i] = matrix[row_order[i]];
    for (int i{}; i < n; ++i)
        matrix[i] = temp[i];
    delete[] temp;
}

int64_t ProductBelowDiagonal(int** matrix, int n) {
    long long prod = 1;
    bool has_elements = false;
    for (int i{ 1 }; i < n; ++i)
        for (int j{}; j < i; ++j) {
            prod *= matrix[i][j];
            has_elements = true;
        }
    return has_elements ? prod : 0;
}

int main() {
    try {
        int n{};
        std::cout << "Enter size: ";
        std::cin >> n;
        if (n <= 0) 
            throw "Size will be positive";
        int** matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n];
        }
        int choice{};
        std::cout << "Chooise:\n1 - sam\n2 - random\nYour cooise: ";
        std::cin >> choice;
        if (choice == 1) {
            InputMatrix(matrix, n);
        }
        else if (choice == 2) {
            int min_val, max_val;
            std::cout << "Max and min: ";
            std::cin >> min_val >> max_val;
            Random(matrix, n, min_val, max_val);
        }
        else {
            throw "Error.";
        }
        std::cout << "\nFirst ";
        OutputMatrix(matrix, n);
        bool rearranged = false;
        if (CheckingZeros(matrix, n)) {
            int* row_order = new int[n];
            if (Ordering(matrix, n, row_order)) {
                Rows(matrix, n, row_order);
                rearranged = true;
                std::cout << "\nAfter transform:\n";
                OutputMatrix(matrix, n);
            }
            delete[] row_order;
        }
        else {
            std::cout << "\nSomething with nulls.\n";
        }
        long long result = ProductBelowDiagonal(matrix, n);
        std::cout << "\nProduct Below Diagonal: " << result << '\n';
        for (int i = 0; i < n; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg << '\n';
    }
    return 0;
}