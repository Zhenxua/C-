#include "rat.h"
#include <iostream>

int main() {
    try {
        // 创建一些 Rat 对象
        Rat r1(3, 4);       // 3/4
        Rat r2(5, 6);       // 5/6
        Rat r3(2);          // 2/1 (构造函数中没有指定分母)
        Rat r4;             // 0/1 (使用默认构造函数)

        // 显示初始值
        std::cout << "Valeurs initiales :" << std::endl;
        std::cout << "r1 = " << r1 << std::endl;
        std::cout << "r2 = " << r2 << std::endl;
        std::cout << "r3 = " << r3 << std::endl;
        std::cout << "r4 = " << r4 << std::endl;

        // 测试 += 运算符
        r1 += r2;
        std::cout << "Après r1 += r2: r1 = " << r1 << std::endl;

        r1 += 2;
        std::cout << "Après r1 += 2: r1 = " << r1 << std::endl;

        // 测试 -= 运算符
        r2 -= r3;
        std::cout << "Après r2 -= r3: r2 = " << r2 << std::endl;

        r2 -= 1;
        std::cout << "Après r2 -= 1: r2 = " << r2 << std::endl;

        // 测试 *= 运算符
        r3 *= r1;
        std::cout << "Après r3 *= r1: r3 = " << r3 << std::endl;

        r3 *= 3;
        std::cout << "Après r3 *= 3: r3 = " << r3 << std::endl;

        // 测试 /= 运算符
        r1 /= r2;
        std::cout << "Après r1 /= r2: r1 = " << r1 << std::endl;

        r1 /= 2;
        std::cout << "Après r1 /= 2: r1 = " << r1 << std::endl;

        // 测试比较运算符
        std::cout << "\nTest des opérateurs de comparaison :" << std::endl;
        std::cout << "r1 == r2: " << (r1 == r2 ? "Vrai" : "Faux") << std::endl;
        std::cout << "r1 != r2: " << (r1 != r2 ? "Vrai" : "Faux") << std::endl;
        std::cout << "r1 < r2: " << (r1 < r2 ? "Vrai" : "Faux") << std::endl;
        std::cout << "r1 <= r2: " << (r1 <= r2 ? "Vrai" : "Faux") << std::endl;
        std::cout << "r1 > r2: " << (r1 > r2 ? "Vrai" : "Faux") << std::endl;
        std::cout << "r1 >= r2: " << (r1 >= r2 ? "Vrai" : "Faux") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
