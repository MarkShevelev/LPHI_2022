#include <iostream>

enum class weekday_t {MON, TUE, WED, THU, FRI, SAT, SUN}; // int equivalents are 0, 1, 2, 3, 4, 5, 6

weekday_t next_day(weekday_t day) {
    if (weekday_t::SUN == day) return weekday_t::MON;
    return static_cast<weekday_t>(1 + static_cast<int>(day)); // be carefull with the casts !!!
}

weekday_t operator+(weekday_t day, unsigned day_interval) {
    auto diff = day_interval / 7;
    weekday_t result = day;
    switch(diff) {
        case 6:
            result = next_day(result);
        case 5:
            result = next_day(result);
        case 4:
            result = next_day(result);
        case 3:
            result = next_day(result);
        case 2:
            result = next_day(result);
        case 1:
            result = next_day(result);
    }
    return result;
}

using namespace std;

int main() {
    weekday_t today = weekday_t::MON;
    auto next_day = today + 8u;                 // the '+' operator has been overloaded up-code
    cout << static_cast<int>(next_day) << endl;

    weekday_t day = static_cast<weekday_t>(9);

    return 0;
}