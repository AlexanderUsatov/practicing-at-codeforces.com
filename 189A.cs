using System;
using System.Linq;

//
// http://codeforces.com/problemset/problem/189/A
//   
class Program
{
    public IEnumerable<int> GetFeasibleSolutions(int l, int a, int b, int c)
    {
        for (var an = 0; an < l / a + 1; an++)
        {
            for (var bn = 0; bn < l / b + 1; bn++)
            {
                var dividend = (l - na * a - nb * b);
                if (dividend > 0)
                {
                    var cn = (dividend * 1.0) / c;
                    if (cn % 1 == 0)
                    {
                        yield return an + bn + cn;
                    }
                }
            }
            
            return 0;
        }
    }

    static void Main()
    {
        var input = "7 5 5 2".
            Split(' ').
            Select(int.Parse).
            ToArray();
        Console.WriteLine(GetFeasibleSolutions(input[0], input[1], input[2], input[3]).Max());
    }
}