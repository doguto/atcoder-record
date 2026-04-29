using System.Runtime.CompilerServices;
using System.Text;

var fs = new FastScanner();
var fw = new FastWriter();

// 1. 生徒の分類
// 2. 各組の R番までの点数の累積
// 3. L,Rの累積値の検索

// i. 
// - SortedDictionary で各組毎に生徒の点数データを作成
// - 作成後、 SortedDictionary で累積値データへと変換
// - SortedDictionaryなので、O(logN)で検索可能

// Start
var N = fs.Int();
var klasses = new int[2, N];
int[] currentSum = {0, 0};

for (int i = 0; i < N; i++)
{
    var klass = fs.Int();
    var score = fs.Int();

    currentSum[klass - 1] += score;
    for (int j = 0; j < 2; j++)
    {
        klasses[j, i] = currentSum[j];
        // fw.SetLine($"   {i}: CurrentSum[{j}]: {currentSum[j]}");
    }
}

// fw.SetLine("");

var Q = fs.Int();
for (int i = 0; i < Q; i++)
{
    var L = fs.Int();
    var R = fs.Int();

    int min = L >= 2 ? klasses[0, L - 2] : 0;
    fw.Set(klasses[0, R - 1] - min);
    fw.Set(" ");
    min = L >= 2 ? klasses[1, L - 2] : 0;
    fw.Set(klasses[1, R - 1] - min);
    fw.SetLine("");
}

// End

fw.Confirm();


//
// Utility
//

class FastScanner
{
    private readonly Stream _stream;
    private readonly byte[] _buffer = new byte[1024];
    private int _ptr = 0;
    private int _buflen = 0;

    public FastScanner() { _stream = Console.OpenStandardInput(); }

    private bool HasNextByte()
    {
        if (_ptr < _buflen) return true;
        _ptr = 0;
        _buflen = _stream.Read(_buffer, 0, _buffer.Length);
        return _buflen > 0;
    }

    private byte ReadByte() => HasNextByte() ? _buffer[_ptr++] : (byte)0;

    private static bool IsPrintableChar(int c) => 33 <= c && c <= 126;

    private void SkipUnprintable()
    {
        while (HasNextByte() && !IsPrintableChar(_buffer[_ptr])) _ptr++;
    }

    public string Str()
    {
        SkipUnprintable();
        var sb = new StringBuilder();
        while (HasNextByte() && IsPrintableChar(_buffer[_ptr]))
        {
            sb.Append((char)ReadByte());
        }
        return sb.ToString();
    }

    public int Int()
    {
        long n = Long();
        if (n < int.MinValue || n > int.MaxValue) throw new OverflowException();
        return (int)n;
    }

    public long Long()
    {
        SkipUnprintable();
        long n = 0;
        bool minus = false;
        byte b = ReadByte();
        if (b == '-') { minus = true; b = ReadByte(); }
        if (b < '0' || '9' < b) throw new FormatException();
        while (true)
        {
            if ('0' <= b && b <= '9') { n *= 10; n += b - '0'; }
            else if (b == (byte)0 || !IsPrintableChar(b)) return minus ? -n : n;
            else throw new FormatException();
            b = ReadByte();
        }
    }

    public Int128 LongLong()
    {
        SkipUnprintable();
        Int128 n = 0;
        bool minus = false;
        byte b = ReadByte();
        if (b == '-') { minus = true; b = ReadByte(); }
        if (b < '0' || '9' < b) throw new FormatException();
        while (true)
        {
            if ('0' <= b && b <= '9') { n *= 10; n += b - '0'; }
            else if (b == (byte)0 || !IsPrintableChar(b)) return minus ? -n : n;
            else throw new FormatException();
            b = ReadByte();
        }
    }

    public double Double() => double.Parse(Str());
    public int[] IntArr(int n) { var a = new int[n]; for (int i = 0; i < n; i++) a[i] = Int(); return a; }
    public long[] LongArr(int n) { var a = new long[n]; for (int i = 0; i < n; i++) a[i] = Long(); return a; }
    public Int128[] LongLongArr(int n) { var a = new Int128[n]; for (int i = 0; i < n; i++) a[i] = LongLong(); return a; }
}

class FastWriter
{
    readonly StreamWriter sw;

    public FastWriter()
    {
        sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
        Console.SetOut(sw);
    }

    public void Set(string s)
    {
        Console.Write(s);
    }

    public void Set(long n)
    {
        Console.Write(n);
    }

    public void Set(Int128 n)
    {
        Console.Write(n);
    }

    public void SetLine(string s)
    {
        Console.WriteLine(s);
    }

    public void SetLine(long n)
    {
        Console.WriteLine(n);
    }

    public void SetLine(Int128 n)
    {
        Console.WriteLine(n);
    }

    public void Confirm()
    {
        Console.Out.Flush();
    }
}

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
