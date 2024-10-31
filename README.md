# CPP Module 02

<div align="center">
  <img src="assets/14_cpp_module_02_review.jpg" alt="CPP Module 02 Review" width="800"/>
  
  [![42 Score](https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42)](https://github.com/your-username/CPP-Module-02)
</div>

## Table of Contents
- [About](#about)
- [Requirements](#requirements)
- [Implementation](#implementation)
  - [ex00: My First Orthodox Class](#ex00-my-first-orthodox-class)
  - [ex01: Towards a more useful fixed-point number class](#ex01-towards-a-more-useful-fixed-point-number-class)
  - [ex02: Now we're talking](#ex02-now-were-talking)
  - [ex03: BSP](#ex03-bsp)
- [Usage](#usage)
- [Testing & Debug](#testing--debug)
- [Additional Information](#additional-information)
  - [Orthodox Canonical Form](#orthodox-canonical-form)
  - [Operator Overloading](#operator-overloading)
  - [Fixed Point Numbers](#fixed-point-numbers)
- [Reference](#reference)

### 🗣️ About
C++의 Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form을 학습하는 세 번째 C++ 모듈입니다.

• 학습 목표
  - Orthodox Canonical Form 이해와 구현
  - 연산자 오버로딩의 개념과 활용
  - 고정 소수점 수의 구현
  - Ad-hoc 다형성의 이해

• 주요 개념
  - Orthodox Canonical Form
    - 기본 생성자
    - 복사 생성자
    - 대입 연산자 오버로딩
    - 소멸자
  
  - Operator Overloading
    - 산술 연산자
    - 비교 연산자
    - 증감 연산자
    - 입출력 연산자
  
  - Fixed Point Numbers
    - 고정 소수점 표현
    - 정수부와 소수부 관리
    - 형변환

### Requirements
• 컴파일러
  - c++ (clang++)
  - -Wall -Wextra -Werror
  - -std=c++98

• 금지 사항
  - STL 사용 금지
  - <string.h> 대신 <string> 사용
  - printf 대신 cout 사용
  - 전역 변수 사용 금지

• 준수 사항
  - Orthodox Canonical Form 필수
  - 모든 클래스 헤더 파일 필요
  - 모든 멤버 함수 구현 필요

### Implementation

#### ex00: My First Orthodox Class
• 요구사항
  - Fixed Point Number 클래스 구현
  - Orthodox Canonical Form 준수
  - 정수를 고정 소수점으로 변환

• 클래스 구조
```cpp
class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed(void);                          // 기본 생성자
    Fixed(const Fixed& src);              // 복사 생성자
    Fixed& operator=(const Fixed& rhs);    // 대입 연산자
    ~Fixed(void);                         // 소멸자

    int     getRawBits(void) const;       // 고정소수점 값 반환
    void    setRawBits(int const raw);    // 고정소수점 값 설정
};
```

• 구현 예시
```cpp
// 기본 생성자
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 복사 생성자
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// 대입 연산자
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// 소멸자
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// getter
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// setter
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}
```

• 학습 포인트
  - Orthodox Canonical Form의 필수 요소
  - 고정 소수점 수의 기본 개념
  - const 멤버 함수의 활용
  - this 포인터의 사용

#### ex01: Towards a more useful fixed-point number class
• 요구사항
  - Fixed 클래스 확장
  - 다양한 생성자 추가
  - 부동소수점과 정수 변환 구현
  - 출력 연산자 오버로딩

• 클래스 구조
```cpp
class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed(void);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed(void);
    
    // 추가된 생성자
    Fixed(const int n);         // 정수 변환 생성자
    Fixed(const float n);       // 부동소수점 변환 생성자
    
    // 변환 함수
    float   toFloat(void) const;
    int     toInt(void) const;
    
    // getter/setter
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

// 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

• 구현 예시
```cpp
// 정수 변환 생성자
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

// 부동소수점 변환 생성자
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// 부동소수점으로 변환
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// 정수로 변환
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// 출력 연산자
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
```

• 학습 포인트
  - 비트 연산을 통한 고정소수점 구현
  - 형변환 생성자의 활용
  - 연산자 오버로딩의 기본
  - 부동소수점과 고정소수점의 차이
  - roundf 함수의 사용

• 비트 연산 설명
```cpp
// 정수를 고정소수점으로 변환
n << _fractionalBits
// 예: 42 << 8 = 42 * 256 = 10752

// 고정소수점을 정수로 변환
_fixedPointValue >> _fractionalBits
// 예: 10752 >> 8 = 10752 / 256 = 42

// 부동소수점을 고정소수점으로 변환
roundf(n * (1 << _fractionalBits))
// 예: 42.42 * 256 ≈ 10859
```

#### ex02: Now we're talking
• 요구사항
  - 6가지 비교 연산자 구현 (>, <, >=, <=, ==, !=)
  - 4가지 산술 연산자 구현 (+, -, *, /)
  - 증감 연산자 구현 (++, --)
  - min/max 멤버함수 구현

• 클래스 구조
```cpp
class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form + 기존 멤버들...

    // 비교 연산자
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // 산술 연산자
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // 증감 연산자
    Fixed& operator++();        // 전위 증가
    Fixed operator++(int);      // 후위 증가
    Fixed& operator--();        // 전위 감소
    Fixed operator--(int);      // 후위 감소

    // min/max 함수
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};
```

• 구현 예시
```cpp
// 비교 연산자
bool Fixed::operator>(const Fixed& rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

// 산술 연산자
Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result._fixedPointValue = 
        ((long long)this->_fixedPointValue * rhs._fixedPointValue) 
        >> _fractionalBits;
    return result;
}

// 증감 연산자
Fixed& Fixed::operator++() {
    ++this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++this->_fixedPointValue;
    return temp;
}

// min/max 함수
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

// 복합 대입 연산자
Fixed& operator+=(const Fixed& rhs) {
    this->_fixedPointValue += rhs._fixedPointValue;
    return *this;
}

// 단항 연산자
Fixed operator-() const {
    Fixed result;
    result._fixedPointValue = -this->_fixedPointValue;
    return result;
}

// 입력 연산자
friend std::istream& operator>>(std::istream& in, Fixed& fixed) {
    float value;
    in >> value;
    fixed = Fixed(value);
    return in;
}
```

• 학습 포인트
  - 연산자 오버로딩의 다양한 형태
  - 전위/후위 증감 연산자의 차이
  - const 멤버함수의 활용
  - static 멤버함수의 사용
  - 오버플로우 처리 (`long long` 사용)

• 주의사항
```cpp
// 산술 연산시 오버플로우 주의
((long long)a * b) >> bits  // OK
(a * b) >> bits            // 가능한 오버플로우

// 나눗셈시 0 체크
if (rhs._fixedPointValue == 0)
    throw std::runtime_error("Division by zero");

// const 정확성
const Fixed a(42);
a++;  // 컴파일 에러
```

#### ex03: BSP (Binary Space Partitioning)
• 요구사항
  - Point 클래스 구현
  - 삼각형 내부 점 판별 함수 구현
  - Fixed 클래스 활용

• 클래스 구조
```cpp
class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    // Orthodox Canonical Form
    Point();
    Point(const Point& src);
    Point& operator=(const Point& rhs);
    ~Point();
    
    // 추가 생성자
    Point(const float x, const float y);
    
    // getter
    Fixed getX() const;
    Fixed getY() const;
};

// BSP 함수
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

• BSP 시각적 설명
```text
    C(5,10)
     /\
    /  \
   /    \
  /  P   \     P(5,5): 내부 점
 /        \
A(0,0)---->B(10,0)

면적 계산 원리:
1. ABC 전체 면적
2. PAB 면적
3. PBC 면적
4. PCA 면적

판정:
- 내부: PAB + PBC + PCA = ABC
- 외부: PAB + PBC + PCA > ABC
- 경계: 어느 한 부분 면적 = 0
```

• 구현 예시
```cpp
// Point 클래스 구현
Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {}

Point& Point::operator=(const Point& rhs) {
    // const 멤버는 수정 불가능하므로 아무것도 하지 않음
    (void)rhs;
    return *this;
}

Point::~Point() {}

// BSP 함수 구현
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) + 
                 (b.getX() * (c.getY() - a.getY())) + 
                 (c.getX() * (a.getY() - b.getY()))) / 2;
    return area < 0 ? area * -1 : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // 전체 삼각형 면적
    Fixed abcArea = area(a, b, c);
    
    // 점 P를 포함한 세 부분 삼각형의 면적
    Fixed pabArea = area(point, a, b);
    Fixed pbcArea = area(point, b, c);
    Fixed pcaArea = area(point, c, a);
    
    // 면적이 0인 경우 (점이 선 위에 있는 경우) false 반환
    if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
        return false;
    
    // 세 부분 삼각형의 면적 합이 전체 삼각형 면적과 같으면 내부에 있음
    return (pabArea + pbcArea + pcaArea) == abcArea;
}
```

• 학습 포인트
  - const 멤버 변수의 활용
  - 기하학적 알고리즘 구현
  - Fixed 클래스의 실제 응용
  - 복사 생성자와 대입 연산자의 const 처리

• 삼각형 내부 점 판별 원리
```text
1. 전체 삼각형 ABC의 면적 계산
2. 점 P와 각 변을 이용한 세 부분 삼각형의 면적 계산
   - PAB, PBC, PCA
3. 판별 조건
   - P가 내부에 있으면: Area(ABC) = Area(PAB) + Area(PBC) + Area(PCA)
   - P가 선 위에 있으면: 어느 한 부분 삼각형의 면적이 0
   - P가 외부에 있으면: Area(ABC) < Area(PAB) + Area(PBC) + Area(PCA)
```

### Testing & Debug

• 컴파일 및 기본 테스트
```bash
# 컴파일
make                # 전체 컴파일
make ex00          # Fixed 기본 클래스
make ex01          # Fixed 확장 클래스
make ex02          # 연산자 오버로딩
make ex03          # BSP

# 메모리 테스트
valgrind --leak-check=full ./fixed
```

• Exercise별 테스트 케이스
```cpp
// ex00: Orthodox Class 테스트
int main() {
    Fixed a;                    // 기본 생성자
    Fixed b(a);                // 복사 생성자
    Fixed c;
    c = b;                     // 대입 연산자
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}

// ex01: 변환 테스트
int main() {
    Fixed a;
    Fixed const b(10);         // 정수 테스트
    Fixed const c(42.42f);     // 부동소수점 테스트
    Fixed const d(b);
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

// ex02: 연산자 테스트
int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
}

// ex03: BSP 테스트
int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    // 내부 점 테스트
    Point p1(5.0f, 5.0f);     // true
    Point p2(0.0f, 0.0f);     // false (꼭지점)
    Point p3(5.0f, 0.0f);     // false (변 위)
    Point p4(20.0f, 20.0f);   // false (외부)
    
    std::cout << std::boolalpha;
    std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
    std::cout << "p4: " << bsp(a, b, c, p4) << std::endl;
}
```

• 자주 발생하는 문제와 해결
```cpp
// 1. 고정소수점 오버플로우
Fixed Fixed::operator*(const Fixed& rhs) const {
    // 잘못된 방법
    return Fixed(this->toFloat() * rhs.toFloat());
    
    // 올바른 방법
    long long temp = (long long)this->_fixedPointValue * rhs._fixedPointValue;
    return Fixed(temp >> _fractionalBits);
}

// 2. const 정확성
class Fixed {
    // 잘못된 방법
    int getRawBits() { return _fixedPointValue; }
    
    // 올바른 방법
    int getRawBits() const { return _fixedPointValue; }
};

// 3. 비교 연산자 구현
// 최소한의 구현으로 나머지 유도
bool operator<(const Fixed& rhs) const;
bool operator==(const Fixed& rhs) const;

bool operator>(const Fixed& rhs) const { return rhs < *this; }
bool operator<=(const Fixed& rhs) const { return !(*this > rhs); }
bool operator>=(const Fixed& rhs) const { return !(*this < rhs); }
bool operator!=(const Fixed& rhs) const { return !(*this == rhs); }
```

### Additional Information

#### Orthodox Canonical Form
• 필수 구성 요소
```cpp
class Orthodox {
public:
    Orthodox(void);                    // 기본 생성자
    Orthodox(const Orthodox& src);     // 복사 생성자
    ~Orthodox(void);                   // 소멸자
    Orthodox& operator=(const Orthodox& rhs);  // 대입 연산자
};
```

• 구현 패턴
```cpp
// 1. 복사 생성자
Orthodox::Orthodox(const Orthodox& src) {
    *this = src;  // 대입 연산자 활용
}

// 2. 대입 연산자
Orthodox& Orthodox::operator=(const Orthodox& rhs) {
    if (this != &rhs) {  // 자기 대입 체크
        // 깊은 복사 구현
    }
    return *this;
}
```

#### Fixed Point Numbers
• 구조와 원리
```text
32비트 정수 표현:
[31 30 29 ... 8] [7 6 5 4 3 2 1 0]
   정수부 24비트    소수부 8비트

예시: 42.42를 표현
1. 42.42 * 256(2^8) = 10859.52
2. round(10859.52) = 10860
3. 저장된 값: 10860
4. 실제 값: 10860 / 256 = 42.421875
```

• 변환 연산
```cpp
// 1. 정수 → 고정소수점
int n = 42;
int fixed = n << 8;        // 42 * 256 = 10752

// 2. 고정소수점 → 정수
int fixed = 10752;
int n = fixed >> 8;        // 10752 / 256 = 42

// 3. 부동소수점 → 고정소수점
float f = 42.42f;
int fixed = roundf(f * 256);  // round(10859.52) = 10860

// 4. 고정소수점 → 부동소수점
int fixed = 10860;
float f = fixed / 256.0f;     // 10860 / 256 = 42.421875
```

#### Operator Overloading
• 연산자 종류와 특징
```cpp
// 1. 단항 연산자
T& operator++();       // 전위 증가: ++a
T operator++(int);     // 후위 증가: a++
T operator-();         // 단항 마이너스: -a

// 2. 이항 연산자
T operator+(const T& rhs);    // a + b
T operator-(const T& rhs);    // a - b
T& operator=(const T& rhs);   // a = b

// 3. 비교 연산자
bool operator<(const T& rhs) const;   // a < b
bool operator==(const T& rhs) const;  // a == b

// 4. 입출력 연산자
friend std::ostream& operator<<(std::ostream& out, const T& obj);
```

• 구현 팁
```cpp
// 1. const 정확성
T operator+(const T& rhs) const;  // 원본 수정 없음

// 2. 반환 타입
T& operator++();     // 연쇄 호출 가능
T operator++(int);   // 임시 객체 반환

// 3. friend 함수
friend std::ostream& operator<<(std::ostream& out, const T& obj);
// 클래스 내부 접근 가능
```

### Reference
> Orthodox Canonical Form, 연산자 오버로딩, 고정소수점에 대한 심화 자료

• Orthodox Canonical Form
  - [C++ Orthodox Canonical Class Form](https://www.francescmm.com/orthodox-canonical-class-form/)
    - 정의와 필요성
    - 구현 패턴
    - 모범 사례
  
  - [Rule of Three](https://en.cppreference.com/w/cpp/language/rule_of_three)
    - 복사 생성자
    - 대입 연산자
    - 소멸자

• Operator Overloading
  - [Operator Overloading in C++](https://en.cppreference.com/w/cpp/language/operators)
    - 연산자 종류
    - 구현 규칙
    - 제약사항
  
  - [Microsoft: Operator Overloading](https://learn.microsoft.com/cpp/cpp/operator-overloading)
    - 구현 가이드라인
    - 최적화 팁
    - 실제 예제

• Fixed Point Arithmetic
  - [Fixed Point Arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
    - 개념 설명
    - 구현 방법
    - 장단점
  
  - [Fixed Point Math in C](https://spin.atomicobject.com/2012/03/15/simple-fixed-point-math/)
    - 비트 연산
    - 오버플로우 처리
    - 최적화 기법

• Binary Space Partitioning
  - [Point in Triangle Test](https://blackpawn.com/texts/pointinpoly/)
    - 알고리즘 설명
    - 구현 방법
    - 최적화
  
  - [Geometric Algorithms](https://www.cs.princeton.edu/~rs/AlgsDS07/16Geometric.pdf)
    - 기하학적 알고리즘
    - 면적 계산
    - 점 위치 판별

• 추천 도서
  - "Effective C++" by Scott Meyers
    - Item 5: Know what functions C++ silently writes and calls
    - Item 12: Copy all parts of an object
  
  - "C++ Coding Standards" by Herb Sutter
    - Item 50: Learn the canonical forms
    - Item 51: Operator overloading guidelines

• 유용한 도구
  - [Fixed Point Calculator](https://www.rfwireless-world.com/calculators/floating-point-to-fixed-point-converter.html)
    - 고정소수점 변환
    - 정밀도 계산
  
  - [C++ Shell](http://cpp.sh/)
    - 온라인 컴파일러
    - 코드 테스트