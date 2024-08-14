* 最大公约数GCD(greatest common divisor) 求解：https://oi-wiki.org/math/number-theory/gcd/

一个简单的推导公式就是   gcd(a,b) = gcd(b, a mod b)



不自己实现gcd的话：

C++14 可以用 __gcd(a,b)，C++17 可以用 std::gcd，std::lcm