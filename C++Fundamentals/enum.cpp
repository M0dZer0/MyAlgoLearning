#include <iostream>

// 定义一个枚举类型，表示星期几
enum Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday = 10086,
    Saturday,
    Sunday
};

int main() {
    // 声明一个枚举类型的变量，并赋值为枚举常量
    Weekday today = Wednesday;

    // 输出当前星期几
    switch (today) {
        case Monday:
            std::cout << "Today is Monday.\n";
            break;
        case Tuesday:
            std::cout << "Today is Tuesday.\n";
            break;
        case Wednesday:
            std::cout << "Today is Wednesday.\n";
            break;
        case Thursday:
            std::cout << "Today is Thursday.\n";
            break;
        case Friday:
            std::cout << "Today is Friday.\n";
            break;
        case Saturday:
            std::cout << "Today is Saturday.\n";
            break;
        case Sunday:
            std::cout << "Today is Sunday.\n";
            break;
        default:
            std::cout << "Invalid day.\n";
            break;
    }
    std::cout << "Size of Weekday: " << sizeof(Weekday) << std::endl;
    std::cout << today << std::endl;
    std::cout << Sunday << std::endl;
    return 0;
}
