#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

struct Student {
    char name[50]{};
    char surname[50]{};
    int course{};
    char group[20]{};
    int grades[5]{};
};

int CountFracDigits(double x) {
    if (x < 0) x = -x;
    long long ip = static_cast<long long>(x);
    double frac = x - static_cast<double>(ip);
    std::ostringstream os;
    os.setf(std::ios::fixed);
    os.precision(15);
    os << frac;
    std::string s = os.str();
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    auto pos = s.find('.');
    return (pos == std::string::npos) ? 0 : int(s.size() - pos - 1);
}

int PartitionQS(double* a, int lo, int hi, bool asc) {
    double pivot = a[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if ((asc && a[j] <= pivot) || (!asc && a[j] >= pivot)) {
            std::swap(a[++i], a[j]);
        }
    }
    std::swap(a[i + 1], a[hi]);
    return i + 1;
}

void QuickSort(double* a, int lo, int hi, bool asc) {
    if (lo < hi) {
        int p = PartitionQS(a, lo, hi, asc);
        QuickSort(a, lo, p - 1, asc);
        QuickSort(a, p + 1, hi, asc);
    }
}

void InsertionSort(double* a, int n, bool asc) {
    for (int i = 1; i < n; ++i) {
        double key = a[i];
        int j = i - 1;
        while (j >= 0 && ((asc && a[j] > key) || (!asc && a[j] < key))) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

void SelectionSort(double* a, int n, bool asc) {
    for (int i = 0; i + 1 < n; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if ((asc && a[j] < a[idx]) || (!asc && a[j] > a[idx])) {
                idx = j;
            }
        }
        std::swap(a[i], a[idx]);
    }
}

void Merge(double* a, int lo, int mid, int hi, bool asc) {
    int nl = mid - lo + 1;
    int nr = hi - mid;
    double* L = new double[nl] {};
    double* R = new double[nr] {};
    for (int i = 0; i < nl; ++i) L[i] = a[lo + i];
    for (int j = 0; j < nr; ++j) R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = lo;
    while (i < nl && j < nr) {
        if ((asc && L[i] <= R[j]) || (!asc && L[i] >= R[j])) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }
    while (i < nl) a[k++] = L[i++];
    while (j < nr) a[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void MergeSort(double* a, int lo, int hi, bool asc) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        MergeSort(a, lo, mid, asc);
        MergeSort(a, mid + 1, hi, asc);
        Merge(a, lo, mid, hi, asc);
    }
}

void ImprovedBubbleSort(double* a, int n, bool asc) {
    for (int m = n; m > 1; --m) {
        bool swapped = false;
        for (int i = 1; i < m; ++i) {
            if ((asc && a[i - 1] > a[i]) || (!asc && a[i - 1] < a[i])) {
                std::swap(a[i - 1], a[i]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int PartitionFrac(double* a, int lo, int hi) {
    double pivot = a[hi];
    int dp = CountFracDigits(pivot);
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (CountFracDigits(a[j]) >= dp) {
            std::swap(a[++i], a[j]);
        }
    }
    std::swap(a[i + 1], a[hi]);
    return i + 1;
}

void QuickSortFrac(double* a, int lo, int hi) {
    if (lo < hi) {
        int p = PartitionFrac(a, lo, hi);
        QuickSortFrac(a, lo, p - 1);
        QuickSortFrac(a, p + 1, hi);
    }
}

double* ReadFromConsole(int& n) {
    std::cin >> n;
    double* a = new double[n] {};
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    return a;
}

double* ReadFromFile(const char* fn, int& n) {
    std::ifstream in(fn);
    if (!in) return nullptr;
    n = 0; double x{};
    while (in >> x) ++n;
    in.clear(); in.seekg(0);
    double* a = new double[n] {};
    for (int i = 0; i < n; ++i) in >> a[i];
    return a;
}

void WriteToConsole(double* a, int n) {
    for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
    std::cout << "\n";
}

void WriteToFile(double* a, int n, const char* fn) {
    std::ofstream out(fn);
    if (!out) return;
    for (int i = 0; i < n; ++i) out << a[i] << " ";
}

void ProcessRealArray() {
    int src{}; std::cin >> src;
    double* arr = nullptr;
    int n{};
    if (src == 1) arr = ReadFromConsole(n);
    else {
        char fn[256]{}; std::cin >> fn;
        arr = ReadFromFile(fn, n);
    }
    if (!arr || n <= 0) return;
    int algo{}; std::cin >> algo;
    bool asc = true;
    if (algo >= 1 && algo <= 5) {
        int ord{}; std::cin >> ord;
        asc = (ord == 1);
    }
    switch (algo) {
    case 1: QuickSort(arr, 0, n - 1, asc);     
        break;
    case 2: InsertionSort(arr, n, asc);        
        break;
    case 3: SelectionSort(arr, n, asc);         
        break;
    case 4: MergeSort(arr, 0, n - 1, asc);      
        break;
    case 5: ImprovedBubbleSort(arr, n, asc);   
        break;
    case 6: QuickSortFrac(arr, 0, n - 1);      
        break;
    default: delete[] arr; return;
    }
    int dest{}; std::cin >> dest;
    if (dest == 1) WriteToConsole(arr, n);
    else {
        char fn[256]{}; std::cin >> fn;
        WriteToFile(arr, n, fn);
    }
    delete[] arr;
}

void ProcessStudents() {
    int n{}; std::cin >> n;
    Student* st = new Student[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> st[i].name
            >> st[i].surname
            >> st[i].course
            >> st[i].group;
        for (int j = 0; j < 5; ++j)
            std::cin >> st[i].grades[j];
    }
    for (int i = 0; i + 1 < n; ++i) {
        int idx = i;
        double sumI = 0;
        for (int k = 0; k < 5; ++k) sumI += st[i].grades[k];
        double avgI = sumI / 5.0;
        for (int j = i + 1; j < n; ++j) {
            double sumJ = 0;
            for (int k = 0; k < 5; ++k) sumJ += st[j].grades[k];
            double avgJ = sumJ / 5.0;
            if (avgJ > avgI) {
                idx = j;
                avgI = avgJ;
            }
        }
        if (idx != i) std::swap(st[i], st[idx]);
    }
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int k = 0; k < 5; ++k) sum += st[i].grades[k];
        double avg = sum / 5.0;
        int avg100 = (avg >= 0 ? int(avg * 100 + 0.5) : int(avg * 100 - 0.5));
        int whole = avg100 / 100;
        int frac = avg100 % 100; if (frac < 0) frac = -frac;
        std::cout
            << st[i].name << " "
            << st[i].surname << " "
            << st[i].course << " "
            << st[i].group << " "
            << whole << '.'
            << (frac < 10 ? "0" : "") << frac
            << "\n";
    }
    delete[] st;
}

int main() {
    int choice{};
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1 - Sort a real-number array\n";
        std::cout << "2 - Sort student records\n";
        std::cout << "0 - Exit\n";
        std::cout << "Your choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            std::cout << "\n-- Real-Number Array Sorting --\n";
            std::cout << "Choose input: 1 - Console, 2 - File\n";
            ProcessRealArray();
        }
        else if (choice == 2) {
            std::cout << "\n-- Student Record Sorting --\n";
            std::cout << "Entering student data...\n";
            ProcessStudents();
        }
        else if (choice == 0) {
            std::cout << "\nThank you for using the sorter. Goodbye!\n";
            break;
        }
        else {
            std::cout << "\nInvalid option, please try again.\n";
        }
    }
    return 0;
}