/* Name: Minjie Shen
 * NetID: ms10733
 *
 * Question #1 :
 * - Base Case: we first need to prove that P(2), since for any positive integer greater than or equal to 2,
 * the inequality exist.
 * When n = 2,
 *            3^n = 3^2 =9
 *            2^n + n^2 = 2^2 + 2^2 = 8
 *            since 9 > 8, so 3^n > 2^n + n^2 is true when n = 2, P(2) is true.
 *
 * - Inductive step: For any positive integer greater than or equal to 2, we assume that there is a positive integer k,
 * where any integer in the range between 2 to k will satisfy 3^n > 2^n + n^2, then we need to prove that 3^n > 2^n + n^2
 * is also true for n = k + 1, which is 3^(k+1) > 2^(k+1) + (k+1)^2.
 * we have 3^k > 2^k + k^2
 *
 * 3^(k+1) = 3 * 3^k > 2 *(2^k + (k)^2)      //(since k >= 2, 3 * 3^k > 3^k, and 3^k > 2^k + k^2)
 *                   = 2*2^k + 2*(k)^2
 *                   = 2^(k+1) + 2*(k)^2
 *                   = 2^(k+1) + k^2 + k^2   //(since k >= 2, k^2 >= 2k +1)
 *                  >= 2^(k+1) + k^2 + 2k + 1
 *                  = 2^(k+1) + (k+1)^2
 *
 * Thus, 3^(k+1) > 2^(k+1) + (k+1)^2 is true for k >= 2.
 *
 *
 * Question #2:
 * Since there are only even digits in the first three place, and the even digits in the range 1 - 9 are 2, 4, 6, 8.
 * There are 4 even numbers in the range and 5 odd numbers. In the first place, we have 4 choices; in the second place,
 * we have 3 choices (since the first place has already chosen an even digit); in the third place, we have 2 choices.
 * Then in the rest places, we can choose from the rest 6 digits that has not been chosen.
 *
 * So, it is (4 * 3 * 2) * (6 * 5 * 4 * 3 * 2 * 1) = 17280
 *
 *
 * Question #3:
 * a)  X = 0, P(x = 0) = 1 / 2^5 = 0.0313
 *     X = 1, P(x = 1) = 5 / 2^5 = 0.1563
 *     X = 2, P(x = 2) = 10 / 2^5 = 0.3125
 *     X = 3, P(x = 3) = 10 /2^5 = 0.3125
 *     X = 4, P(x = 4) = 5 /2^5 = 0.1563
 *     X = 5, P(x = 5) = 1/ 2^5 = 0.0313
 *So the distribution of X: {(0, 0.0313), (1, 0.1563), (2, 0.3125), (3, 0.3125), (4,0.1563), (5, 0.0313)}
 *
 * b) E(X) = 0 * 1 / 2^5 + 1 * 5 / 2^5 + 2 * 10 / 2^5 + 3 * 10 / 2^5 + 4 * 5 /2^5 + 5 * 1/ 2^5
 *         = 2.5
 *
 *
 * Question #4:
 *
 * func1)
 * First we can ignore the operations outside of the two for-loop, since their operation time is always constant Theta(1).
 * Then we can also ignore the operations within the two for-loop, since their operation time is also constant Theta(1)
 * Now, we analyze the first for-loop.
 * In the first for-loop, we give value to each element of the array and the array becomes: 1, 2, 3, 4 ... n.
 * the time complexity of the first for-loop is T(n)
 * Then we analyze the second for-loop.
 * when i = 0, we count 1 times; when i = 1, we count 2 times; when i = n - 1, we count n times.
 * so the operations here is (1 + 2 + 3 + ... + n) = (1 + n) * n / 2 = (n + n^2) /2
 *
 * The total time is (n + n^2) /2 + n + c (c is a constant)
 * So the time complexity is Theta(n^2)
 *
 * Func2)
 * First we can ignore the operations outside of the two for-loop, since their operation time is always constant Theta(1).
 * Then we can also ignore the operations within the two for-loop, since their operation time is also constant Theta(1)
 * Now, we analyze the first for-loop.
 * In the first for-loop, we give value to each element of the array and the array becomes: 1, 2, 4, 8 ... 2^n.
 * the time complexity of the first for-loop is T(n)
 * Then we analyze the second for-loop.
 * when i = 0, we count 1 times; when i = 1, we count 2 times; when i = n - 1, we count 2^n times.
 * so the operations here is (1 + 2 + 4 + ... + 2^n) = (2^(n+1) + n) / 2
 *
 * The total time is (2^(n+1) + n) / 2 + n + c (c is a constant)
 * So the time complexity is Theta(2^n).
 *
 *
 *
 */
