using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace InCSharp
{
    internal class Program
    {
        public static void PrintAllCombinations()
        {
            foreach (var combination in AllCombinations(new[] { "AB", "CD" }))
            {
                Console.WriteLine(combination);
            }
        }

        private static string[] AllCombinations(string[] values)
        {
            return AllCombinationsRecursive(values, 0, values.Length - 1);
        }

        private static string[] AllCombinationsRecursive(string[] values, int i, int n)
        {
            var result = new List<string>();
            //var enumerable = values as string[] ?? values.ToArray();
            if (i == n)
            {
                var combinedString = new StringBuilder();
                foreach (var value in values)
                {
                    var res = Convert.ToChar(value);
                    combinedString.Append(value);
                }

                result.Add(combinedString.ToString());
            }

            for (var j = i; j <= n; j++)
            {
                values = Swap(values, i, j);
                var enumerable1 = values as string[] ?? values.ToArray();
                result.AddRange(AllCombinationsRecursive(enumerable1, i + 1, n));
                values = Swap(values, i, j); // backtrack
            }

            return result.ToArray();
        }

        private static string[] Swap(string[] values, int i, int j)
        {
            var enumerable = values as string[] ?? values.ToArray();
            var tmp = enumerable[i];
            enumerable[i] = enumerable[j];
            enumerable[j] = tmp;
            return (string[])values;
        }

        static void Main(string[] args)
        {
            //PrintAllCombinations();
            var a = "ab";
            var b = "ba";
            var ab = a + b;
            var c = ab.ToCharArray();
            //Console.WriteLine(ab);
            /*var c = new StringBuilder();

            foreach (var letter1 in a)
            {
                foreach (var letter2 in b)
                {
                    if (!letter1.Equals(letter2))
                    {
                        c.Append(letter1);
                        c.Append(letter2);
                        c.Append("\n");
                    }
                }
            }*/

            //Combine(ab);

            //var list = new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            //Console.WriteLine(SubsetSum(list, 30));

            //Console.WriteLine(c);
            PrintSubsets(c);
        }

        // Print all subsets of given set[] 
        private static void PrintSubsets(char[] set)
        {
            var n = set.Length;

            var result = new char[n];

            // Run a loop for printing all 2^n 
            // subsets one by obe 
            for (var i = 0; i < 1 << n; i++)
            {
                // Print current subset 
                for (var j = 0; j < n; j++)
                    if ((i & (1 << j)) > 0)
                        result.Append(set[j]);

                
            }
            Console.WriteLine(result);
        }

        public static void Combine(string ab)
        {
            Combine(0, ab);
        }

        private static void Combine(int start, string ab)
        {
            var output = new StringBuilder();

            for (var i = start; i < ab.Length; ++i)
            {
                output.Append(ab[i]);
                Console.WriteLine(output);
                if (i < ab.Length)
                    Combine(i + 1, ab);
                output.ToString().SetLength(output.Length - 1);
            }
        }

        public static bool SubsetSum(IEnumerable<int> list, int s)
        {
            var arr = list.ToArray();
            Array.Sort(arr);
            var a = arr.Where(i => i < 0).Sum();
            var b = arr.Where(i => i > 0).Sum();
            if (a > s || b < s)
            {
                return false;
            }
            var dp = new bool[arr.Length + 1, s + 1];
            for (var i = 0; i <= s; i++)
            {
                dp[0, i] = false;
            }
            for (var j = 1; j <= s; j++)
            {
                for (var i = 1; i <= arr.Length; i++)
                {
                    dp[i, j] = (arr[i - 1] == j) || dp[i - 1, j] ||
                               ((j - arr[i - 1] >= arr.Take(i).Where(number => number < 0).Sum())
                                && (j - arr[i - 1] <= arr.Take(i).Where(number => number > 0).Sum())
                                && dp[i - 1, j - arr[i - 1]]);
                }
            }
            return dp[arr.Length, s];
        }
    }

    public static class StringExtensions
    {
        /// <summary>
        /// Method that limits the length of text to a defined length.
        /// </summary>
        /// <param name="source">The source text.</param>
        /// <param name="maxLength">The maximum limit of the string to return.</param>
        public static string SetLength(this string source, int maxLength)
        {
            if (source.Length <= maxLength)
            {
                return source;
            }

            return source.Substring(0, maxLength);
        }
    }
}