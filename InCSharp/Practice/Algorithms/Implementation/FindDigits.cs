// --------------------------------------------------------------------------------------------------------------------
// <copyright file="FindDigits.cs" company="SDCWORLD">
//   Sourodeep Chatterjee
// </copyright>
// <summary>
//   Defines the FindDigits type.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace InCSharp.Practice.Algorithms.Implementation
{
    using System;

    /// <summary>
    /// The find digits.
    /// </summary>
    public class FindDigits
    {
        /// <summary>
        /// The solution.
        /// </summary>
        /// <param name="args">
        /// The args.
        /// </param>
        public static void Solution(string[] args)
        {
            var testCases = Convert.ToInt32(Console.ReadLine());

            for (var i = 0; i < testCases; i++)
            {
                var n = Convert.ToInt32(Console.ReadLine());

                var result = FindNoOfDivisorDigits(n);

                Console.WriteLine(result);
            }
        }

        /// <summary>
        /// The find no of divisor digits.
        /// </summary>
        /// <param name="n">
        /// The n.
        /// </param>
        /// <returns>
        /// The <see cref="int"/>.
        /// </returns>
        private static int FindNoOfDivisorDigits(int n)
        {
            var copyOfN = n;
            var noOfDivisors = 0;

            while (n != 0)
            {
                var remainder = n % 10;

                n /= 10;

                if (remainder == 0)
                {
                    continue;
                }

                if (copyOfN % remainder == 0)
                {
                    noOfDivisors++;
                }
            }

            return noOfDivisors;
        }
    }
}
