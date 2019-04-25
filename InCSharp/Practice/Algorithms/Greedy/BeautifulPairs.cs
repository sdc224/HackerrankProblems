// --------------------------------------------------------------------------------------------------------------------
// <copyright file="BeautifulPairs.cs" company="SDCWORLD">
//   Sourodeep Chatterjee
// </copyright>
// <summary>
//   Defines the FindNoOfBeautifulPairs type.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace InCSharp.Practice.Algorithms.Greedy
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    /// <summary>
    /// The beautiful pairs.
    /// </summary>
    public static class BeautifulPairs
    {
        /// <summary>
        /// The solution.
        /// </summary>
        /// <param name="args">
        /// The args.
        /// </param>
        public static void Solution(string[] args)
        {
            var n = Convert.ToInt32(Console.ReadLine());

            var a = Array.ConvertAll(
                Console.ReadLine()?.Split(' ') ?? throw new InvalidOperationException(),
                Convert.ToInt32);

            var b = Array.ConvertAll(
                Console.ReadLine()?.Split(' ') ?? throw new InvalidOperationException(),
                Convert.ToInt32);

            Array.Resize(ref a, n);
            Array.Resize(ref b, n);

            var result = FindNoOfBeautifulPairs(a, b);

            Console.WriteLine(result);
        }
        
        /// <summary>
        /// The find no of beautiful pairs.
        /// </summary>
        /// <param name="a">
        /// The a.
        /// </param>
        /// <param name="b">
        /// The b.
        /// </param>
        /// <returns>
        /// The <see cref="int"/>.
        /// </returns>
        private static int FindNoOfBeautifulPairs(IReadOnlyCollection<int> a, IEnumerable<int> b)
        {
            var noOfBeautifulPairs = 0;
            var newArray = new int[1001];

            foreach (var t in a)
            {
                newArray[t]++;
            }

            foreach (var t in b.Where(t => newArray[t] > 0))
            {
                noOfBeautifulPairs++;
                newArray[t]--;
            }

            if (noOfBeautifulPairs == a.Count)
            {
                return noOfBeautifulPairs - 1;
            }

            return noOfBeautifulPairs + 1;
        }
    }
}
