#include "iostream"
#include "ctime"
#include "utility"
#include "unordered_map"
#include "string"
#include "vector"
#include "array"
#include "iomanip"

using namespace std;

//<editor-fold desc="Working with dates">
const static int NUMBER_OF_MONTHS = 12;
static const int NUMBER_OF_DAYS = 36494;

struct Date {
    int year;
    int month;
    int day;

    Date() {}

    Date(int year_, int month_, int day_) : year(year_), month(month_), day(day_) {};

    time_t AsTimeStamp() const {
        std::tm t;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_mday = day;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;
        t.tm_isdst = 0;
        return mktime(&t);
    }

    bool IsLeapYear() {
        return (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
    }
};

istream &operator>>(istream &in, Date &d) {
    in >> d.year;
    in.ignore(1);
    in >> d.month;
    in.ignore(1);
    in >> d.day;
    return in;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <
    tie(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) ==
    tie(rhs.year, rhs.month, rhs.day);
}

bool operator<=(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <=
    tie(rhs.year, rhs.month, rhs.day);
}

struct DateHasher {
    size_t operator()(const Date &date) const {
        size_t r1 = ihasher(date.year);
        size_t r2 = ihasher(date.month);
        size_t r3 = ihasher(date.day);
        size_t x = 31;
        return (r1 * x * x + r2 * x + r3);
    }

    hash<int> ihasher;
};

int ComputeDaysDiff(const Date &to, const Date &from) {
    const time_t time_to = to.AsTimeStamp();
    const time_t time_from = from.AsTimeStamp();
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
    return (time_to - time_from) / SECONDS_IN_DAY;
}


Date &operator++(Date &d) {
    const array<int, NUMBER_OF_MONTHS> month_lengths{
        31, 28 + d.IsLeapYear(), 31, 30, 31,
        30, 31, 31, 30, 31, 30, 31
    };
    int num_days = month_lengths[d.month - 1];
    // case 1: day is less than the number of days in the month
    if (d.day < num_days) {
        ++d.day;
        return d;
    } else { // day is the last day in the month
        if (d.month < 12) { // if not the last month in the year
            ++d.month;
            d.day = 1;
            return d;
        } else { // if last month in the year
            ++d.year;
            d.month = 1;
            d.day = 1;
        }
    }
    return d;
}

const static Date START_DATE = Date{2000, 01, 01};;

    //</editor-fold>

    struct MoneyState {
        double earned = 0;
        double spent = 0;
    };

    MoneyState operator+=(const MoneyState &l, const MoneyState &r) {
        return {l.earned + r.earned, l.spent + r.spent};
    }

    class BudgetManager {
    public:
        BudgetManager() {
            earned.fill({0, 0});
        }

        double ComputeIncome(const Date &from, const Date &to) const;

        void Earn(const Date &from, const Date &to, double amount);

        void PayTax(const Date &from, const Date &to, int tax);

        void Spend(const Date &from, const Date &to, double amount);

    private:
        unordered_map<Date, MoneyState, DateHasher> date_to_amounts;
        array<MoneyState, NUMBER_OF_DAYS> earned;
    };

    void BudgetManager::Spend(const Date &from, const Date &to, double amount) {
        int days_diff = ComputeDaysDiff(to, from);
        double spent_per_day = amount / (days_diff + 1);

        int from_idx = ComputeDaysDiff(from, START_DATE);
        int to_idx = ComputeDaysDiff(to, START_DATE);

        for(; from_idx <= to_idx; ++from_idx) {
            earned[from_idx].spent += spent_per_day;
        }
    }

    void BudgetManager::PayTax(const Date &from, const Date &to, int tax) {
        double t = 1.0 - tax * 1.0 / 100;

        int from_idx = ComputeDaysDiff(from, START_DATE);
        int to_idx = ComputeDaysDiff(to, START_DATE);

        for(; from_idx <= to_idx; ++from_idx) {
            earned[from_idx].earned *= t;
        }
    }

    void BudgetManager::Earn(const Date &from, const Date &to, double amount) {
        int days_diff = ComputeDaysDiff(to, from);
        int from_idx = ComputeDaysDiff(from, START_DATE);
        int to_idx = ComputeDaysDiff(to, START_DATE);

        double earned_per_day = amount / (days_diff + 1);

        for (; from_idx <= to_idx; ++from_idx) {
            earned[from_idx].earned += earned_per_day;
        }
    }

    double BudgetManager::ComputeIncome(const Date &from, const Date &to) const {
        double res = 0;
        int from_idx = ComputeDaysDiff(from, START_DATE);
        int to_idx = ComputeDaysDiff(to, START_DATE);
        for (; from_idx <= to_idx; ++from_idx) {
            res += earned[from_idx].earned;
            res -= earned[from_idx].spent;
        }
        return res;
    }


    int main() {
        int q;
        cin >> q;
        BudgetManager manager;
        for (int i = 0; i < q; ++i) {
            string command;
            Date from{};
            Date to{};
            cin >> command >> from >> to;
            if (command == "Earn") {
                double amount;
                cin >> amount;
                manager.Earn(from, to, amount);
            } else if (command == "ComputeIncome") {
                cout << setprecision(25) << manager.ComputeIncome(from, to) << endl;
            } else if (command == "PayTax") {
                int tax;
                cin >> tax;
                manager.PayTax(from, to, tax);
            } else if (command == "Spend") {
                double amount;
                cin >> amount;
                manager.Spend(from, to, amount);
            }
        }
        return 0;
    }
























