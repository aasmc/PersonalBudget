# Личный бюджет

Система ведения личного бюджета. Обрабатывает запросы следующих типов:

- ComputeIncome from to: вычислить чистую прибыль за данный диапазон дат. Чистая прибыль вычисляется как разница заработанного (за вычетом налогов) и потраченного. При расчёте налога потраченные суммы не учитываются.
- Earn from to value: учесть, что за указанный период (равномерно по дням) была заработана сумма value.
- PayTax from to percentage: заплатить налог percentage в каждый день указанного диапазона. Это означает простое умножение всей прибыли в диапазоне на 1 - percentage / 100, независимо от того, отдавался ли уже налог за какой-то из указанных дней. Прибыль за эти дни, которая обнаружится позже, налогами из прошлого не облагается.
- Spend from to value: потратить указанную сумму равномерно за указанный диапазон дат.

### Примечания:

- Во всех диапазонах from to обе даты from и to включаются.

### Формат ввода

В первой строке вводится количество запросов Q, затем в описанном выше формате вводятся сами запросы, по одному на строке.

### Формат вывода

Для каждого запроса ComputeIncome в отдельной строке в стандартный поток вывода выводится вещественное число — чистую прибыль (прибыль за вычетом налогов) за указанный диапазон дат.

## Пример

### Ввод

```text
8
Earn 2000-01-02 2000-01-06 20
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-01-02 2000-01-03 13
ComputeIncome 2000-01-01 2001-01-01
Spend 2000-12-30 2001-01-02 14
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-12-30 2000-12-30 13
ComputeIncome 2000-01-01 2001-01-01
```

### Вывод

```text
20
18.96
8.46
8.46
```
