using System;
using System.Linq;

//
// http://codeforces.com/problemset/problem/616/B
//
class Program
{
    static void Main()
    {
        var nm = Console.
            ReadLine().
            Split(' ').
            Select(int.Parse).
            ToArray();
        var n = nm[0];
        var m = nm[1];
        var a = new int[n][];

        for (var i = 0; i < n; i++)
        {
            a[i] = Console.
                ReadLine().
                Split(' ').
                Select(int.Parse).
                ToArray();
        }

        Console.WriteLine(a.Select(row => row.Min()).Max());
    }
}