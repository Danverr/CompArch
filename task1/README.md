# Отчет

Выполнил Маряхин Даниил (БПИ205)

Номер варианта: 179 \
Номер задания 1: 13 \
Номер задания 2: 11 

# Описание задачи

Необходимо создать программу, которая реализует обобщенный класс чисел и классы конкретных чисел:
1. Комплексные (действительная и мнимая части – пара действительных чисел)
2. Простые дроби (числитель, знаменатель – пара целых чисел)
3. Полярные координаты (радиус и угол – действительные числа)

Все числа должны быть приводимы к эквивалентным им действительным числам.
Например, для комплексного числа эквивалентное ему действительное - это sqrt(a^2+b^2), для полярных координат - радиус.

Программа должна принять набор чисел из файла в формате ```тип_числа_от_1_до_3 параметр_1 параметр_2 ... параметр_n```,
записать их в массив и отсортировать с помощью алгоритма Shaker Sort по убыванию их действительных значений. 
Также программа должна уметь генерировать числа случайным образом и заполнять ими контейнер.

# Характеристики

### Структура проекта

- Заголовочные файлы (.h): 6 шт. (2643 байт)
- Модули реализации (.cpp): 7 шт. (7646 байт)
- Итого: 13 файлов (10289 байт, ~10Кб)


- Размер исполняемого файла: 158 Кб

### Результаты тестов:
```
========== RUNNING TEST tests/test_all_types_1 ==========
real    0m0.008s
user    0m0.001s
sys     0m0.002s
Result: OK
========== RUNNING TEST tests/test_all_types_2 ==========
real    0m0.005s
user    0m0.001s
sys     0m0.002s
Result: OK
========== RUNNING TEST tests/test_empty_input ==========
real    0m0.004s
user    0m0.001s
sys     0m0.002s
Result: OK
========== RUNNING RANDOM TEST tests/random_test_1 ==========
real    0m0.007s
user    0m0.002s
sys     0m0.003s
========== RUNNING RANDOM TEST tests/random_test_10 ==========
real    0m0.004s
user    0m0.001s
sys     0m0.002s
========== RUNNING RANDOM TEST tests/random_test_100 ==========
real    0m0.006s
user    0m0.002s
sys     0m0.003s
========== RUNNING RANDOM TEST tests/random_test_1000 ==========
real    0m0.026s
user    0m0.015s
sys     0m0.008s
========== RUNNING RANDOM TEST tests/random_test_10000 ==========
real    0m1.203s
user    0m1.122s
sys     0m0.073s
```

# Архитектура программы

### Типы данных

| Тип данных | Размер |
|------------|--------|
| bool       | 1      |
| float      | 4      |
| int        | 4      |

```c++
struct Complex {  //   [8]
    float Re;     // 4 [0]
    float Im;     // 4 [4]
};
```

```c++
struct Fraction {     //   [8]
    int Numerator;    // 4 [0]
    int Denominator;  // 4 [4]
};
```

```c++
struct Polar {  //   [8]
    float R;    // 4 [0]
    float Phi;  // 4 [4]
};
```

```c++
struct Number {             //   [12]
    
    enum Type {             // 4 [0]
        COMPLEX,
        FRACTION,
        POLAR
    } type;
    
    union {                 
        Complex complex;    // 8 [4] 
        Fraction fraction;  // 8 [4]
        Polar polar;        // 8 [4]
    };
    
};
```

```c++
struct Container {            // [120008]
    enum {
        MAX_SIZE = 10000      // 4 [0]
    };
    int Size = 0;             // 4 [4]
    Number Numbers[MAX_SIZE]; // 120000 [8]
};
```

### Память программы

**main(int argc, char\* argv[]) [120600]**

| Переменная              | Размер       |
|-------------------------|--------------|
| int argc                | 4 [0]        |
| char* argv[]            | 8 [0, heap]  |
| Container container     | 120008 [4]   |
| std::ifstream input     | 576 [120012] |
| int size                | 4 [120588]   |
| std::ofstream output    | 568 [120592] |

**void CreateContainer(container, input) [12]**

| Переменная              | Размер       |
|-------------------------|--------------|
| int type                | 4 [0]        |
| float Re                | 4 [4]        |
| float Im                | 4 [12]       |

*Прим.: вместо Re и Im могут быть поля классов Fraction и Polar, но т.к. они имеют одинаковые размеры, пишу один раз
на примере класса Complex* 

**void CreateRandomContainer(Container &container, int size) [16]**

| Переменная              | Размер       |
|-------------------------|--------------|
| int i                   | 4 [0]        |
| int type                | 4 [4]        |
| float Re                | 4 [12]       |
| float Im                | 4 [16]       |

*Прим.: вместо Re и Im могут быть поля классов Fraction и Polar, но т.к. они имеют одинаковые размеры, пишу один раз
на примере класса Complex*

**void PrintContainer(Container &container, std::ofstream &output) [4]**

| Переменная              | Размер       |
|-------------------------|--------------|
| int i                   | 4 [0]        |

**void ShakerSort(Container &container) [13]**

| Переменная              | Размер       |
|-------------------------|--------------|
| int left                | 4 [0]        |
| int right               | 4 [4]        |
| int pos                 | 4 [8]        |
| bool isChanged          | 1 [12]       |

### Глобальные переменные

Нет