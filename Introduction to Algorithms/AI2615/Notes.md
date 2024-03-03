# 算法设计与分析 课堂笔记

### 一、函数的渐进的界

##### 渐进的界

求解$f(n)=n^\frac{1}{logn}=\Theta(1)$

对函数取对数得$ln(f(n))=\frac{lnn}{logn}$，由换底公式可知，当$n\rightarrow+\infty$时$ln(f(n))$为常数，证毕。

##### 阶乘函数

$f(n)=n!$是增长很快的函数，根据Stirling公式，阶乘函数
$$
n！=\sqrt{2\pi n}(\frac{n}{e})^n[1+\Theta(\frac{1}{n})]
$$
关于阶乘函数有下面的结果：
$$
n!=\omicron(n^n)   \quad	n!=\omega(2^n)   \quad	log(n!)=\Theta(nlogn)
$$
