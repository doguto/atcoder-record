public static class KMath
{
    public static long Gcd(long a, long b)
    {
        while (b != 0)
        {
            (a, b) = (b, a % b);
        }
        return Math.Abs(a);
    }

    public static Int128 Gcd(Int128 a, Int128 b)
    {
        while (b != 0)
        {
            (a, b) = (b, a % b);
        }

        // Math.Abs が CE になるので手で実装
        if (a < 0) return -a;
        return a;
    }
}
