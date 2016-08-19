#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

//
// Маленький Слоник любит играть с цветными карточками.
// 
// У него есть n карточек, каждая имеет ровно два цвета(цвет на передней стороне 
// и цвет на задней стороне).Изначально все карточки лежат на столе передней стороной 
// вверх.За один шаг Маленький / Слоник /может перевернуть на другую сторону любую 
// карточку.Маленький Слоник считает набор карточек на столе веселым, если хотя бы 
// половина карточек имеет одинаковый цвет(для каждой карточки // рассматривается цвет 
// стороны, которой она лежит вверх).
// 
// Помогите Маленькому Слонику найти минимальное количество шагов необходимых для 
// превращения набора из n карточек в веселый.
// 
// Входные данные
// В первой строке задано единственное целое число n(1 ≤ n ≤ 105) — количество карточек.Следующие 
// n строк содержат описание всех карточек, по одной карточке на строку.Карточки описываются 
// парой / целых/ положительных чисел, не превосходящих 109, — цветами на обеих сторонах.Первое 
// число в строке — это цвет на передней стороне карточки, второе — на задней.Цвет 
// на передней стороне может / совпадать/ с цветом на задней.
// 
// Числа в строках разделяются единичными пробелами.
// 
// Выходные данные
// В единственной строке выведите единственное целое число — искомое минимальное 
// количество шагов.Если превратить набор в веселый невозможно, выведите - 1.
//
// http://codeforces.com/problemset/problem/204/B
//
int main()
{
    auto n = 0;
    cin >> n;
    auto const halfN = (n + 1) / 2;
    unordered_map<int, vector<int>> indices;

    for (auto i = 0; i < n; i++)
    {
        auto up = 0, down = 0;
        cin >> up >> down;

        indices[up].push_back(i + 1);

        if (up == down)
        {
            // Gain nothing with turning this card,
            // do not count.
        }
        else
        {
            indices[down].push_back((-1) * (i + 1));
        }
    }

    auto bestTurnCount = numeric_limits<int>::max();
    for (auto it: indices)
    {
        auto const currentTurnCount = halfN - count_if(it.second.begin(), it.second.end(), [](int i) { return i > 0; });
        if (currentTurnCount <= 0)
        {
            bestTurnCount = 0;
            break;
        }

        if (currentTurnCount <= count_if(it.second.begin(), it.second.end(), [](int i) { return i < 0; }) &&
            currentTurnCount < bestTurnCount)
        {
            bestTurnCount = currentTurnCount;
        }
    }

    if (bestTurnCount == numeric_limits<int>::max())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << bestTurnCount << endl;
    }
}
