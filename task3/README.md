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

- Заголовочные файлы: 0 шт.
- Модули реализации: 5 шт. (5140 байт)
- Итого: 5 файлов (5140 байт, ~5Кб)

### Результаты тестов
```
========== RUNNING TEST tests/test_all_types_1 ==========
real    0m0.085s
user    0m0.041s
sys     0m0.010s
Result: OK
========== RUNNING TEST tests/test_all_types_2 ==========
real    0m0.083s
user    0m0.024s
sys     0m0.024s
Result: OK
========== RUNNING TEST tests/test_empty_input ==========
real    0m0.080s
user    0m0.046s
sys     0m0.000s
Result: OK
========== RUNNING TEST tests/complex_only ==========
real    0m0.085s
user    0m0.017s
sys     0m0.033s
Result: OK
========== RUNNING TEST tests/fraction_only ==========
real    0m0.080s
user    0m0.047s
sys     0m0.000s
Result: OK
========== RUNNING TEST tests/polar_only ==========
real    0m0.086s
user    0m0.050s
sys     0m0.000s
Result: OK
========== RUNNING RANDOM TEST tests/random_test_1 ==========
real    0m0.078s
user    0m0.046s
sys     0m0.000s
========== RUNNING RANDOM TEST tests/random_test_10 ==========
real    0m0.094s
user    0m0.059s
sys     0m0.000s
========== RUNNING RANDOM TEST tests/random_test_100 ==========
real    0m0.096s
user    0m0.052s
sys     0m0.010s
========== RUNNING RANDOM TEST tests/random_test_1000 ==========
real    0m0.490s
user    0m0.453s
sys     0m0.000s
========== RUNNING RANDOM TEST tests/random_test_10000 ==========
real    0m35.926s
user    0m35.870s
sys     0m0.020s
```

# Архитектура программы

**main.py**

| Переменная              | Типы         |
|-------------------------|--------------|
| argv                    | List[string] |
| container               | Container    |
| inputFileName           | string       |
| outputFileName          | string       |
| ifile                   | File         |
| numberOfElements        | int          |
| container.ReadStrArray  | method       |
| container.CreateRandom  | method       |
| output                  | File         |
| container.ToString      | method       |
| container.Size          | method       |
| container.ShakerSort    | method       |

### Container

**ReadStrArray(self, strArray)**

| Переменная              | Типы         |
|-------------------------|--------------|
| strArray                | List[string] |
| arrayLen                | int          |
| i                       | int          |
| key                     | int          |
| shape                   | Complex OR Fraction OR Polar |
| self.store              | List[Complex OR Fraction OR Polar] |

**CreateRandom(self, size)**

| Переменная              | Типы         |
|-------------------------|--------------|
| size                    | int          |
| i                       | int          |
| key                     | int          |
| shape                   | Complex OR Fraction OR Polar |
| self.store              | List[Complex OR Fraction OR Polar] |

**ToString(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| res                     | string       |
| self.store              | List[Complex OR Fraction OR Polar] |
| shape                   | Complex OR Fraction OR Polar |

**Size(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| self.store              | List[Complex OR Fraction OR Polar] |

**ShakerSort(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| left                    | int          |
| right                   | int          |
| pos                     | int          |
| isChanged               | boolean      |
| self.store              | List[Complex OR Fraction OR Polar] |
| container.ToReal        | method       |

### Complex / Fraction / Polar

**ReadStrArray(self, strArray, i)**

| Переменная              | Типы         |
|-------------------------|--------------|
| strArray                | List[string] |
| i                       | int          |
| self.re / self.num / self.r     | float / int / float |
| self.im / self.denom / self.phi | float / int / float |

**CreateRandom(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| self.re / self.num / self.r     | float / int / float |
| self.im / self.denom / self.phi | float / int / float |

**ToString(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| self.re / self.num / self.r     | float / int / float |
| self.im / self.denom / self.phi | float / int / float |

**ToReal(self)**

| Переменная              | Типы         |
|-------------------------|--------------|
| self.re / self.num / self.r | float / int / float |
| self.im / self.denom    | float / int |

# Сравнение с предыдущими реализациями

Реализация программы на динамически типизированном языке заметно проигрывает по времени исполнения другим программам (на максимальном тесте 32s вместо 0.8-1.2s!), зато выигрывает по времени написания кода: его проще писать и читать, заголовочные файлы отсутствуют, следить за типами и напрямую работать с памятью не нужно. Файлы реализации весят почти столько же, сколько код на С/C++, однако отсутствует исполняемый файл: код напрямую исполняется интерпретатором. 

Таким образом, динамическая типизация подходит для небольших задач, где не требуется высокая производительность, но нужно быстро писать код. 
