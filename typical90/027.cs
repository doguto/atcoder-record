using System.Text;

// N <= 10^5 なので、 O(N logN) まで

var fs = new FastScanner();
var fw = new FastWriter();

var N = fs.Int();

var map = new SortedSet<string>();

for (int i = 0; i < N; i++)
{
    var s = fs.Str();
    if (map.Contains(s)) continue;

    map.Add(s);
    fw.SetLine(i + 1);
}

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

    public double Double() => double.Parse(Str());
    public int[] IntArr(int n) { var a = new int[n]; for (int i = 0; i < n; i++) a[i] = Int(); return a; }
    public long[] LongArr(int n) { var a = new long[n]; for (int i = 0; i < n; i++) a[i] = Long(); return a; }
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

    public void Set(int n)
    {
        Console.Write(n);
    }

    public void SetLine(string s)
    {
        Console.WriteLine(s);
    }

    public void SetLine(int n)
    {
        Console.WriteLine(n);
    }

    public void Confirm()
    {
        Console.Out.Flush();
    }
}
