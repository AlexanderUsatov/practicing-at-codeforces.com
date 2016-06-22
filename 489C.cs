using System;
using System.Linq;

//
// http://codeforces.com/problemset/problem/489/C
//
class Program
{
    static string GetMinNumberAsString(int m, int s)
    {
        var min = Enumerable.
            Range(0, m).
            Select(_ => '0').
            ToArray();

        var n = s != 0 ? Math.Max(1, s - (m - 1) * 9) : 0;
        min[0] = n.ToString()[0];
        s -= n;
        m--;

        while (s > 0 && m != 0)
        {
            n = Math.Max(0, s - (m - 1) * 9);
            min[min.Length - m] = n.ToString()[0];
            s -= n;
            m--;
        }

        return new string(min);
    }

    static string GetMaxNumberAsString(int m, int s)
    {
        var max = Enumerable.
            Range(0, m).
            Select(_ => '0').
            ToArray();
        var n = 0;
        do
        {
            s -= n;
            n = Math.Min(9, s);
            max[max.Length - m] = n.ToString()[0];
            m--;
        }
        while (s > 0 && m != 0);

        return new string(max);
    }

    static void Main()
    {
        var input = Console.
            ReadLine().
            Split(' ').
            Select(int.Parse).
            ToArray();
        var m = input[0];
        var s = input[1];
        var max = Enumerable.
            Range(0, m).
            Select(_ => '0').
            ToArray();

        if ((m > 1 && s == 0) ||
            m * 9 < s)
        {
            Console.WriteLine("-1 -1");
            return;
        }

        Console.WriteLine("{0} {1}", GetMinNumberAsString(m, s), GetMaxNumberAsString(m, s));
    }
}